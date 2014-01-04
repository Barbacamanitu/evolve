#ifndef SKELETALPHYSICSCOMPONENT_H
#define SKELETALPHYSICSCOMPONENT_H
class SkeletalComponent;
class SkeletalPhysicsComponent
{
public:
	SkeletalPhysicsComponent(SkeletalComponent* parent);
	~SkeletalPhysicsComponent(void);
	void Update(float delta);


	void ApplyForce(float amount);
	void RecursiveApplyForce(float amount);
	void SetTargetAngle(float angle);
private:
	SkeletalComponent* sComp;

	void ApplyDrag(float delta);
	void CheckConstraints(float delta);
	void HitConstraint();
	void RotateTowardsTarget(float delta);
	void Stop(float speed);
	void UpdateSpeed(float delta);

	//Private Data Members
	float mMaxSpeed;		
	float mTargetAngle;
	float mAngularSpeed;
	float mDrag;
};
#endif
