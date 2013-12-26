#include "Bone.h"
#include <Render/RenderMath.h>
#include <Game.h>
Bone::Bone(float length, float centerAngle, float range)
{
    //ctor
    mLength = length;
    mCenterAngle = centerAngle;
	mRange = range;
	angularSpeed = 0;
	drag = 0.8f;
    debugRect.setSize(sf::Vector2f(mLength,1.f));
    debugRect.setOrigin(sf::Vector2f(0.f,.5f));
    debugRect.setFillColor(sf::Color::White);



    float dcRadius = .75f;
    debugCirc.setRadius(dcRadius);
    debugCirc.setFillColor(sf::Color::Green);
    debugCirc.setOrigin(sf::Vector2f(dcRadius,dcRadius));
}

float Bone::GetRange()
{
	return mRange;
}

void Bone::SetConstraints(float centerAngle, float range)
{
	mCenterAngle = centerAngle;
	mRange = range;
}

void Bone::AttachSkeletalComponent(SceneNode::Ptr child)
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
	target.draw(debugRect,states);
	target.draw(debugCirc,states);
	target.draw(mSkin,states);
	
	
	
	sf::FloatRect fR = getBoundingRect();
	sf::RectangleShape aabb(sf::Vector2f(fR.width,fR.height));
	aabb.setPosition(fR.left,fR.top);
	aabb.setFillColor(sf::Color::Transparent);
	aabb.setOutlineColor(sf::Color::Green);
	aabb.setOutlineThickness(.1f);
	
	//target.draw(aabb,sf::RenderStates());
}

void Bone::UpdateSelf(float delta)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		ApplyRotation((rand() % 200) - 100);
	}

	if (angularSpeed > 100)
		angularSpeed = 100;
	if (angularSpeed < -100)
		angularSpeed = -100;



	if (abs(angularSpeed) > 0)
	{
	//Apply drag
	angularSpeed -= (drag * angularSpeed) * delta;
	if (abs(angularSpeed) < 0.2f)
		angularSpeed = 0.f;


	//Check for constraints
	float oldRotation = getRotation();
	rotate(angularSpeed * delta);
	float newRotation = getRotation();

	float d = fmod(abs(newRotation - mCenterAngle),360.f);
    float r = d > 180 ? 360 - d : d;
	if (r > mRange)
	{
		setRotation(oldRotation);
		angularSpeed *= -.1f * mLength;
		rotate(angularSpeed * delta);
	}
	}
}

void Bone::ApplyRotation(float amount)
{
	angularSpeed+= amount;
}

void Bone::AttachSkin(float thickness,sf::Texture* tex)
{
	mSkin = RenderMath::CreateBoneShape(mLength,thickness);
	//mSkin.setFillColor(sf::Color::White);
	
	mSkin.setTexture(tex,false);
	mSkin.setTextureRect(sf::IntRect(0, 0, 200, 200));
}