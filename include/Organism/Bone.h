#ifndef BONE_H
#define BONE_H

#include "SkeletalComponent.h"
#include <Math/eMath.h>
#include <memory>
class Bone : public SkeletalComponent
{
    public:
		typedef std::unique_ptr<Bone> Ptr;
        Bone(float length, float lowerConstraint, float upperConstraint);
        virtual ~Bone();

        /*

            Bone derives from SkeletalComponent.

            Bone has the following properties:
                - Length
                - Constraints

        */
		void SetShading(float amount);
		void AttachSkeletalComponent(SkeletalComponent::Ptr child);
		void SetConstraints(float centerAngle, float range);
		SkeletalComponent* mParent;
		void AttachSkin(float thickness,sf::Texture* tex);
		sf::FloatRect getBoundingRect() const;
    protected:
    private:
        float mLength;

        sf::RectangleShape debugRect;
        sf::CircleShape debugCirc;
		void CheckConstraints(float delta);
		void HitConstraint();
		void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
		void UpdateSelf(float delta);

		sf::ConvexShape mSkin;

};

#endif // BONE_H
