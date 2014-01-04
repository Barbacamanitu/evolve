#ifndef CCDSOLVER_H
#define CCDSOLVER_H
#include <Math/eMath.h>
class SkeletalComponent;
class CCDSolver
{
public:

	struct AnglePair
	{
		double initialAngle;
		double optimizedAngle;
	};

	typedef std::map<SkeletalComponent*,AnglePair> AngleMap;
	static void Solve(SkeletalComponent* effector,evolve::Vec2 targetPos);
	static void IKLoop(SkeletalComponent* effector,evolve::Vec2 targetPos,AngleMap& angleMap);
private:


	
   
};
#endif

