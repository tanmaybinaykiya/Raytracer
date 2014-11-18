#include "sphere.h"

sphere::sphere(void){
			this->centre.x=0;
			this->centre.y=0;
			this->centre.z=0;
			this->radius=1;
			this->colour=color(0,0,0);
		}	 

sphere::sphere(vertex c, GLfloat r, color col){
			this->centre=c;
			this->radius=r;
			this->colour=col;
		}	 

sphere::sphere(GLfloat a,GLfloat b,GLfloat c, GLfloat r, color col){
			this->centre.x=a;
			this->centre.y=b;
			this->centre.z=c;
			this->radius=r;
			this->colour=col;
		}
bool sphere::isHit(ray r, GLfloat *t){

	GLfloat a=dot(r.direction,r.direction);
	GLfloat b=dot(diff(r.start,this->centre),r.direction);
	GLfloat c=dot(diff(r.start,this->centre),diff(r.start,this->centre))-pow(this->radius,2);
	GLfloat disc=(pow(b,2))-(a*c);						//discriminant
	GLfloat t1=-b + sqrt(disc);
			t1/=a;
	GLfloat t2=-b - sqrt(disc);
			t2/=a;
	
	if ((t1 > 0.1f)&&(t1<*t)){
        *t = t1;
        return true; 
    } 
    else if ((t2 > 0.1f)&&(t2<*t)){
        *t = t2; 
        return true; 
    }
	else{
		return false;
	}

}

vertex sphere::getDirection(ray incidentRay,vertex start){
	//reflectedRay=(2x(incidentRay.normal)/(normal.normal))-V;
	vertex normal= vertex(start.x-this->centre.x,start.y-this->centre.y,start.z-this->centre.z);
	GLfloat a=dot(incidentRay.direction,normal);
	GLfloat b=dot(normal,normal);
	GLfloat c=2*a/b;
	vertex reflectedRay=vertex(c*normal.x,c*normal.y,c*normal.z);
	return diff(reflectedRay,incidentRay.direction);
}