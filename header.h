
#ifndef __HEADER__
#define __HEADER__

	#include <iostream>
	#include <vector>
	#include <cstdio>
	#include <GL/freeglut.h>
	#include <math.h>

	#include "color.h"
	#include "geometry.h"
	#include "ray.h"
	#include "scene.h"
	#include "sphere.h"

	extern GLboolean rayT;
	extern vertex eye;
	extern vertex viewPlane[4];
	extern std::vector<vertex> vertices;
	extern std::vector<face> faces;
	extern std::vector<wEdge> edges;
	extern sphere mySphere;
	extern scene myScene;
	extern std::vector<std::vector<color>> buffer;

	const int screenW=300,screenH=300;
	const GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0};		// Red diffuse light.
	const GLfloat light_position[] = {1.0, 1.0, 1.0, 1.0};	// Infinite light location.
	const char filename[] = "objects/input3.txt";


//	glutRoutines
	void reshape (int w, int h);
	void display(void);
	void keyboard (unsigned char key, int x, int y);

//	glRoutine	(WITHOUT RAYTRACER)
	void initGL(void);
	void drawGeometry(void);
	void drawGrid(void);
	void drawByEdge(void);
	void drawByQuads(void);
	void glRoutine(void);
	void light(void);

//	RTRoutine (RAYTRACER)
	std::vector <std::vector<color> >  initializeScene(void);
	void initializeGeometry(void);
	void initRT(void);
	color isHit(ray r);
	bool isHitQuad(ray r,face);
	bool isHitSphere(ray r,sphere c);
	void raytrace(void);
	void drawGeometryRT();
	void rtRoutine(void);
	GLfloat max(GLfloat a,GLfloat b);
	void noLight(void);
	color shade(ray r);

//	INPUT	
	void input(void);
	int twinExists(int v1,int v2);
	void inputReport(void);

//	Main
	

//	Geometry
	vertex diff(vertex a, vertex b);
	void unitize(vertex p);

//	Ray
	GLfloat dot(vertex a,vertex b);
	vertex cross(vertex a,vertex b);

////#define _input_



#endif
