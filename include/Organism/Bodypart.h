#ifndef BODYPART_H
#define BODYPART_H

#include <Render/SceneNode.h>
#include <memory>
#include "BodypartDefinition.h"
class b2Body;
class BodypartDefinition;
class JointDefinition;
/*

Abstract base class for Bodyparts.

*/


class Bodypart : public SceneNode
{
public:
	typedef std::unique_ptr<Bodypart> Ptr;
	Bodypart();
	virtual ~Bodypart(void);
	b2Body* mBody;
	void CreateChildren(BodypartDefinition bDef);
	void CreateChild(BodypartDefinition bDef);
	void AttachToParent(Bodypart* parent,JointDefinition jDef);

protected:
	sf::Drawable * visibleRepresentation;
private:
    void UpdateSelf(float delta){};
	void RenderSelf(sf::RenderTarget &target,Game &game,float interpolation);

};
#endif
