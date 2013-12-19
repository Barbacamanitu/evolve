#ifndef BODYPARTDEFINITION_H
#define BODYPARTDEFINITION_H
#include <SFML/Graphics.hpp>
#include <Math/Vec2.h>
#include "JointDefinition.h"
class BodypartDefinition
{

	/*

	Abstract base class
	Derive all bodypart deifnition from this class

	*/

public:
	BodypartDefinition();
	virtual ~BodypartDefinition();
	//Accessors
	void Angle(float angle);
	float Angle(){
		return mAngle;
	};

	void Radius(float radius);
	float Radius(){
		return mRadius;
	};

	void Position(evolve::Vec2 position);
	evolve::Vec2 Position(){
		return mPosition;
	};

	void Size(evolve::Vec2 size);
	evolve::Vec2 Size(){
		return mSize;
	};

	

	void Density(float density);
	float Density(){
		return mDensity;
	};

	void Color(sf::Color color);
	void Color(int color);
	sf::Color Color(){
		return mColor;
	};

	


	JointDefinition mJointDefinition;

	enum class Shape
	{
		Rectangle, Circle
	};

	void SetShape(BodypartDefinition::Shape color);
	Shape GetShape(){
		return mShape;
	};

	std::vector<BodypartDefinition> mChildNodes;
private:
	evolve::Vec2	mSize;  //For Rectangles
	float			mRadius; //For Cirlces
    float			mAngle;
	evolve::Vec2	mPosition;
	float			mDensity;
    sf::Color		mColor;
	Shape			mShape;

};
#endif