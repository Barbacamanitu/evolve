#ifndef HUB_H
#define HUB_H

#include <SkeletalComponent.h>


class Hub : public SkeletalComponent
{
    public:
        Hub();
        virtual ~Hub();

        void debugDraw(sf::RenderTarget & target, sf::RenderStates states) const;
    protected:
    private:
};

#endif // HUB_H
