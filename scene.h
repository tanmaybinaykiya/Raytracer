#ifndef __SCENE__
#define __SCENE__

#include "geometry.h"
#include <vector>
#include "color.h"

//SINGLETON SCENE
class scene{
	private :
		static bool instanceFlag;
		static scene* instance;
		scene(void);
		
public :
		vertex eye;
		vertex planeV1,planeV2,planeV3,planeV4;
		int windowWidth, windowHeight;
		bool rayT;
		std::vector <std::vector<color> > buffer;
		
		static scene* getInstance();
		void editScene(vertex eye, vertex planeV1, vertex planeV2, vertex  planeV3, vertex planeV4, int width, int height );
			scene::~scene(){
			instanceFlag=false;
		}
	};

#endif