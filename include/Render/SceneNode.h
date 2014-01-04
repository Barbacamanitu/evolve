#ifndef SCENENODE_H
#define SCENENODE_H
#include <memory>
#include <SFML/Graphics.hpp>
class Game;
class SceneNode : public sf::Transformable
{

public:
	SceneNode(void);
	~SceneNode(void);
	typedef std::unique_ptr<SceneNode> Ptr;
	virtual void Render(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
	virtual void Update(float delta);
	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;
	virtual SceneNode* GetChild(int index);
	virtual int ChildCount();
	void AttachChild(Ptr child);
	Ptr  DetachChild(const SceneNode& node);

	//Public Fields
	SceneNode* GetParent() const;
	virtual void SetParent(SceneNode* parent);

	sf::FloatRect getBoundingRect() const;
protected:
    virtual void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation){};
    virtual void UpdateSelf(float delta){};
	virtual void RenderChildren(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
	virtual void UpdateChildren(float delta);
	sf::Vector2f pPosition;
	float pRotation;
	SceneNode*       mParent;

private:

	std::vector<Ptr> mChildren;

};
#endif

