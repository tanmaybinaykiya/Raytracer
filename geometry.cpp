#ifndef __GEOMDEF__
#define __GEOMDEF__

	#include "header.h"

	geometry::geometry(){
		memset(this,0,sizeof(geometry));
	}
	
	
	vertex::vertex(void){
		x=y=z=0;
	}
	
	vertex::vertex(GLfloat a,GLfloat b,GLfloat c){
		x=a;
		y=b;
		z=c;
		//std::cout<<"vertex created \n";
	}
	
	
	face::face(void){
		memset(this,0,sizeof(face));
		edge[0]=edge[1]=edge[2]=edge[3]=-1;
	}
	
	face::face(int vert1,int vert2,int vert3,int vert4){

		
	// Check if twin of the edge exists

		int e12=twinExists(vert1,vert2);
		int e23=twinExists(vert2,vert3);
		int e34=twinExists(vert3,vert4);
		int e41=twinExists(vert4,vert1);

		std::cout<<" ";
		// According to the twin edge, create new edges if twin does not exist

		if (e12==-1){
			edges.push_back(wEdge(vert1,vert2));
			edge[0]=edges.size()-1;
		}
		else{
			edge[0]=e12;
		}

		if (e23==-1){
			edges.push_back(wEdge(vert2,vert3));
			edge[1]=edges.size()-1;
		}
		else{
			edge[1]=e23;
		}

		if (e34==-1){
			edges.push_back(wEdge(vert3,vert4));
			edge[2]=edges.size()-1;
		}
		else{
			edge[2]=e34;
		}

		if (e41==-1){
			edges.push_back(wEdge(vert4,vert1));
			edge[3]=edges.size()-1;
		}
		else{
			edge[3]=e41;
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
		normal.unitize();

	// Setup faces for edges

		int fSize=faces.size();
		if (edges[edge[0]].rightFace==-1){
			edges[edge[0]].rightFace=fSize;;
		}
		else{
			edges[edge[0]].leftFace=fSize;;
		}

		if (edges[edge[1]].rightFace==-1){
			edges[edge[1]].rightFace=fSize;;
		}
		else{
			edges[edge[1]].leftFace=fSize;;
		}

		if (edges[edge[2]].rightFace==-1){
			edges[edge[2]].rightFace=fSize;;
		}
		else{
			edges[edge[2]].leftFace=fSize;;
		}

		if (edges[edge[3]].rightFace==-1){
			edges[edge[3]].rightFace=fSize;;
		}
		else{
			edges[edge[3]].leftFace=fSize;;
		}

	//	Setup left and right edges for each edge

		//find whether the current face is in left or right and decide on the leftPrev ...

		if (edges[edge[0]].rightFace==fSize){
			//add prev and next to right
			edges[edge[0]].rightNext=edge[1];
			edges[edge[0]].rightPrev=edge[3];
		}
		else{
			//add prev and next to left
			edges[edge[0]].leftNext=edge[3];
			edges[edge[0]].leftPrev=edge[1];
		}

		if (edges[edge[1]].rightFace==fSize){
			//add prev and next to right
			edges[edge[1]].rightNext=edge[2];
			edges[edge[1]].rightPrev=edge[0];
		}
		else{
			//add prev and next to left
			edges[edge[1]].leftNext=edge[0];
			edges[edge[1]].leftPrev=edge[2];
		}

		if (edges[edge[2]].rightFace==fSize){
			//add prev and next to right
			edges[edge[2]].rightNext=edge[3];
			edges[edge[2]].rightPrev=edge[1];
		}
		else{
			//add prev and next to left
			edges[edge[2]].leftNext=edge[1];
			edges[edge[2]].leftPrev=edge[3];
		}

		if (edges[edge[3]].rightFace==fSize){
			//add prev and next to right
			edges[edge[3]].rightNext=edge[0];
			edges[edge[3]].rightPrev=edge[2];
		}
		else{
			//add prev and next to left
			edges[edge[3]].leftNext=edge[2];
			edges[edge[3]].leftPrev=edge[0];
		}

		//std::cout<<"FACE CREATED \n";


	}
	
	
	wEdge::wEdge(void){
		
		v1=v2=leftFace=rightFace=leftNext=leftPrev=rightNext=rightPrev=-1;
	}
	
	wEdge::wEdge(int a,int b){
			v1=a;
			v2=b;
			leftFace=rightFace=leftNext=leftPrev=rightNext=rightPrev=-1;
	}
	
	wEdge::wEdge(int V1,int V2,int F1,int F2){
			v1=V1;
			v2=V2;
			leftFace=F1;
			rightFace=F2;
			leftNext=leftPrev=rightNext=rightPrev=-1;
	}

	vertex diff(vertex a, vertex b){
		return(vertex(a.x-b.x,a.x-b.y,a.z-b.z));
	}

	void vertex::unitize(){
		GLfloat norm= sqrt((this->x*this->x) + (this->y*this->y)+ (this->z*this->z));
		this->x/=norm;
		this->y/=norm;
		this->z/=norm;
	}

#endif
