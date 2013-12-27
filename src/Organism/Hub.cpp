#include "Hub.h"
#include <Math/eMath.h>
Hub::Hub(float radius)
{
    //ctor
	mRadius = radius;
	debugCirc.setRadius(radius);
	debugCirc.setOrigin(sf::Vector2f(radius,radius));
	debugCirc.setFillColor(sf::Color::Red);

}

Hub::~Hub()
{
    //dtor
}

void Hub::RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{
	target.draw(debugCirc,states);
}
void Hub::AttachBone(Bone::Ptr child,float angle)
{
	float rad = evolve::Conversions::DegreesToRadians(angle);
	//Find attachment position
	sf::Vector2f aPos(cos(rad) * mRadius,sin(rad) * mRadius);
	child->setPosition(aPos);
	child->setRotation(angle);
	AttachChild(std::move(child));

}