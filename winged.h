
#ifndef __WINGED__
#define __WINGED__

	#include <GL/freeglut.h>
	#include <math.h>
	#include <vector>


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

	vertex diff(vertex a, vertex b);
	void unitize(vertex p);



#endif
