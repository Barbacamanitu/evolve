#ifndef HUB_H
#define HUB_H

#include <SkeletalComponent.h>
#include <SFML/Graphics.hpp>
#include "Bone.h"

class Hub : public SkeletalComponent
{
    public:
		typedef std::unique_ptr<Hub> Ptr;
        Hub(float radius);
        virtual ~Hub();
		void AttachBone(Bone::Ptr child,float pos);


    protected:
    private:
		sf::CircleShape debugCirc;
		void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
		float mRadius;

};

#endif // HUB_H
