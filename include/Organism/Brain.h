#ifndef BRAIN_H
#define BRAIN_H

#include <Math/eMath.h>
class SkeletalComponent;
class Organism;
class Brain
{
public:
	Brain(Organism* organism);
	~Brain(void);
	void Update(float delta);
	
private:
	Organism* mOrganism;
	bool wasIPressed;
};
#endif

