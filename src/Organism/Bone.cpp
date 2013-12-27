#include "Bone.h"
#include <Game.h>
#include <Math/eMath.h>
#include <Render/RenderMath.h>
Bone::Bone(float length, float lowerConstraint, float upperConstraint)
{
    //ctor
    mLength = length;
	mLowerConstraint = lowerConstraint;
	mUpperConstraint = upperConstraint;
    debugRect.setSize(sf::Vector2f(mLength,0.1f));
    debugRect.setOrigin(sf::Vector2f(0.f,.05f));
    debugRect.setFillColor(sf::Color::White);



    float dcRadius = .2f;
    debugCirc.setRadius(dcRadius);
    debugCirc.setFillColor(sf::Color::Green);
    debugCirc.setOrigin(sf::Vector2f(dcRadius,dcRadius));
	setRotation(evolve::Geometry::InterpolateAngles(lowerConstraint,upperConstraint,.5f));
}

void Bone::SetShading(float amount)
{
	sf::Color shade = sf::Color::Black;
	shade.a = amount;
	mSkin.setFillColor(shade);
}

void Bone::SetConstraints(float lowerConstraint, float upperConstraint)
{
	mLowerConstraint = lowerConstraint;
	mUpperConstraint = upperConstraint;
}

void Bone::AttachSkeletalComponent(SkeletalComponent::Ptr child)
{
	//Attach at the correct point.
	float rot = child->getRotation();
	child->setPosition(mLength,0.f);
	child->setRotation(rot);

	AttachChild(std::move(child));
}


Bone::~Bone()
{
    //dtor
}

sf::FloatRect Bone::getBoundingRect() const
{
    return getWorldTransform()
		.transformRect(mSkin.getGlobalBounds());
}

void Bone::RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{

	target.draw(mSkin,states);


		
	sf::FloatRect fR = getBoundingRect();
	sf::RectangleShape aabb(sf::Vector2f(fR.width,fR.height));
	aabb.setPosition(fR.left,fR.top);
	aabb.setFillColor(sf::Color::Transparent);
	aabb.setOutlineColor(sf::Color::Green);
	aabb.setOutlineThickness(.1f);
	
	/*
	target.draw(debugRect,states);
	target.draw(debugCirc,states);
	target.draw(aabb,sf::RenderStates());*/
}

void Bone::UpdateSelf(float delta)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		ApplyRotation(((rand() % 200) - 100) * 10.f);
	}

	if (angularSpeed > 100)
		angularSpeed = 100;
	if (angularSpeed < -100)
		angularSpeed = -100;



	if (abs(angularSpeed) > 0)
	{
	//Apply drag
	angularSpeed -= (mDrag * angularSpeed) * delta;
	if (abs(angularSpeed) < 0.2f)
		angularSpeed = 0.f;
	}
	CheckConstraints(delta);
	rotate(angularSpeed * delta);
}



void Bone::AttachSkin(float thickness,sf::Texture* tex)
{
	mSkin = RenderMath::CreateBoneShape(mLength,thickness);
	//mSkin.setFillColor(sf::Color::White);
	mSkin.setTexture(tex,false);
	mSkin.setTextureRect(sf::IntRect(0, 0, 200, 200));
}

void Bone::CheckConstraints(float delta)
{
	//Check if current angle is within constraints
	//Range is the distance from the centerAngle that each joint is allowed to move
	float newAngle = getRotation();
	newAngle +=  (angularSpeed * delta);
	if(!evolve::Geometry::IsAngleInRange(newAngle,mLowerConstraint,mUpperConstraint))
		HitConstraint();
}

void Bone::HitConstraint()
{
	angularSpeed *= -.3f;
	if (mChildren.size() > 0)
	{
		mChildren[0]->ApplyRotation(angularSpeed * -50.3f);
	}
		
}