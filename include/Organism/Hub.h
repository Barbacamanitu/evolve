#ifndef HUB_H
#define HUB_H

#include <SkeletalComponent.h>
#include <SFML/Graphics.hpp>
class Bone;

class Hub : public SkeletalComponent
{
    public:
		typedef std::unique_ptr<Hub> Ptr;
        Hub(float radius, float lowerConstraint, float upperConstraint);
        virtual ~Hub();
		void AttachBone(std::unique_ptr<Bone> child,float pos);
		void AttachSkin(float radius,sf::Texture* tex);
    protected:
    private:
		sf::CircleShape debugCirc;
		void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
		float mRadius;
};

#endif // HUB_H
