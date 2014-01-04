#include "SkeletalPhysicsComponent.h"
#include "SkeletalComponent.h"

SkeletalPhysicsComponent::SkeletalPhysicsComponent(SkeletalComponent* parent)
{
	sComp = parent;
}





void SkeletalPhysicsComponent::Update(float delta)
{

	//Update all physics on SkeletalPhysicsComponent

}




SkeletalPhysicsComponent::~SkeletalPhysicsComponent(void)
{
}

void SkeletalPhysicsComponent::ApplyForce(float amount)
{
	mAngularSpeed+= amount;
}

void SkeletalPhysicsComponent::RecursiveApplyForce(float amount)
{
	ApplyForce(amount);
	/*for (const SkeletalPhysicsComponent::Ptr& node : mChildren)
    {
		float scalar = ((rand() % 30) +70) * .01f;
		node->RecursiveApplyForce(amount * scalar);
	}*/
}
void SkeletalPhysicsComponent::ApplyDrag(float delta)
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

