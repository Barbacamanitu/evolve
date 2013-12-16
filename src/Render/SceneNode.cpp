#include "SceneNode.h"
#include <assert.h>

SceneNode::SceneNode(void)
{
}


SceneNode::~SceneNode(void)
{
}

void SceneNode::AttachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::DetachChild(const SceneNode& node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(),[&] (Ptr& p) -> bool { return p.get() == &node; });

    assert(found != mChildren.end());
	Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::Render(sf::RenderTarget &target,Game &game,float interpolation)
{
    RenderChildren(target,game,interpolation);
    RenderSelf(target,game,interpolation);
}

void SceneNode::RenderChildren(sf::RenderTarget &target,Game &game,float interpolation)
{
    for (const Ptr& node : mChildren)
    {
        node->Render(target,game,interpolation);
    }
}

void SceneNode::Update(float delta)
{
    UpdateChildren(delta);
    UpdateSelf(delta);
}

void SceneNode::UpdateChildren(float delta)
{
    for (const Ptr& node : mChildren)
    {
        node->Update(delta);
    }
}
