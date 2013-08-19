
#ifndef __RAY__
#define __RAY__

	#include <GL/freeglut.h>
	#include "winged.h"

	class ray{
		public :
			vertex start;
			vertex direction;
			GLfloat tMax,tMin;

			ray(void);
			ray(GLfloat a,GLfloat b,GLfloat c,GLfloat dx,GLfloat dy,GLfloat dz);
			ray(vertex a,vertex b );
		};
	GLfloat dot(vertex a,vertex b);
	vertex cross(vertex a,vertex b);

#endif
