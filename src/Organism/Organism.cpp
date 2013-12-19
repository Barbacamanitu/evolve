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

void Organism::Dummy(b2World& world)
{
	BodypartDefinition mainDef;
	mainDef.Color(sf::Color::Transparent);
	mainDef.Size(evolve::Vec2(0.0001f,0.0001f));
	for (int i = 0; i < (rand() % 20) + 10; i++)
	{
		BodypartDefinition &bA = randDef();
		for (int x = 0; i < (rand() % 30) + 10; i++)
		{
			BodypartDefinition &bB = randDef();
			for (int y = 0; i < (rand() % 50) + 10; i++)
			{
				BodypartDefinition &bC = randDef();

				bB.mChildNodes.push_back(bC);
			}
			bA.mChildNodes.push_back(bB);

			
			//Add B to A
		}
		//A has lots of B's. Do something with A.
		mainDef.mChildNodes.push_back(bA);
	}




	AttachChild(BodypartFactory::CreateBodypart(mainDef,&world));


}

void Organism::UpdateSelf(float dt)
{
	
}