#ifndef BODYPARTFACTORY_H
#define BODYPARTFACTORY_H
#include <memory>
class Bodypart;
class BodypartDefinition;
class BodypartRectangle;
class BodypartCircle;
class b2World;
#include "Bodypart.h"
class BodypartFactory
{
public:
	static std::unique_ptr<Bodypart> CreateBodypart(BodypartDefinition& bpDef,b2World* world);
private:
	static BodypartRectangle CreateRectangle(BodypartDefinition& bpDef);
	static BodypartCircle CreateCircle(BodypartDefinition& bpDef);
	static void CreateChildren(BodypartDefinition& bpDef,b2World* world,Bodypart::Ptr& parent);
};
#endif

