#include "header.h"

std::vector <std::vector<color> >  initializeScene(void){
	GLfloat w,h,d;

	#ifdef _input_
		std::cout<<"Enter the width(pixels) of viewing plane :\t\n";
		std::cin>>w;
		std::cout<<"Enter the height(pixels) of viewing plane :\t \n";
		std::cin>> h;
		std::cout<<"Enter the distance of viewing plane from origin : \t \n";
		std::cin>>d;
		if (d<=eye.z){
			std::cout<<"eye in front of viewing plane, nothing is visible\n Program exiting";
			exit(0);
		}
	#else
		w=3,h=3,d=-5;
	#endif
		myScene=scene(vertex(0.0,0.0,-10.0),vertex(-w/2,h/2,d),vertex(w/2,h/2,d),vertex(w/2,-h/2,d),vertex(-w/2,-h/2,d),screenW,screenH);
		std::vector <std::vector<color> > buffer (2*myScene.windowHeight, std::vector<color>(2*myScene.windowWidth));
		int i=0;
		return buffer;
}

void initializeGeometry(){
	

}

void initRT(void ){
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-myScene.planeV1.x/2,myScene.planeV1.x/2,-myScene.planeV1.y/2,myScene.planeV1.y/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor((GLclampf)0.2,(GLclampf)0.2,(GLclampf)0.2,(GLclampf)1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

color isHit(ray r){
	sphere mySphere[2];
	mySphere[0]=sphere(vertex(0,0,0),.5);
	mySphere[1]=sphere(vertex(1,1,5),.5);
	int i=0;
	bool v=false;

	for(i=0;i<2;i++){
		v=v||isHitSphere(r,mySphere[i]);
	}
	if(true==v){
		return shade(r);
	}
	else return color(0,0,0);
}

bool isHitQuad(ray r){
	
	int numfaces=faces.size();
	int	i=0;
	//for (i=0,i<numfaces;i++){
	//	i=i;
	//}		
	return false;
}

bool isHitSphere(ray r,sphere s){

	GLfloat a=dot(r.direction,r.direction);
	GLfloat b=dot(diff(r.start,s.centre),r.direction);
	GLfloat c=dot(diff(r.start,s.centre),diff(r.start,s.centre))-pow(s.radius,2);
	GLfloat disc=(pow(b,2))-(a*c);				//discriminant

	if (disc<0.01){
		return false;
	}
	else {
		return true;
	}
}

void raytrace(void){
	// for every pixel shoot a ray and intersect with the objects and return white if hit else black										DONE
	// NEXT STEP for every pixel shoot a ray and intersect with the objects and return color if hit else black								DONE
	// NEXT STEP for every pixel shoot a ray and intersect with the objects and calculate normals and evrything and return color using coefficients if hit else black
	std::cout<<"TRACE BEGINS \n";
	GLfloat i=0,j=0;
	GLfloat dx=1,dy=1,z=-myScene.planeV1.z,l,r,b,t;
	const int sampleX=2*myScene.windowWidth;
	const int sampleY=2*myScene.windowHeight;
	glColor3f(0,0,0);
	l=myScene.planeV1.x;
	r=myScene.planeV2.x;
	b=myScene.planeV3.y;
	t=myScene.planeV2.y;
	dx=(r-l)/sampleX;
	dy=(t-b)/sampleY;

	for(i=0;i<2*myScene.windowHeight;i+=1){
		for(j=0;j<2*myScene.windowWidth;j+=1){
			color c=isHit(ray(myScene.eye,vertex((i*dx)+l,(j*dy)+b,z)));
			glColor3f(c.r,c.g,c.b);
			buffer[i][j]=c;
		}
	}

///ORIGINAL WITHOUT TRANSFORMATIONS FOR BUFFER///

/*
	for(i=l;i<r;i+=dx){
		for(j=b;j<t;j+=dy){
			color c=isHit(ray(myScene.eye,vertex(i,j,z)));
			
			glColor3f(c.r,c.g,c.b);
			//glColor3f(1,1,1);

			glBegin(GL_POINTS);
				glVertex2f(i,j);
			glEnd();
		}
	}
*/
	std::cout<<"TRACE DONE\n";	
}

color shade(ray r){
	return color(1,1,1);
}

void drawGeometryRT(){
	std::cout<<"DRAW STARTS\n";	

	int i=0,j=0;
	GLfloat dx=1,dy=1,z=-myScene.planeV1.z,l,r,b,t;
	const int sampleX=2*myScene.windowWidth;
	const int sampleY=2*myScene.windowHeight;
	glColor3f(1,1,1);
	l=myScene.planeV1.x;
	r=myScene.planeV2.x;
	b=myScene.planeV3.y;
	t=myScene.planeV2.y;
	dx=(r-l)/sampleX;
	dy=(t-b)/sampleY;

	for(i=0;i<2*myScene.windowHeight;i+=1){
		for(j=0;j<2*myScene.windowWidth;j+=1){
				color c=buffer[i][j];
				glColor3f(c.r,c.g,c.b);
				glBegin(GL_POINTS);
					glVertex2f((i*dx)+l,(j*dy)+b);
				glEnd();
		}
	}
	std::cout<<"DRAW COMPLETE\n";
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