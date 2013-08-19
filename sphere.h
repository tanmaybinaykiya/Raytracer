#ifndef __SPHERE__
#define __SPHERE__

	#include <GL/freeglut.h>
	#include "winged.h"
	#include "ray.h"
	
	class sphere{
		public :
			vertex centre;
			GLfloat radius;

		sphere(void); 
		sphere(vertex c, GLfloat r);
		sphere(float a,float b,float c, float r);
		bool isHit(ray r);
	};
	
#endif