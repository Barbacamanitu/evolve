#ifndef ORGANISM_H
#define ORGANISM_H

#include <Render/SceneNode.h>
#include <Box2D/Box2D.h>
#include<memory>

class Organism : public SceneNode
{
    public:
        typedef std::unique_ptr<Organism> Ptr;
        Organism();
        virtual ~Organism();
        void Dummy(b2World& world);
    protected:
    private:
};

#endif // ORGANISM_H
