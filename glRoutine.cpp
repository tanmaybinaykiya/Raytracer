#include "header.h"

void initGL(void)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, 1, 1.0, 1000.0);
	gluLookAt(0,5,10,0,0,0,0,1,0);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glClearColor((GLclampf)0.2,(GLclampf)0.2,(GLclampf)0.2,(GLclampf)1);
}

void drawGeometry(void){
	//glLoadIdentity();
	glRotatef((GLfloat)5,(GLfloat)0,(GLfloat)1.0,(GLfloat)0.0);
	drawGrid();
//	drawByEdge();
	drawByQuads();
}
void drawGrid(void){
int i=0;
glColor3f((GLfloat)0.1,(GLfloat)0.1,(GLfloat)0.1);
for(i=0;i<11;i++){
	glBegin(GL_LINES);
		glVertex3i(i-5,0,-5);
		glVertex3i(i-5,0,5);
		glVertex3i(-5,0,i-5);
		glVertex3i(5,0,i-5);
	glEnd();
	}
}
void drawByEdge(){
	int i=0;
  	int	edgeNum=edges.size();
	glTranslatef(-.5,0,-.5);
	glColor3f(1,1,1);
	for (i=0;i<edgeNum;i++){
		glBegin(GL_LINES);
            glVertex3f(vertices[edges[i].v1].x,vertices[edges[i].v1].y,vertices[edges[i].v1].z);
            glVertex3f(vertices[edges[i].v2].x,vertices[edges[i].v2].y,vertices[edges[i].v2].z);
        glEnd();
     }
}
void drawByQuads(void ){
	int i=0,j=0;
  	int	faceNum=faces.size();
	for(i=0;i<faceNum;i++){
		glColor3f((GLfloat)i/faceNum,(GLfloat)1-i/faceNum,0);
		glBegin(GL_QUADS);
		for(j=0;j<4;j++){
			if (edges[faces[i].edge[j]].rightFace==i){
				glVertex3f(vertices[edges[faces[i].edge[j]].v1].x,vertices[edges[faces[i].edge[j]].v1].y,vertices[edges[faces[i].edge[j]].v1].z);
				glVertex3f(vertices[edges[faces[i].edge[j]].v2].x,vertices[edges[faces[i].edge[j]].v2].y,vertices[edges[faces[i].edge[j]].v2].z);
			}
			else{
				glVertex3f(vertices[edges[faces[i].edge[j]].v2].x,vertices[edges[faces[i].edge[j]].v2].y,vertices[edges[faces[i].edge[j]].v2].z);
				glVertex3f(vertices[edges[faces[i].edge[j]].v1].x,vertices[edges[faces[i].edge[j]].v1].y,vertices[edges[faces[i].edge[j]].v1].z);
			}
		}
		glEnd();
	}


}
void glRoutine(void){
	initGL();
	light();
	drawGeometry();
}
void light(void){
	
	/* Enable a single OpenGL light. */
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

  /* Use depth buffering for hidden surface elimination. */
    glEnable(GL_DEPTH_TEST);
}