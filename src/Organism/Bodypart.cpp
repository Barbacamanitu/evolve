#include "Bodypart.h"
#include <Box2D/Box2D.h>
#include <Math/eMath.h>
#include "BodypartRectangle.h"
#include "BodypartFactory.h"
Bodypart::Bodypart()
{

}


Bodypart::~Bodypart(void)
{
}

void Bodypart::CreateChild(BodypartDefinition bDef)
{
	//Create Child Body part
	Bodypart::Ptr childBP(BodypartFactory::CreateBodypart(bDef,mBody->GetWorld()));
	//Attach to self with a joint
	childBP->AttachToParent(this,bDef.mJointDefinition);
	//Add as a child so it renders.
	AttachChild(std::move(childBP));

}

void Bodypart::CreateChildren(BodypartDefinition bDef)
{
	for (BodypartDefinition childDef : bDef.mChildNodes)
	{
		CreateChild(childDef);
	}
}

void Bodypart::AttachToParent(Bodypart* parent,JointDefinition jDef)
{
	b2RevoluteJointDef rjDef;
	rjDef.bodyA = parent->mBody;
	rjDef.bodyB = mBody;
	rjDef.collideConnected = false;
	rjDef.localAnchorA = jDef.ParentAnchor().toBox2D();
	rjDef.localAnchorB = jDef.ChildAnchor().toBox2D();
	rjDef.upperAngle = evolve::Conversions::DegreesToRadians(jDef.Constraints().Y);
	rjDef.lowerAngle = evolve::Conversions::DegreesToRadians(jDef.Constraints().X);
	rjDef.enableLimit = true;
	mBody->GetWorld()->CreateJoint(&rjDef);
}

void Bodypart::RenderSelf(sf::RenderTarget &target,Game &game,float interpolation)
{
	sf::RenderStates states;
	b2Vec2 bPos = mBody->GetPosition();
	states.transform.translate(evolve::Vec2(bPos).toSFML());
	states.transform.rotate(evolve::Conversions::RadiansToDegrees(mBody->GetAngle()));
	target.draw(*visibleRepresentation,states);
}
