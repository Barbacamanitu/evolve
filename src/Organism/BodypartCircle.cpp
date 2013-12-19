#include "BodypartCircle.h"
#include "BodypartDefinition.h"
#include "Box2D\Box2D.h"
#include <Math/eMath.h>

BodypartCircle::BodypartCircle(BodypartDefinition& bpDef, b2World* world)
{
	b2BodyDef bDef;
	bDef.type = b2_dynamicBody;
	bDef.angle = evolve::Conversions::DegreesToRadians(bpDef.Angle());
	bDef.position = bpDef.Position().toBox2D();
	//bDef.userData = this;

	//Create and attach body
	mBody = world->CreateBody(&bDef);

	//Now create fixture
	b2CircleShape circ;
	circ.m_radius = bpDef.Radius();

	b2FixtureDef bFixDef;
	bFixDef.density = bpDef.Density();
	bFixDef.restitution = 1.f;
	bFixDef.shape = &circ;
	mBody->CreateFixture(&bFixDef);

	//Lastly, create and attach the drawable rectangle
	sf::CircleShape* rShape = new sf::CircleShape();
	rShape->setRadius(bpDef.Radius());
	rShape->setFillColor(bpDef.Color());
	rShape->setOrigin(sf::Vector2f(bpDef.Radius(),bpDef.Radius()));
	visibleRepresentation = rShape;
}


BodypartCircle::~BodypartCircle(void)
{
}
