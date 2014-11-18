#include "header.h"

int main(int argc, char **argv)
{
	scene *myScene=scene::getInstance();

	initializeScene();
	initializeGeometry();
	
	raytrace();
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(myScene->windowWidth,myScene->windowHeight);
	glutCreateWindow("My RayTracer");
    glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
    
    glutMainLoop();
	
	return 1;
}
