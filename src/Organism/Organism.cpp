#include "Organism.h"
#include <Math/eMath.h>
#include "SkeletalComponent.h"
#include "Game.h"
Organism::Organism(void)
{
	mBrain.reset(new Brain(this));
	marker.setRadius(.3f);
	marker.setOrigin(.3f,.3f);
	marker.setFillColor(sf::Color::Cyan);

}


Organism::~Organism(void)
{
}

std::vector<SkeletalComponent::Ptr>* Organism::GetSkeleton()
{
	return &mSkeleton;
}

void Organism::SetGame(Game* game)
{
	mGame = game;
}
Game* Organism::GetGame()
{
	return mGame;
}
void Organism::RenderSelf(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{
	sf::CircleShape circ;
	circ.setFillColor(sf::Color::Red);
	circ.setRadius(1.f);
	circ.setOrigin(1.f,1.f);
	RenderSkeleton(target,states,game,interpolation);
	target.draw(circ,states);
	//target.draw(marker);

}

void Organism::RenderSkeleton(sf::RenderTarget &target, sf::RenderStates states,Game &game,float interpolation)
{
	for (SkeletalComponent::Ptr & sC : mSkeleton)
	{
		sC->Render(target,states,game,interpolation);
	}
}

void Organism::UpdateSkeleton(float delta)
{
	for (SkeletalComponent::Ptr & sC : mSkeleton)
	{
		sC->Update(delta);
	}
}

void Organism::AttachSkeletalComponent(SkeletalComponent::Ptr child)
{
	child->SetParent(this);
	mSkeleton.push_back(std::move(child));
}

void Organism::CalculateSize()
{
	//Traverse Children
	//Find theoretical min/max for x/y

	/*
		Psuedo-code:

		If Has Child, send current bounds to CheckBounds and assign returned value.
		Like this: Bounds = Child->CheckBounds(Bounds);

		Child should take these bounds and push itself to its limits to see if it can extend the bounds.
		if it can, update the bounds. Then, check any of its children to see if they can extend the bounds by calling
		Bounds = Child->CheckBounds. Finally, return the extended bounds to the organism.

		Outline of CheckBounds:
		Push self to limits
		Extend if possible
		Check children
		return.

		*/
/*
	for (int i = 0; i < mChildren.size(); i++)
	{
		mChildren[i]->ExtendSize(mSize,getWorldPosition(),0.f);
		mChildren[i]->ExtendSize(mSize,getWorldPosition(),90.f);
		mChildren[i]->ExtendSize(mSize,getWorldPosition(),180.f);
		mChildren[i]->ExtendSize(mSize,getWorldPosition(),280.f);
	}*/
}

void Organism::UpdateSelf(float delta)
{
	
	
	mBrain->Update(delta);
	float speed = 10;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move(sf::Vector2f(-speed,0) * delta);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		move(sf::Vector2f(0,-speed) * delta);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		move(sf::Vector2f(0,speed) * delta);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move(sf::Vector2f(speed,0) * delta);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		rotate(50.f * delta);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		rotate(-50.f * delta);
	}
	UpdateSkeleton(delta);
}

SkeletalComponent* Organism::GetSkeletalComponentByID(int ID)
{

	SkeletalComponent* sComp = nullptr;
	for (const SkeletalComponent::Ptr& child : mSkeleton)
	{
		sComp = child->GetSkeletalComponentByID(ID);
		if (sComp != nullptr)
			return sComp;
	}
	return sComp;

}