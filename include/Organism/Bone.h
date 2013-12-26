#ifndef BONE_H
#define BONE_H

#include "SkeletalComponent.h"
#include <Math/eMath.h>
#include <memory>
class Bone : public SkeletalComponent
{
    public:
        Bone(float length, float rotation, evolve::Vec2 constraints);
        virtual ~Bone();

        /*

            Bone derives from SkeletalComponent.

            Bone has the following properties:
                - Length
                - Constraints

        */
    protected:
    private:
        void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
        float mLength;
        float mRotation;
        evolve::Vec2 mConstraints;
        sf::RectangleShape debugRect;
        sf::CircleShape debugCirc;
};

#endif // BONE_H
