#ifndef BODYPARTRECTANGLE_H
#define BODYPARTRECTANGLE_H

#include "Bodypart.h"

class BodypartDefinition;
class b2World;
class BodypartRectangle :
	public Bodypart
{
public:
	BodypartRectangle(BodypartDefinition& bpDef, b2World* world);
	~BodypartRectangle(void);

};
#endif
