#include"sphere.h"

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
