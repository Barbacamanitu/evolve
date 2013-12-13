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
