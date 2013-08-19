#ifndef __LIGHTS__
#define __LIGHTS__

#include "winged.h"

class light{
	public:
		vertex location;
		light(void);
		light(vertex);

		~light();
};


#endif