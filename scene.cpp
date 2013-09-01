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
	
	void scene::editScene(vertex i,vertex V1,vertex V2,vertex  V3,vertex V4,int w, int h){
		this->eye=i;
		this->planeV1=V1;
		this->planeV2=V2;
		this->planeV3=V3;
		this->planeV4=V4;
		this->windowWidth=w;
		this->windowHeight=h;
		this->rayT=true;
	}

	void scene::editScreen(int w, int h){
		this->windowWidth=w;
		this->windowHeight=h;
		std::vector <std::vector<color> > temp (2*this->windowHeight, std::vector<color>(2*this->windowWidth));
		this->buffer=temp;
	}