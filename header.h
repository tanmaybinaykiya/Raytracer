#ifndef __HEADER__
#define __HEADER__

	
	#include <iostream>
	#include <vector>
	#include <cstdio>
	#include <GL/freeglut.h>
	#include <math.h>

	#include "color.h"
	#include "winged.h"
	#include "geometry.h"
	#include "ray.h"
	#include "scene.h"
	#include "sphere.h"
	#include "light.h"	

	const int SPHERE= 1;
	const int FACE= 2;
	const int MAX_RAYTRACING_DEPTH=4;

	const int screenW=400,screenH=400;
	const GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0};		// Red diffuse light.
	const GLfloat light_position[] = {1.0, 1.0, 1.0, 1.0};	// Infinite light location.
	const char filename[] = "objects/input3.txt";
	const color kd=color(0.1,0.1,0.1);
	const color ks=color(0.1,0.1,0.1);
	const color ka=color(0.1,0.1,0.1);
	const color kr=color(0.1,0.1,0.1);

//	GlutRoutines
	void reshape (int w, int h);
	void display(void);
	void keyboard (unsigned char key, int x, int y);

//	Scene
	//void editScene(vertex i,vertex V1,vertex V2,vertex  V3,vertex V4,int w, int h);

//	GLRoutine	(WITHOUT RAYTRACER)
	void initGL(void);
	void drawGeometry(void);
	void drawGrid(void);
	void drawByEdge(void);
	void drawByQuads(void);
	void glRoutine(void);
	void light(void);

//	RTRoutine (RAYTRACER)
	void initializeScene(void);
	void initializeGeometry(void);
	void initRT(void);
	color isHit(ray r,int depth );
	void raytrace(void);
	void drawGeometryRT(void);
	void rtRoutine(void);
	GLfloat max(GLfloat a,GLfloat b);
	void noLight(void);
	color shade(ray r, int intersectionType,int i);

//	Input
	void input(void);
	int twinExists(int v1,int v2);
	void inputReport(void);

//	Main
	
//	Winged

//	Ray

//	#define _input_
#endif