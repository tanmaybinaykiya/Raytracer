#ifndef __RAY_DEFS_
#define __RAY_DEFS_

#include "ray.h"

ray::ray(void){
	memset(this,0,sizeof(ray));
}

ray::ray(GLfloat a,GLfloat b,GLfloat c,GLfloat dx,GLfloat dy,GLfloat dz){
	this->start.x=a;
	this->start.y=b;
	this->start.z=c;
	vertex v=vertex(dx,dy,dz);
	//v.unitize();
	this->direction=v;
}

ray::ray(vertex a,vertex b){
	this->start=a;
	//b.unitize();
	this->direction=b;
}

GLfloat dot(vertex a,vertex b){
	GLfloat x=a.x*b.x;
	GLfloat y=a.y*b.y;
	GLfloat z=a.z*b.z;
	return (x+y+z);
}

vertex cross(vertex a,vertex b){
	GLfloat x=  a.y*b.z-a.z*b.y ;
	GLfloat y=-(a.x*b.z-a.z*b.x);
	GLfloat z=  a.x*b.y-a.y*b.x ;
	return vertex(x,y,z);
}

#endif