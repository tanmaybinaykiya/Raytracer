#include "header.h"

void input(){
	FILE *file = fopen ( filename, "r" );
	int vMax=0;
	if (file != NULL){
		char line [ 128 ];
			while ( fgets ( line, sizeof line, file ) != NULL ){	/* read a line */
				if (line[0]=='#' || line[0]==' '|| line[0]=='\n'){
					continue;
				}
				else if(line[0]=='v'){
					GLfloat x,y,z;
					sscanf (line,"v %f,%f,%f ",&x, &y, &z);
					//std::cout<<"Vertex detected: "<<x<<","<<y<<","<<z<<",\n";
					vertices.push_back(vertex(x,y,z));
					vMax=vertices.size();
				}
				else if(line[0]=='f'){
					int v1,v2,v3,v4;
					sscanf (line,"f %d,%d,%d,%d ",&v1, &v2, &v3, &v4);
					try{
						if (v1>vMax || v2>vMax|| v3>vMax|| v4>vMax){
							throw 100;
							break;
						}
						else{
							int fNum=faces.size();
							//std::cout<<"Face detected: "<<v1<<","<<v2<<","<<v3<<","<<v4<<"\n";
							//std::cout<<"FACE CONTAINS "<<faces.size()<<"\n";						
							faces.push_back(face(v1,v2,v3,v4));
							//std::cout<<faces.size()<<"th face created \n";
						}
					}
					catch(int a){
						if (a==100){ std::cout<<"Invalid Vertex Index"; 
						}
					}
				}
				else {
						fputs ( line, stdout ); /* write the line */
					}
			}
			fclose ( file );
	}
	else{
		perror ( filename );
	}
	//inputReport();
}
int twinExists(int vert1,int vert2){
	int totEdges=edges.size();
	int i;
	for(i=0;i<totEdges;i++){
		if ((edges[i].v1==vert1 && edges[i].v2==vert2 )||(edges[i].v1==vert2 && edges[i].v2==vert1 )){
			return i;
		}
	}
	return -1;
}
void inputReport(void){
	int i=0,max=0;
	max=edges.size();
	std::cout<<"\nEdges : \n";
	std::cout<<"------------------------------------------------------------------------------ \n";
	std::cout<<"Edge No. V1 \t V2  LeftPrev LeftNext  RightPrev RightNext LeftFace Right Face \n";
	std::cout<<"------------------------------------------------------------------------------ \n";

	for (i=0;i<max;i++){
		std::cout<<"  "<<i<<" \t "<<edges[i].v1<<" \t "<<edges[i].v2<<" \t  ";
		std::cout<<edges[i].leftPrev<<"  \t "<<edges[i].leftNext<<" \t   ";
		std::cout<<edges[i].rightPrev<<"  \t    "<<edges[i].rightNext<<"    \t ";
		std::cout<<edges[i].leftFace<<"  \t    "<<edges[i].rightFace<<" \n";
	}

	max=faces.size();
	std::cout<<"\nFaces : \n";
	std::cout<<"------------------------------------ \n";
	std::cout<<"Face No. E1 \t E2 \t E3 \t E4 \n";
	std::cout<<"------------------------------------ \n";
	for (i=0;i<max;i++){
		std::cout<<"  "<<i<<" \t "<<faces[i].edge[0]<<" \t "<<faces[i].edge[1]<<" \t "<<faces[i].edge[2]<<" \t "<<faces[i].edge[3]<<"\n";
	}
}