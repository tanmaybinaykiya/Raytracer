#ifndef __SPHERE__
#define __SPHERE__

	#include <GL/freeglut.h>
	#include "winged.h"
	#include "ray.h"
	#include "color.h"
	
	class sphere{
		public :
			vertex centre;
			GLfloat radius;
			color colour;
			sphere(void);
			sphere(vertex , GLfloat ,color );
			sphere(float ,float ,float , float , color );

			bool isHit(ray r, GLfloat *t);
			vertex getDirection(ray r,vertex start);
	};
	
#endif