#include "light.h"

light::light(){
	location=vertex(0,0,0);
}

light::light(vertex v){
	location=v;
}