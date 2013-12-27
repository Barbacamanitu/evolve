#ifndef SKELETALCOMPONENT_H
#define SKELETALCOMPONENT_H
#include  <SFML/Graphics.hpp>
#include <Render/SceneNode.h>
#include <memory>

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
		virtual void AttachSkin(float thickness){};
		void ApplyRotation(float amount);
		std::vector<SkeletalComponent::Ptr> mChildren;

    protected:
		float angularSpeed;
		float mLowerConstraint;
		float mUpperConstraint;
		float mDrag;
    private:

		

};

#endif // SKELETALCOMPONENT_H
