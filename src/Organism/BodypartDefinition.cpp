#include "BodypartDefinition.h"

BodypartDefinition::BodypartDefinition()
{
	//Set Defaults
	mAngle			=	0.f;
	mPosition		=	evolve::Vec2(0,0);
	mSize			=	evolve::Vec2(1,1);
	mRadius			=	1.f;
	mDensity		=	1.f;
	mColor			=	sf::Color::Cyan;
	mJointDefinition = JointDefinition();
	mShape = Shape::Circle;
}

BodypartDefinition::~BodypartDefinition()
{
}

void BodypartDefinition::Color(sf::Color color)
{
	mColor = color;
}

void BodypartDefinition::Color(int color)
{
	sf::Color c;
	c.r = (color & 0xFF000000) >> 24;
	c.g = (color & 0x00FF0000) >> 16;
	c.b = (color & 0x0000FF00) >> 8;
	c.a = (color & 0x000000FF) >> 0;
	mColor = c;
}

void BodypartDefinition::Angle(float angle)
{
	mAngle = angle;
}

void BodypartDefinition::Position(evolve::Vec2 position)
{
	mPosition = position;
}

void BodypartDefinition::Size(evolve::Vec2 size)
{
	mSize = size;
	if (mSize.X < .2f)
		mSize.X = .2f;
	if (mSize.Y < .2f)
		mSize.Y = .2f;
}
void BodypartDefinition::Density(float density)
{
	mDensity = density;
}

void BodypartDefinition::Radius(float radius)
{
	mRadius = radius;
}

void BodypartDefinition::SetShape(BodypartDefinition::Shape shape)
{
	mShape = shape;
}

