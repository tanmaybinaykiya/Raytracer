#include "light.h"

_light::_light(){
	location=vertex(0,0,0);
}

_light::_light(vertex v,int type, color col){
	if(type==POINT_LIGHT){
		location = v;
	}
	else if(type==DIRECTIONAL_LIGHT){
		direction = v;
	}
	colour=col;
}
_light::~_light(){
	;
}