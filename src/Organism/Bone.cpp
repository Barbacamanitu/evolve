#include "Bone.h"
#include <Game.h>
#include <Math/eMath.h>
#include <Render/RenderMath.h>
#include "Hub.h"
Bone::Bone(float length, float lowerConstraint, float upperConstraint)
{
	canControl = false;
    //ctor
    mLength = length;
	SetConstraints(evolve::Vec2(lowerConstraint,upperConstraint));
	setRotation(evolve::Geometry::InterpolateAngles(lowerConstraint,upperConstraint,.5f));
    debugRect.setSize(sf::Vector2f(mLength,0.1f));
    debugRect.setOrigin(sf::Vector2f(0.f,.05f));
    debugRect.setFillColor(sf::Color::White);



    float dcRadius = .2f;
    debugCirc.setRadius(dcRadius);
    debugCirc.setFillColor(sf::Color::Green);
    debugCirc.setOrigin(sf::Vector2f(dcRadius,dcRadius));
	
}
float Bone::AngleClosestToPoint(evolve::Vec2 target)
{
	evolve::Vec2 endPoint = GetEndpoint();
	evolve::Vec2 curToTar = target - endPoint;
return 0;
}

evolve::Vec2 Bone::GetEndpoint()
{
	sf::Transform m = getWorldTransform();
	sf::Vector2f mm = m.translate(mLength,0) * sf::Vector2f();
	return evolve::Vec2(mm);
}

evolve::Vec2 Bone::GetEndpoint(const sf::Transform& worldTrans)
{
	sf::Transform m = worldTrans;
	sf::Vector2f mm = m.translate(mLength,0) * sf::Vector2f();
	return evolve::Vec2(mm);
}






void Bone::RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{
	target.draw(*mSkin,states);
	debugCirc.setPosition(GetEndpoint().toSFML());
	//target.draw(debugCirc);
}

void Bone::AttachSkeletalComponent(SkeletalComponent::Ptr child)
{
	float oldRotation = getRotation();
	setRotation(0);
	child->move(mLength,0);
	setRotation(oldRotation);
	mChildren.clear();
	child->SetSkeletalParent(this);
	mChildren.push_back(std::move(child));
}


Bone::~Bone()
{
    //dtor
}


void Bone::UpdateSelf(float delta)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && canControl)
	{
		float force = (rand() % 600) + 300;
		if (rand() % 10 > 5)
			force *= -1.f;
		ApplyForce(force);
	}
	
}



void Bone::AttachSkin(float thickness,sf::Texture* tex)
{
	mSkin = new sf::ConvexShape(RenderMath::CreateBoneShape(mLength,thickness));
	//mSkin.setFillColor(sf::Color::White);
	mSkin->setTexture(tex,false);
	mSkin->setTextureRect(sf::IntRect(0, 0, 200, 200));
}



