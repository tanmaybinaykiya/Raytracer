#include "header.h"

scene myScene;
std::vector<vertex> vertices;
std::vector<wEdge> edges;
std::vector<face> faces;
std::vector <std::vector<color> > buffer;

int main(int argc, char **argv)
{
    buffer=initializeScene();
	
	input();
	raytrace();
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(myScene.windowWidth,myScene.windowHeight);
	glutCreateWindow("My RayTracer");
    glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
    
    glutMainLoop();
	
	return 1;
}
