#ifndef BONE_H
#define BONE_H

#include "SkeletalComponent.h"
#include <Math/eMath.h>
class Hub;
class Bone : public SkeletalComponent
{
    public:
		bool canControl;
		typedef std::unique_ptr<Bone> Ptr;
        Bone(float length, float lowerConstraint, float upperConstraint);
        virtual ~Bone();
		void AttachSkeletalComponent(SkeletalComponent::Ptr child);
		void AttachSkin(float thickness,sf::Texture* tex);
		void UpdateSelf(float delta);
		evolve::Vec2 GetEndpoint();
		evolve::Vec2 GetEndpoint(const sf::Transform& worldTrans);

		float AngleClosestToPoint(evolve::Vec2 target);
    protected:
    private:
        float mLength;
        sf::RectangleShape debugRect;
        sf::CircleShape debugCirc;
		void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);


		

		//sf::ConvexShape mSkin;
};

#endif // BONE_H
