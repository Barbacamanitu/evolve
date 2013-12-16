#ifndef BODYPART_H
#define BODYPART_H

#include<SceneNode.h>
#include<memory>
#include <SFML/Graphics.hpp>
class b2Body;
class b2World;
class Organism;
class b2Vec2;
class Bodypart : public SceneNode
{


public:
    struct BodypartProperties
    {
        int shape = 0;
        float width = 0;
        float height = 0;
        float radius = 0;
        float angle = 0;
        float x = 0;
        float y = 0;
        float density = 1.f;
        sf::Color color = sf::Color::Cyan;

    };
    typedef std::unique_ptr<Bodypart> Ptr;
    Bodypart();
	~Bodypart(void);
	b2Body* mBody;
	static Ptr Create(Bodypart::BodypartProperties properties, b2World& world);
	void AttachBodypart(b2Body* bodypart, b2Vec2& jointPos);

	std::unique_ptr<sf::Drawable> visibleRepresentation;

private:
    void RenderSelf(sf::RenderTarget &target,Game &game,float interpolation);
    void UpdateSelf(float delta){};


};
#endif
