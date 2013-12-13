#ifndef SCENENODE_H
#define SCENENODE_H
#include <memory>
#include <SFML/Graphics.hpp>
class Game;
class SceneNode
{
public:
	SceneNode(void);
	~SceneNode(void);
	typedef std::unique_ptr<SceneNode> Ptr;
	virtual void Render(sf::RenderTarget &target,Game &game,float interpolation){};
	virtual void Update(float delta){};

	void AttachChild(Ptr child);
	Ptr  DetachChild(const SceneNode& node);

	//Public Fields
	std::vector<Ptr> mChildren;
	SceneNode*       mParent;

};
#endif

