#include "JointDefinition.h"


JointDefinition::JointDefinition(void)
{
}


JointDefinition::~JointDefinition(void)
{
}

void JointDefinition::ChildAnchor(evolve::Vec2 anchor)
{
	mChildAnchor = anchor;
}

void JointDefinition::ParentAnchor(evolve::Vec2 anchor)
{
	mParentAnchor = anchor;
}

void JointDefinition::Constraints(evolve::Vec2 constraints)
{
	/*
		X is small value
		Y is large value
	*/
	mConstraints = constraints;

}
