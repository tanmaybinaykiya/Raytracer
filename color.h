#ifndef __COLOR__
#define __COLOR__

#include<GL/freeglut.h>

class color{
		public :
		GLfloat r,g,b;

		color(void);
		color operator+(const color& other);		
		color(GLfloat R, GLfloat G,GLfloat B);
	};
#endif
