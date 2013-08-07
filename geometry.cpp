#include "geometry.h"

	bool geometry::instanceFlag = false;
	geometry* geometry::instance = NULL;

	geometry* geometry::getInstance()
	{
		if(! instanceFlag)
		{
			instance =new  geometry();
			instanceFlag = true;
			return instance;
		}
		else
		{
			return instance;
		}
	}

	geometry::geometry(void){
		memset(this,0,sizeof(geometry));
	}