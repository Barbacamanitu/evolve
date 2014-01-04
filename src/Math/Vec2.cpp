#include "Vec2.h"


evolve::Vec2::Vec2(void)
{
	X = 0.f;
	Y = 0.f;
}

evolve::Vec2::Vec2(float x, float y)
{
	X = x;
	Y = y;
}

evolve::Vec2::Vec2(int x, int y)
{
	X = (float) x;
	Y = (float) y;
}

evolve::Vec2::Vec2(b2Vec2& bVec)
{
	X = bVec.x;
	Y = bVec.y;
}

evolve::Vec2::Vec2(sf::Vector2f& sfVec)
{
	X = sfVec.x;
	Y = sfVec.y;
}


double evolve::Vec2::ToRadians()
{
	Vec2 simple(X,Y);
	simple.Normalize();
	return atan2(simple.X,simple.Y);
}

float evolve::Vec2::DistanceTo(Vec2 other)
{
	return sqrt(pow(other.X - X,2) + pow(other.Y - Y,2));
}

evolve::Vec2& evolve::Vec2::Normalize()
{
	
	return *this /= Magnitude();
}

float evolve::Vec2::Magnitude()
{
	 return sqrt((X * X) + (Y * Y));
}



//Operator overloads
evolve::Vec2 evolve::Vec2::operator+(const Vec2& other)
{
	evolve::Vec2 newVec(X,Y);
	newVec.X += other.X;
	newVec.Y += other.Y;
	return newVec;
}

evolve::Vec2& evolve::Vec2::operator+=(const Vec2& other)
{
	X += other.X;
	Y += other.Y;
	return *this;
}

evolve::Vec2& evolve::Vec2::operator-=(const Vec2& other)
{
	X -= other.X;
	Y -= other.Y;
	return *this;
}

evolve::Vec2& evolve::Vec2::operator*=(const float scalar)
{
	X *= scalar;
	Y *= scalar;
	return *this;
}

evolve::Vec2& evolve::Vec2::operator/=(const float scalar)
{
	X /= scalar;
	Y /= scalar;
	return *this;
}

evolve::Vec2 evolve::Vec2::operator-(const Vec2& other)
{
	evolve::Vec2 newVec(X,Y);
	newVec.X -= other.X;
	newVec.Y -= other.Y;
	return newVec;
}

evolve::Vec2 evolve::Vec2::operator*(const float scalar)
{
	evolve::Vec2 newVec(X,Y);
	newVec.X *= scalar;
	newVec.Y *= scalar;
	return newVec;
}

evolve::Vec2 evolve::Vec2::operator/(const float scalar)
{
	evolve::Vec2 newVec(X,Y);
	newVec.X /= scalar;
	newVec.Y /= scalar;
	return newVec;
}


sf::Vector2f evolve::Vec2::toSFML()
{
	return sf::Vector2f(X,Y);
}

b2Vec2 evolve::Vec2::toBox2D()
{
	return b2Vec2(X,Y);
}




evolve::Vec2::~Vec2(void)
{
}

