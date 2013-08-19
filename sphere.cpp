#include "sphere.h"

sphere::sphere(void){
			this->centre.x=0;
			this->centre.y=0;
			this->centre.z=0;
			this->radius=1;
		}	 

sphere::sphere(vertex c, GLfloat r){
			this->centre=c;
			radius=r;
		}	 

sphere::sphere(GLfloat a,GLfloat b,GLfloat c, GLfloat r){
			this->centre.x=a;
			this->centre.y=b;
			this->centre.z=c;
			radius=r;
		}
bool sphere::isHit(ray r){

	GLfloat a=dot(r.direction,r.direction);
	GLfloat b=dot(diff(r.start,this->centre),r.direction);
	GLfloat c=dot(diff(r.start,this->centre),diff(r.start,this->centre))-pow(this->radius,2);
	GLfloat disc=(pow(b,2))-(a*c);				//discriminant

	if (disc<0.01){
		return false;
	}
	else {
		return true;
	}
}