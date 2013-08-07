#include "header.h"

void reshape (int w, int h)
{
	glViewport (0,0,(GLsizei) w,(GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0);
	//gluLookAt(0,0,10,0,0,0,0,1,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display(void)
{
	scene *myScene=scene::getInstance();
	glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if(myScene->rayT){
		rtRoutine();
	}
	else{
		glRoutine();
		Sleep(100);
		glutPostRedisplay();
	}
    glutSwapBuffers();
	
}

void keyboard (unsigned char key, int x, int y)
{
	scene *myScene=scene::getInstance();
	switch (key) {

		case 'r':
			myScene->rayT=!myScene->rayT;
			glutPostRedisplay();
			break;

		case 'w':
			myScene->eye.z+=(GLfloat).5;
//			std::cout<<"W pressed \n";
			raytrace();
			glutPostRedisplay();
			//std::cout<<"EYE:("<<myScene.eye.x<<","<<myScene.eye.y<<","<<myScene.eye.z<<") \n";
			break;

		case 'a':
			myScene->eye.x-=(GLfloat).2;
			//std::cout<<"A pressed \n";
			raytrace();
			glutPostRedisplay();
			break;

		case 's':
			myScene->eye.z-=(GLfloat).5;
			//std::cout<<"S pressed \n";
			raytrace();
			glutPostRedisplay();
			break;

		case 'd':
			myScene->eye.x+=(GLfloat).2;
			//std::cout<<"D pressed \n";
			raytrace();
			glutPostRedisplay();
			break;

		case 27:
			exit(0);
			break;
	}
}
