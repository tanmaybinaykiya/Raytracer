
#ifndef __GEOMETRY__
#define __GEOMETRY__

#include<cstring>
#include<GL/freeglut.h>


	class geometry{
	public:
		geometry(){
		}
		//static bool instantiated;
		//geometry *instance;
		//geometry* getInstance(void);

	};

	
    class wEdge;

	class vertex{
	public :
		GLfloat x;
		GLfloat y;
		GLfloat z;
		vertex(void){
			x=y=z=0;
		}
		vertex(GLfloat a,GLfloat b,GLfloat c){
			x=a;
			y=b;
			z=c;
		}

	};

	class face{
	public :
		int e1,e2,e3,e4;
		vertex normal;
		face(void){
			e1=e2=e3=-1;
		}
		face(int vert1,int vert2,int vert3,int vert4){
			int edge1=-1,edge2=-1,edge3=-1;
			// Check if twin of the edge exists

			int e12=twinExists(vert1,vert2);
			int e23=twinExists(vert3,vert2);
			int e43=twinExists(vert4,vert3);
			int e41=twinExists(vert4,vert1);

		// According to the twin edge, create new edges if twin does not exist

			if (e12==-1){
				edges.push_back(wEdge(vert1,vert2));
				e1=edges.size();
			}
			else{
			e1=e12;
			}

			if (e23==-1){
				edges.push_back(wEdge(vert2,vert3));
				e2=edges.size();
			}
			else{
			e1=e23;
			}

			if (e43==-1){
				edges.push_back(wEdge(vert4,vert3));
				e3=edges.size();
			}
			else{
			e3=e43;
			}

			if (e41==-1){
				edges.push_back(wEdge(vert4,vert1));
				e4=edges.size();
			}
			else{
			e4=e41;
			}

		// Setup face normals assuming the quad face is planar

			GLfloat x21 = vertices[vert2].x-vertices[vert1].x;
			GLfloat y21 = vertices[vert2].y-vertices[vert1].y;
			GLfloat z21 = vertices[vert2].z-vertices[vert1].z;

			GLfloat x32 = vertices[vert3].x-vertices[vert2].x;
			GLfloat y32 = vertices[vert3].y-vertices[vert2].y;
			GLfloat z32 = vertices[vert3].z-vertices[vert2].z;


			normal.x=y21*z32 - z21*y32;
			normal.y=z21*x32 - x21*z32;
			normal.z=x21*y32 - y21*x32;

		//	setup left and right edges for each edge

			if((edges[e1].aLeft)==-1){
				edges[e1].aLeft=e2;
				edges[e1].aRight=e4;
			}
			else {
				edges[e1].bLeft=e4;
				edges[e1].bRight=e2;
			}

			if((edges[e2].aLeft)==-1){
				edges[e2].aLeft=e3;
				edges[e2].aRight=e1;
			}
			else {
				edges[e2].bLeft=e1;
				edges[e2].bRight=e3;
			}

			if((edges[e3].aLeft)==-1){
				edges[e3].aLeft=e4;
				edges[e3].aRight=e2;
			}
			else {
				edges[e3].bLeft=e2;
				edges[e3].bRight=e4;
			}

			if((edges[e4].aLeft)==-1){
				edges[e4].aLeft=e3;
				edges[e4].aRight=e1;
			}
			else {
				edges[e4].bLeft=e1;
				edges[e4].bRight=e3;
			}

		// Setup faces for edges

			int fSize=faces.size();
			if (edges[e1].f1==-1){
				edges[e1].f1=fSize;;
			}
			else{
				edges[e1].f2=fSize;;
			}

			if (edges[e2].f1==-1){
				edges[e2].f1=fSize;;
			}
			else{
				edges[e2].f2=fSize;;
			}

			if (edges[e3].f1==-1){
				edges[e3].f1=fSize;;
			}
			else{
				edges[e3].f2=fSize;;
			}

			if (edges[e4].f1==-1){
				edges[e4].f1=fSize;;
			}
			else{
				edges[e4].f2=fSize;;
			}
		}
	};

	class wEdge{
	public :
		int v1,v2;
		int f1,f2;
		int aLeft,aRight,bLeft,bRight;

		wEdge(void){
			 v1=v2=f1=f2=aLeft=aRight=bLeft=bRight=-1;
		}
		wEdge(int a,int b){
				v1=a;
				v2=b;
				f1=f2=aLeft=aRight=bLeft=bRight=-1;
		}
		wEdge(int V1,int V2,int F1,int F2){
				v1=V1;
				v2=V2;
				f1=F1;
				f2=F2;
				aLeft=aRight=bLeft=bRight=-1;
		}

	};

#endif