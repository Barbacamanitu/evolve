#include "Organism.h"
#include <Organism/Bodypart.h>
Organism::Organism()
{
    //ctor
}

Organism::~Organism()
{
    //dtor
}

void Organism::Dummy(b2World& world)
{
    Bodypart::BodypartProperties propA;
    Bodypart::BodypartProperties propB;

    propA.x =0.f;
    propA.y = .4f;
    propA.color = sf::Color::Red;
    propA.width = 3.f;
    propA.height = 1.5f;
    propB = propA;
    propB.width = 6.0;
    propB.height = 2.f;
    propB.y -= 5.f;
    propB.angle = 1.1f;
    propB.color = sf::Color::Green;
    propB.shape = 1;
    Bodypart::Ptr bA = Bodypart::Create(propA,world);
    Bodypart::Ptr bB = Bodypart::Create(propB,world);
    b2Vec2 pos;
    pos.x = 1.f;
    pos.y = 2.f;
    bA->AttachBodypart(bB->mBody,pos);
    AttachChild(std::move(bA));
    AttachChild(std::move(bB));

}
