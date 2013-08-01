#ifndef __SCENE__
#define __SCENE__

#include "geometry.h"

class scene{
	public :
		vertex eye;
		vertex planeV1,planeV2,planeV3,planeV4;
		int windowWidth, windowHeight;
		bool rayT;

		scene(void);
		scene(vertex eye,vertex planeV1,vertex planeV2,vertex  planeV3,vertex planeV4,int width, int height );
	};

#endif