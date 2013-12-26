#ifndef VEC2_H
#define VEC2_H
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
namespace evolve
{
	class Vec2
	{
	public:
		//Constructors
		Vec2(void);
		Vec2(float x,float y);
		Vec2(int x,int y);
		Vec2(b2Vec2& bVec);
		Vec2(sf::Vector2f& sfVec);

		Vec2 operator+(const Vec2& other);
		Vec2 operator-(const Vec2& other);
		Vec2 operator*(const float scalar);
		Vec2 operator/(const float scalar);

		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(const float scalar);
		Vec2& operator/=(const float scalar);

		~Vec2(void);


		float X;
		float Y;

		//Conversions
		sf::Vector2f toSFML();
		b2Vec2 toBox2D();
	};
}
#endif

