#include <Organism/Organism.h>
#include <Organism/Bodypart.h>
#include <Organism/BodypartRectangle.h>
#include "BodypartFactory.h"
#include <Math/eMath.h>
#include "JointDefinition.h"
#include <SFML/Graphics.hpp>
Organism::Organism()
{
    //ctor
}

Organism::~Organism()
{
    //dtor
}

BodypartDefinition Organism::randDef()
{
	float scalar = .5f;
	BodypartDefinition bDef;
	if (rand() % 2 == 1)
		bDef.SetShape(BodypartDefinition::Shape::Rectangle);
	evolve::Vec2 mSize = evolve::Vec2((rand() % 300)+80,(rand() % 300)+80) * .01f;

	bDef.Size(mSize);
	bDef.Radius(mSize.X/2.f);
	sf::Color c;
	c.r = rand() % 255;
	c.g = rand() % 255;
	c.b = rand() % 255;
	c.a = rand() % 100 + 155;
	bDef.Color(c);


	JointDefinition jDef;

	evolve::Vec2 pA = evolve::Vec2((rand() % 100) - 50,(rand() % 100) - 50) * .1f * scalar;
	evolve::Vec2 cA = evolve::Vec2((rand() % 100) - 50,(rand() % 100) - 50) * .1f * scalar;
	jDef.ParentAnchor(pA);
	jDef.ChildAnchor(cA);
	jDef.Constraints(evolve::Vec2((rand() % 360) * -1,(rand() % 360)));
	bDef.mJointDefinition = jDef;
	return bDef;
}


void Organism::UpdateSelf(float dt)
{

}
