#include <Render/SceneNode.h>
#include <assert.h>

SceneNode::SceneNode(void)
{
	mParent = nullptr;
}


SceneNode::~SceneNode(void)
{
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for (const SceneNode* node = this;node != nullptr; node = node->mParent)
    transform = node->getTransform() * transform;

  return transform;
}

sf::FloatRect SceneNode::getBoundingRect() const
{
    return sf::FloatRect(0.f,0.f,0.f,0.f);
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
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

void SceneNode::Render(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{

    states.transform *= getTransform();
    RenderChildren(target,states,game,interpolation);
    RenderSelf(target,states,game,interpolation);
}

void SceneNode::RenderChildren(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{
    for (const Ptr& node : mChildren)
    {
        node->Render(target,states,game,interpolation);
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
