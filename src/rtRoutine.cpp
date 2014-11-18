#include "header.h"

void initializeScene(void){
	GLfloat w,h,d;
	scene *myScene=scene::getInstance();
#ifdef _input_
	std::cout<<"Enter the width(pixels) of viewing plane :\t\n";
	std::cin>>w;
	std::cout<<"Enter the height(pixels) of viewing plane :\t \n";
	std::cin>> h;
	std::cout<<"Enter the distance of viewing plane from origin : \t \n";
	std::cin>>d;
	if (d<=5){
		std::cout<<"eye in front of viewing plane, nothing is visible\n Program exiting";
		exit(0);
	}
#else
	w=3,h=3,d=-5;
#endif

	myScene->editScene(vertex(0.0,0.0,-10.0),vertex(-w/2,h/2,d),vertex(w/2,h/2,d),vertex(w/2,-h/2,d),vertex(-w/2,-h/2,d),screenW,screenH);
	std::vector <std::vector<color> > temp (2*myScene->windowHeight, std::vector<color>(2*myScene->windowWidth));
	myScene->buffer=temp;
	myScene->backgroundColor=color(0,0,0);
	myScene->depth=MAX_RAYTRACING_DEPTH;
}

void initializeGeometry(){
	input();
}

void initRT(void ){
	scene *myScene=scene::getInstance();
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-myScene->planeV1.x/2,myScene->planeV1.x/2,-myScene->planeV1.y/2,myScene->planeV1.y/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor((GLclampf)0.2,(GLclampf)0.2,(GLclampf)0.2,(GLclampf)1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

color isHit(ray r,int depth){
	//isHit calls itself DEPTH times 

	geometry *myGeometry=geometry::getInstance();
	scene *myScene=scene::getInstance();
	GLuint i=0,sphereNum=0,faceNum=0;
	sphereNum=myGeometry->spheres.size();
	GLfloat  t = 100000.0,t2=10000;

	for(i=0;i<sphereNum;i++){//for every sphere

		if(myGeometry->spheres[i].isHit(r, &t)){
			// if the ray hits a sphere
			// at #intersection pt 't', find the #dot() product  with the #direction vector of the light.

			GLuint j;
			vertex intersection =vertex(myScene->eye.x+t*r.direction.x,myScene->eye.y+t*r.direction.y,myScene->eye.z+t*r.direction.z);
			vertex normal=vertex(myGeometry->spheres[i].centre.x-intersection.x,myGeometry->spheres[i].centre.y-intersection.y,myGeometry->spheres[i].centre.z-intersection.z);

			for(j=0;j<myGeometry->lights.size();j++){	//for every light, check if the light illuminates this part of the object
				vertex toLight=myGeometry->lights[j].location;
				GLfloat index=dot(normal,toLight);
				color col;
				if(index<=0.01){
					//SPHERE ON THE OPPOSITE SIDE OF LIGHT
					continue;
				}
				else{
					//light illuminates this part of the object
					ray shadowRay=ray(intersection,myGeometry->lights[j].location);
					GLuint k;

					//col=color(1,1,1);
					for(k=0;k<sphereNum;k++){
						if(myGeometry->spheres[k].isHit(shadowRay, &t2)){
							// check if the point lies in the shadow region of another object
							if(k!=i){
								return color(0,0,0);
							}
						}
					}
					col.r=(GLfloat)LAMBERT_COEFFICIENT*index*myGeometry->lights[j].colour.r;
					col.g=(GLfloat)LAMBERT_COEFFICIENT*index*myGeometry->lights[j].colour.g;
					col.b=(GLfloat)LAMBERT_COEFFICIENT*index*myGeometry->lights[j].colour.b;
					return col;
				}
			}	
		}
	}

	for(i=0;i<faceNum;i++){		
		if(myGeometry->faces[i].isHit(r, &t)){
			//return shade(r,FACE,i);
		}
	}

	return color(0,0,0);
}


void raytrace(void){
	// for every pixel shoot a ray and intersect with the objects and return white (if hit) (else) black									DONE
	// for every pixel shoot a ray and intersect with the objects and calculate normals and evrything and return color using coefficients if hit else black
	scene *myScene=scene::getInstance();
	//std::cout<<"TRACE BEGINS \n";
	GLfloat i=0,j=0;
	GLfloat dx=1,dy=1,z=-myScene->planeV1.z,l,r,b,t;
	const GLint sampleX=2*myScene->windowWidth;
	const GLint sampleY=2*myScene->windowHeight;
	glColor3f(0,0,0);
	l=myScene->planeV1.x;
	r=myScene->planeV2.x;
	b=myScene->planeV3.y;
	t=myScene->planeV2.y;
	dx=(r-l)/sampleX;
	dy=(t-b)/sampleY;

	for(i=0;i<sampleX;i+=1){
		for(j=0;j<sampleY;j+=1){
			color c=isHit(ray(myScene->eye,vertex((i*dx)+l,(j*dy)+b,z)),myScene->depth);
			myScene->buffer[i][j]=c;
		}
	}

	///ORIGINAL WITHOUT TRANSFORMATIONS FOR BUFFER///

	/*
	for(i=l;i<r;i+=dx){
	for(j=b;j<t;j+=dy){
	color c=isHit(ray(myScene->eye,vertex(i,j,z)));

	glColor3f(c.r,c.g,c.b);
	//glColor3f(1,1,1);

	glBegin(GL_POINTS);
	glVertex2f(i,j);
	glEnd();
	}
	}
	*/
	//std::cout<<"TRACE DONE\n";	
}

color shade(ray r,int intersectionType,int i){
	if (intersectionType == SPHERE){

	}
	else if(intersectionType == FACE){

	}
	else if(intersectionType==SPHERE + FACE){

	}
	return color(1,1,0);
}

void drawGeometryRT(){
	scene *myScene=scene::getInstance();
	//std::cout<<"DRAW STARTS\n";	

	int i=0,j=0;
	GLfloat dx=1,dy=1,z=-myScene->planeV1.z,l,r,b,t;
	const int sampleX=2*myScene->windowWidth;
	const int sampleY=2*myScene->windowHeight;
	glColor3f(1,1,1);
	l=myScene->planeV1.x;
	r=myScene->planeV2.x;
	b=myScene->planeV3.y;
	t=myScene->planeV2.y;
	dx=(r-l)/sampleX;
	dy=(t-b)/sampleY;

	for(i=-1+2*myScene->windowWidth;i>=0;i-=1){
		for(j=0;j<2*myScene->windowHeight;j+=1){
			color c=myScene->buffer[i][j];
			glColor3f(c.r,c.g,c.b);
			glBegin(GL_POINTS);
			glVertex2f(((-1+2*myScene->windowWidth-i)*dx)+l,(j*dy)+b);
			glEnd();
		}
	}
	//std::cout<<"DRAW COMPLETE\n";
}

void rtRoutine(void){
	initRT();
	noLight();
	//raytrace();
	drawGeometryRT();
}

GLfloat max(GLfloat a,GLfloat b){
	if (a>b) return a;
	else return b;

}

void noLight (void){
	/* Enable a single OpenGL light. */
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

	/* Use depth buffering for hidden surface elimination. */
	glDisable(GL_DEPTH_TEST);
}