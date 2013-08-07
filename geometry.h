#ifndef __GEOMETRY__
#define __GEOMETRY__


#include "winged.h"
#include "sphere.h"


class geometry{
		//SINGLETON
	private:
		static bool instanceFlag;
		static geometry* instance;
		geometry();

	public:
		std::vector<vertex> vertices;
		std::vector<wEdge> edges;
		std::vector<face> faces;
		std::vector<sphere> spheres;
		static geometry* getInstance();
		~geometry(){
			instanceFlag=false;
		};
	};

#endif