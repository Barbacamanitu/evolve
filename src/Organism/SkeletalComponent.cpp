#include "SkeletalComponent.h"

SkeletalComponent::SkeletalComponent()
{
    //ctor
	angularSpeed = 0;
	mDrag = 0.55f;
}

SkeletalComponent::~SkeletalComponent()
{
    //dtor
}

void SkeletalComponent::ApplyRotation(float amount)
{
	angularSpeed+= amount;
}



