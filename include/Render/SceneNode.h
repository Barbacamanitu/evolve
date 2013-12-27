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
	void Render(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
	void Update(float delta);
	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;
	void AttachChild(Ptr child);
	Ptr  DetachChild(const SceneNode& node);
	sf::FloatRect getBoundingRect() const;
	//Public Fields
	std::vector<Ptr> mChildren;
	SceneNode*       mParent;
protected:
    virtual void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation){};
    virtual void UpdateSelf(float delta){};

private:
    void RenderChildren(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
    void UpdateChildren(float delta);
	sf::Vector2f pPosition;
	float pRotation;

};
#endif

