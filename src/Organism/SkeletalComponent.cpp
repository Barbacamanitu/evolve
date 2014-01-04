#include "SkeletalComponent.h"
#include <Math/eMath.h>
#include <Render/RenderMath.h>
SkeletalComponent::SkeletalComponent()
{

	//Constants
	mMaxSpeed = 10.f;
	mDrag =1.2f;


    //Initialization
	mAngularSpeed = 0;	
	sParent = nullptr;
	
}

void SkeletalComponent::SetConstraints(evolve::Vec2 constraints)
{
	mConstraints = constraints;
}

evolve::Vec2 SkeletalComponent::GetConstraints()
{
	return mConstraints;
}

SkeletalComponent::~SkeletalComponent()
{
    //dtor
}

SkeletalComponent* SkeletalComponent::GetSkeletalParent() const
{
	return sParent;
}

void SkeletalComponent::SetSkeletalParent(SkeletalComponent* parent)
{
	sParent = parent;
	SetParent(parent);
}


SkeletalComponent* SkeletalComponent::GetChild(int index)
{
	
	SkeletalComponent* child = nullptr;
	if (mChildren.size() > 0)
	{
		child = mChildren[index].get();
	}
	return child;
}

int SkeletalComponent::ChildCount()
{
	return mChildren.size();
}

SkeletalComponent* SkeletalComponent::GetSkeletalComponentByID(int id)
{
	//Check self
	if (GetID() == id)
		return this;

	SkeletalComponent* sComp = nullptr;
	for (const SkeletalComponent::Ptr& child : mChildren)
	{
		sComp = child->GetSkeletalComponentByID(id);
		if (sComp != nullptr)
			return sComp;
	}
	return sComp;
	//Function will return nullptr if not found.
}


void SkeletalComponent::SetID(int id)
{
	mID = id;
}

int SkeletalComponent::GetID()
{
	return mID;
}


void SkeletalComponent::ApplyForce(float amount)
{
	mAngularSpeed+= amount;
}

void SkeletalComponent::RecursiveApplyForce(float amount)
{
	ApplyForce(amount);
	for (const SkeletalComponent::Ptr& node : mChildren)
    {
		float scalar = ((rand() % 30) +70) * .01f;
		node->RecursiveApplyForce(amount * scalar);
	}
}
void SkeletalComponent::ApplyDrag(float delta)
{
	
	//lower speed based on drag
	if (abs(mAngularSpeed) > 0.f)
	{
	//Apply drag
	mAngularSpeed -= (mDrag * mAngularSpeed) * delta;
	if (abs(mAngularSpeed) < 0.2f)
		mAngularSpeed = 0.f;
	}
}



void SkeletalComponent::RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{
	target.draw(*mSkin,states);
}

void SkeletalComponent::UpdateSpeed(float delta)
{
	
}

void SkeletalComponent::Update(float delta)
{
	pPosition = getPosition();
	pRotation = getRotation();

	//Apply any accelerations first
	

	
	RotateTowardsTarget(delta);

	CheckConstraints(delta);	
	UpdateSpeed(delta);
	UpdateChildren(delta);
	UpdateSelf(delta);
	rotate(delta * mAngularSpeed);
}

void SkeletalComponent::CheckConstraints(float delta)
{
	float newAngle = getRotation();
	newAngle +=  (mAngularSpeed * delta);
	if(!evolve::Geometry::IsAngleInRange(newAngle,mConstraints.X,mConstraints.Y))
		HitConstraint();
}

void SkeletalComponent::HitConstraint()
{
	//Send impulse to child
	if (mChildren.size() > 0)
	{
		mChildren[0]->RecursiveApplyForce(mAngularSpeed *.8f);
	}

	
	mAngularSpeed *= -.2f;
}

void SkeletalComponent::Stop(float speed)
{

}
void SkeletalComponent::RotateTowardsTarget(float delta)
{
	float distanceToAngle = evolve::Geometry::DistanceBetweenAngles(getRotation(),mTargetAngle);
	
	
		if (distanceToAngle > .5f)
		{

			//Find which way to rotate now.
			//If target is counter clockwise from current
			float cAng = getRotation();
			evolve::Geometry::MakeAnglePositive(cAng);
			evolve::Geometry::MakeAnglePositive(mTargetAngle);

			float accel = distanceToAngle * .5f;

			if (cAng > mTargetAngle)
				accel *= -1.f;

			//Apply accelleration
			rotate(accel);
		}

		
}

void SkeletalComponent::SetTargetAngle(float angle)
{
	mTargetAngle = angle;
}

void SkeletalComponent::SetOrganism(Organism* organism)
{
	mOrganism = organism;
	for (const SkeletalComponent::Ptr& child : mChildren)
	{
		child->SetOrganism(organism);
	}
};

void SkeletalComponent::SetAnglePercentage(float percentage)
{
	float range = mConstraints.Y - mConstraints.Y;
	float angle = mConstraints.X + (percentage * range);
	setRotation(angle);
}
