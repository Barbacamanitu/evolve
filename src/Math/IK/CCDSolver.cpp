#include "CCDSolver.h"
#include <Organism/SkeletalComponent.h>
#include <Organism/Organism.h>
void CCDSolver::Solve(SkeletalComponent* effector,evolve::Vec2 targetPos)
{
	AngleMap mAngles;
	//Fill initial transforms
	
	for (SkeletalComponent* node = effector; node != nullptr; node = node->GetSkeletalParent())
	{
		//Node is the current skeletal node
		mAngles[node].initialAngle = node->getRotation();
	}

	//Initial Angles Saved.
	IKLoop(effector,targetPos,mAngles);	
}

void CCDSolver::IKLoop(SkeletalComponent* effector,evolve::Vec2 targetPos,AngleMap& angleMap)
{
	const double closeEnough = .5f;


	for (SkeletalComponent* node = effector; node != nullptr; node = node->GetSkeletalParent())
	{
		
		//Find offset between effector and target.
		evolve::Vec2 endPos = effector->GetEndpoint();
		if (endPos.DistanceTo(targetPos) < closeEnough)
			return;
		//Find ideal angle for the current node

		//First, Get angle to the effector
		//Second, Get Angle to Target
		//See how much movement it would take to move one angle to the other.
		evolve::Vec2 nPos = node->getWorldPosition();

		evolve::Vec2 effVec = endPos - nPos;
		evolve::Vec2 tarVec = targetPos - nPos;
		
		effVec.Normalize();
		tarVec.Normalize();

		double effAngle = effVec.ToRadians();
		double tarAngle = tarVec.ToRadians();
		double rotAng = effAngle - tarAngle;
		rotAng = evolve::Geometry::SimplifyAngle(rotAng);
		double degrees = evolve::Conversions::RadiansToDegrees(rotAng);
		double targetAngle = node->getRotation() + degrees;
		evolve::Vec2 constraints = node->GetConstraints();
		double newTarget = evolve::Geometry::GetClosestAngle(targetAngle,constraints.X,constraints.Y);
		node->SetTargetAngle(newTarget);

	}
}

