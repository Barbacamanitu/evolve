#ifndef ORGANISM_H
#define ORGANISM_H
#include <Render/SceneNode.h>
#include "SkeletalComponent.h"
#include <memory>
#include "Brain.h"
class Game;
class Organism : public SceneNode
{
public:
	Organism(void);
	~Organism(void);

	//Debug stuff

	sf::CircleShape marker;

	typedef std::unique_ptr<Organism> Ptr;
	void AttachSkeletalComponent(SkeletalComponent::Ptr child);
	std::vector<SkeletalComponent::Ptr>* GetSkeleton();
	SkeletalComponent* GetSkeletalComponentByID(int ID);
	Game* GetGame();
	void SetGame(Game* game);
private:
	void RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
	void RenderSkeleton(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation);
	void UpdateSkeleton(float delta);

	void UpdateSelf(float delta);
	sf::Vector2f mSize;
	void CalculateSize();
	std::vector<SkeletalComponent::Ptr> mSkeleton;
	std::unique_ptr<Brain> mBrain;
	Game* mGame;


	
};
#endif

