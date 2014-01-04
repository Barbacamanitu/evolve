#ifndef SKELETALCOMPONENT_H
#define SKELETALCOMPONENT_H
#include  <SFML/Graphics.hpp>
#include <Math/eMath.h>
#include <memory>
#include <Render/SceneNode.h>
class Game;
class Organism;
class SkeletalComponent : public SceneNode
/*
    SkeletalComponent derives from SceneNode to simplify DebugDrawing.
    Should only be drawn for debug purposes.

    SkeletalComponent is an abstract base class
    that Bone and Hub derive from. It provides
    the basic functions for debug drawing and allows
    for polymorphism.

    SkeletalComponent keeps a pointer to its parent. Each
    SkeletalComponent will only have a single parent, but Hubs
    may have multiple children.


    Debug Draw Mode:
    SkeletalComponent is capable of drawing itself for debug mode.
    DebugDraw will draw the current SkeletalComponent and all child
    SkeletalComponents.


*/



{
    public:
		typedef std::unique_ptr<SkeletalComponent> Ptr;
        SkeletalComponent();
        virtual ~SkeletalComponent();
		
		void SetConstraints(evolve::Vec2 constraints);

		void SetSkeletalParent(SkeletalComponent* parent);
		SkeletalComponent* GetSkeletalParent() const;

		virtual void AttachSkin(float thickness){};

		void Update(float delta);
		
		Organism* GetOrganism()
		{
			return mOrganism;
		}
		void SetOrganism(Organism* organism);

		
		
		SkeletalComponent* GetChild(int index);
		int ChildCount();

		void SetID(int id);
		int GetID();
		SkeletalComponent* GetSkeletalComponentByID(int id);

		void ApplyForce(float amount);
		void RecursiveApplyForce(float amount);
		void SetTargetAngle(float angle);
		void SetAnglePercentage(float percentage);

		virtual evolve::Vec2 GetEndpoint(){return evolve::Vec2(getWorldPosition());};
		virtual evolve::Vec2 GetEndpoint(const sf::Transform& worldTrans){return worldTrans * sf::Vector2f();};
		evolve::Vec2 GetConstraints();
		
    protected:
		void ApplyDrag(float delta);
		void CheckConstraints(float delta);
		void HitConstraint();
		float mDrag;
		sf::Shape * mSkin;
		std::vector<SkeletalComponent::Ptr> mChildren;
		SkeletalComponent* sParent;
		virtual void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);

private:
		
	//Rotation Related Methods
	void RotateTowardsTarget(float delta);
	void Stop(float speed);
	void UpdateSpeed(float delta);


	//Private Data Members
	int mID;
	float mMaxSpeed;		
	float mTargetAngle;
	float mAngularSpeed;
	

	evolve::Vec2 mConstraints;	
	Organism* mOrganism;
		
};

#endif // SKELETALCOMPONENT_H
