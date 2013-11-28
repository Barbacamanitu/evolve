#include "SceneNode.h"
#include <assert.h>
#include <Render/RenderMath.h>

SceneNode::SceneNode()
{
    //ctor
    mParent = nullptr;
}

SceneNode::~SceneNode()
{
    //dtor
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states, float interpolation)
{

        states.transform *= getInterpolatedTransform(interpolation);

    //states.transform *= getTransform();

    if  (drawChildrenFirst)
    {
        drawChildren(target, states,interpolation);
        drawSelf(target,states,interpolation);
    }
    else
    {
        drawSelf(target, states, interpolation);
        drawChildren(target, states ,interpolation);
    }
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states, float interpolation)
{
    for (const Ptr &child : mChildren)
    {
        child->draw(target,states,interpolation);
    }
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node)
{
    auto found = std::find_if(
        mChildren.begin(), mChildren.end(),[&] (Ptr&p) ->bool { return p.get() == &node; });
        assert(found != mChildren.end());
        Ptr result = std::move(*found);
        result->mParent = nullptr;
        mChildren.erase(found);
        return result;
}

void SceneNode::attachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}


void SceneNode::update(float dt)
{
    updateWorldTransform();
    updateSelf(dt);
    updateChildren(dt);
}

void SceneNode::updateChildren(float dt)
{
    for (Ptr & child : mChildren)
    {
        child->update(dt);
    }
}

sf::Transform SceneNode::getWorldTransform() const
{
  sf::Transform transform = sf::Transform::Identity;

for (const SceneNode* node = this;node != nullptr; node = node->mParent)
transform = node->getTransform() * transform;

return transform;
}

sf::Transform SceneNode::getInterpolatedTransform(float interpolation)
{
    return RenderMath::InterpolateTransforms(previousLocalTransform.getPosition(),getPosition(),previousLocalTransform.getRotation(),getRotation(),previousLocalTransform.getScale(),getScale(),interpolation);
}

void SceneNode::updateWorldTransform()
{
   // if (getTransform() != previousLocalTransform)
   previousLocalTransform.setRotation(getRotation());
   previousLocalTransform.setPosition(getPosition());
   previousLocalTransform.setScale(getScale());
}

sf::Vector2f SceneNode::getWorldPosition() const
{
return getWorldTransform() * sf::Vector2f();
}
