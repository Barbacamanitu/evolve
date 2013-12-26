#include "Bone.h"

Bone::Bone(float length, float rotation, evolve::Vec2 constraints)
{
    //ctor
    mLength = length;
    mConstraints = constraints;

    debugRect.setSize(sf::Vector2f(mLength,1.f));
    debugRect.setOrigin(sf::Vector2f(0.f,.5f));
    debugRect.setFillColor(sf::Color::White);



    float dcRadius = .75f;
    debugCirc.setRadius(dcRadius);
    debugCirc.setFillColor(sf::Color::Green);
    debugCirc.setOrigin(sf::Vector2f(dcRadius,dcRadius));

}


Bone::~Bone()
{
    //dtor
}
