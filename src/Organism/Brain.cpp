#include "Brain.h"
#include "Organism.h"
#include "SkeletalComponent.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <ctime>
#include <Math/IK/CCDSolver.h>
Brain::Brain(Organism* organism)
{
	mOrganism = organism;
}


Brain::~Brain(void)
{
}


void Brain::Update(float delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		//Only happens once
		int effectorID = 301;

		SkeletalComponent * effector = mOrganism->GetSkeletalComponentByID(effectorID);
		if (effector!= nullptr)
		{
			CCDSolver::Solve(effector,mOrganism->GetGame()->GetMouseWorldPosition());
		}
	}
	wasIPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::I);
}

