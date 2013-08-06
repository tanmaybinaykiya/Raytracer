#include"scene.h"

	bool scene::instanceFlag = false;
	scene* scene::instance = NULL;
	scene* scene::getInstance()
	{
		if(! instanceFlag)
		{
			instance =new scene();
			instanceFlag = true;
			return instance;
		}
		else
		{
			return instance;
		}
	}

	scene::scene(void){
		memset(this,0,sizeof(scene));
	}
	void editScene(vertex i,vertex V1,vertex V2,vertex  V3,vertex V4,int w, int h){
	scene *myScene=scene::getInstance();
		myScene->eye=i;
		myScene->planeV1=V1;
		myScene->planeV2=V2;
		myScene->planeV3=V3;
		myScene->planeV4=V4;
		myScene->windowWidth=w;
		myScene->windowHeight=h;
		myScene->rayT=true;
	}
