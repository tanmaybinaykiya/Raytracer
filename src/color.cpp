#include "color.h"
#include <iostream>

color::color(void){
	r=g=b=(GLfloat)0;
}
color::color(GLfloat R, GLfloat G,GLfloat B){
	if(R<=1 && G<=1 && B<=1){
	r=R;g=G;b=B;
	}
	else{
	std::cout<<"Error in RGB values";
	}
}
color color::operator+(const color& other){
	return (color(r+other.r,g+other.g,b+other.b));
}