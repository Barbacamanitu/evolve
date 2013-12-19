#include "BodypartRectangle.h"
#include "BodypartDefinition.h"
#include "Box2D\Box2D.h"
#include <Math/eMath.h>
BodypartRectangle::BodypartRectangle(BodypartDefinition& bpDef,b2World* world)
{
	b2BodyDef bDef;
	bDef.type = b2_dynamicBody;
	bDef.angle = evolve::Conversions::DegreesToRadians(bpDef.Angle());
	bDef.position = bpDef.Position().toBox2D();
	//bDef.userData = this;

	//Create and attach body
	mBody = world->CreateBody(&bDef);

	//Now create fixture
	b2PolygonShape rect;
	evolve::Vec2 boxCenter = bpDef.Size()/2.f;
	rect.SetAsBox(boxCenter.X,boxCenter.Y);

	b2FixtureDef bFixDef;
	bFixDef.density = bpDef.Density();
	bFixDef.restitution = 1.f;
	bFixDef.shape = &rect;
	mBody->CreateFixture(&bFixDef);

	//Lastly, create and attach the drawable rectangle
	sf::RectangleShape* rShape = new sf::RectangleShape();
	rShape->setSize(bpDef.Size().toSFML());
	rShape->setFillColor(bpDef.Color());
	rShape->setOrigin(boxCenter.toSFML());
	visibleRepresentation = rShape;
}

BodypartRectangle::~BodypartRectangle(void)
{
}
