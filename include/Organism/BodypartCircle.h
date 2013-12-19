#ifndef BODYPARTCIRCLE_H
#define BODYPARTCIRCLE_H
#include "Bodypart.h"
class BodypartDefinition;
class b2World;
class BodypartCircle :
	public Bodypart
{
public:
	BodypartCircle(BodypartDefinition& bpDef, b2World* world);
	~BodypartCircle(void);

};
#endif

