#ifndef JOINTDEFINITION_H
#define JOINTDEFINITION_H
#include <Math/eMath.h>
class JointDefinition
{
public:
	JointDefinition(void);
	~JointDefinition(void);

	void ChildAnchor(evolve::Vec2 anchor);
	evolve::Vec2 ChildAnchor(){
		return mChildAnchor;
	}

	void ParentAnchor(evolve::Vec2 anchor);
	evolve::Vec2 ParentAnchor(){
		return mParentAnchor;
	}

	void Constraints(evolve::Vec2 constraints);
	evolve::Vec2 Constraints(){
		return mConstraints;
	}




private:
	evolve::Vec2 mChildAnchor;
	evolve::Vec2 mParentAnchor;
	evolve::Vec2 mConstraints;
};
#endif
