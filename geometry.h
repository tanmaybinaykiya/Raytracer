
#ifndef __GEOMETRY__
#define __GEOMETRY__

#include<GL/freeglut.h>
#include<math.h>
#include<vector>

    class wEdge;
	class vertex{
	public :
		GLfloat x;
		GLfloat y;
		GLfloat z;
		int edge[4];
	
		vertex(void);
		vertex(GLfloat a,GLfloat b,GLfloat c);
		void unitize();
		
	};

	class face{
	public :
		int edge[4];
		vertex normal;
		face(void);
		face(int a,int b,int c,int d);
		
	};

	class wEdge{
	public :
		int v1,v2;
		int leftFace,rightFace;
		int leftPrev,leftNext,rightPrev,rightNext;

		wEdge(void);
		wEdge(int a,int b);
		wEdge(int v1,int v2,int f1,int f2);
		
	};

	class geometry{
	private:
		static bool instanceFlag;
		static geometry* instance;
		geometry();

	public:
		std::vector<vertex> vertices;
		std::vector<wEdge> edges;
		std::vector<face> faces;
		static geometry* getInstance();

		geometry::~geometry(){
			instanceFlag=false;
		}
	};

#endif
