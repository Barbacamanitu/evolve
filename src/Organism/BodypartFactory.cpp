#include "BodypartFactory.h"
#include "BodypartDefinition.h"
#include "BodypartRectangle.h"
#include "BodypartCircle.h"
#include <Box2D\Box2D.h>


std::unique_ptr<Bodypart> BodypartFactory::CreateBodypart(BodypartDefinition& bpDef,b2World* world)
{
	Bodypart::Ptr bp(new Bodypart());
	//Determine type of body part to create
	switch(bpDef.GetShape())
	{
	case BodypartDefinition::Shape::Rectangle:
		bp.reset(new BodypartRectangle(bpDef,world));
		break;
	case BodypartDefinition::Shape::Circle:
		bp.reset(new BodypartCircle(bpDef,world));
		break;
	default:
		break;
	}
	for (BodypartDefinition child : bpDef.mChildNodes)
	{
		bp->CreateChild(child);
	}
	return std::move(bp);

}

void BodypartFactory::CreateChildren(BodypartDefinition& bpDef,b2World* world,Bodypart::Ptr & parent)
{
	for (BodypartDefinition child : bpDef.mChildNodes)
	{
		parent->CreateChild(child);
	}
}