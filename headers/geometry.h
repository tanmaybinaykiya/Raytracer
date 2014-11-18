#ifndef __GEOMETRY__
#define __GEOMETRY__

#include "sphere.h"
#include "light.h"
#include <cstring>

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
		std::vector<_light> lights;
		static geometry* getInstance();
		~geometry(){
			instanceFlag=false;
		};
	};

#endif