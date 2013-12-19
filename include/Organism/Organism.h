#ifndef ORGANISM_H
#define ORGANISM_H

#include <Render/SceneNode.h>
#include <Box2D/Box2D.h>
#include<memory>
class Bodypart;
class BodypartDefinition;
class Organism : public SceneNode
{
    public:
        typedef std::unique_ptr<Organism> Ptr;
        Organism();
        virtual ~Organism();
        void Dummy(b2World& world);
		BodypartDefinition randDef();
		void UpdateSelf(float dt);
    protected:
    private:
		b2Joint* JoinBodyparts(b2JointDef& jDef);
};

#endif // ORGANISM_H
