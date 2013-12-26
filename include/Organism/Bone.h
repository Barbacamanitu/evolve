#ifndef BONE_H
#define BONE_H

#include "SkeletalComponent.h"
#include <Math/eMath.h>
#include <memory>
class Bone : public SkeletalComponent
{
    public:
		typedef std::unique_ptr<Bone> Ptr;
        Bone(float length, float centerAngle, float range);
        virtual ~Bone();

        /*

            Bone derives from SkeletalComponent.

            Bone has the following properties:
                - Length
                - Constraints

        */
		void AttachSkeletalComponent(SkeletalComponent::Ptr child);
		void ApplyRotation(float amount);
		void SetConstraints(float centerAngle, float range);
		float GetRange();
		SkeletalComponent* mParent;
		void AttachSkin(float thickness,sf::Texture* tex);
		sf::FloatRect getBoundingRect() const;
    protected:
    private:
        float mLength;
        float mRotation;
        float mCenterAngle;
		float mRange;
        sf::RectangleShape debugRect;
        sf::CircleShape debugCirc;
		void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
		void UpdateSelf(float delta);
		float angularSpeed;
		float drag;
		sf::ConvexShape mSkin;

};

#endif // BONE_H
