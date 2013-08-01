
#ifndef __RAY__
#define __RAY__

	#include <GL/freeglut.h>
	#include "geometry.h"

	class ray{
		public :
			vertex start;
			vertex direction;
			GLfloat tMax,tMin;

			ray(void);
			ray(GLfloat a,GLfloat b,GLfloat c,GLfloat dx,GLfloat dy,GLfloat dz);
			ray(vertex a,vertex b );
		};

#endif
