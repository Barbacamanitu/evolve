#include "Hub.h"
#include <Math/eMath.h>
#include "Bone.h"
Hub::Hub(float radius, float lowerConstraint, float upperConstraint)
{
    //ctor
	mRadius = radius;
	debugCirc.setRadius(radius);
	debugCirc.setOrigin(sf::Vector2f(radius,radius));
	debugCirc.setFillColor(sf::Color::Red);
	SetConstraints(evolve::Vec2(lowerConstraint,upperConstraint));

}

Hub::~Hub()
{
    //dtor
}


void Hub::RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{
	target.draw(*mSkin,states);
	//target.draw(debugCirc,states);
}
void Hub::AttachBone(Bone::Ptr child,float angle)
{
	float rad = evolve::Conversions::DegreesToRadians(angle);
	//Find attachment position
	sf::Vector2f aPos(cos(rad) * mRadius,sin(rad) * mRadius);
	child->setPosition(aPos);
	child->SetSkeletalParent(this);
	mChildren.push_back(std::move(child));

}



void Hub::AttachSkin(float thick,sf::Texture* tex)
{
	float thickness = mRadius + thick;
	mSkin = new sf::CircleShape(thickness);
	mSkin->setOrigin(sf::Vector2f(thickness,thickness));
	//mSkin.setFillColor(sf::Color::White);
	mSkin->setTexture(tex,false);
	mSkin->setTextureRect(sf::IntRect(0, 0, 200, 200));
}