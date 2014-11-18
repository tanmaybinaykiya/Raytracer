#ifndef __LIGHTS__
#define __LIGHTS__

#include "winged.h"
#include "color.h"

#define POINT_LIGHT 1
#define DIRECTIONAL_LIGHT 2
#define LAMBERT_COEFFICIENT  0.11


class _light{
	public:
		vertex location;
		vertex direction;
		color colour;
		int lightType;

		_light(void);
		_light(vertex ,int, color);

		~_light();
};


#endif