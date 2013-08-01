#include"scene.h"

	scene::scene(void){
		memset(this,0,sizeof(scene));
	}
	scene::scene(vertex i,vertex V1,vertex V2,vertex  V3,vertex V4,int w, int h){
		this->eye=i;
		this->planeV1=V1;
		this->planeV2=V2;
		this->planeV3=V3;
		this->planeV4=V4;
		this->windowWidth=w;
		this->windowHeight=h;
		this->rayT=true;
	}
