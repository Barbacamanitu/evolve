#ifndef ENTITY_H
#define ENTITY_H
#include <Render/SceneNode.h>
#include <SFML/Graphics.hpp>

class Entity : public SceneNode
{
    public:
        typedef std::unique_ptr<Entity> Ptr;
        Entity();
        virtual ~Entity();
        sf::RectangleShape rectangle;
    protected:
    private:
        void input();
        void updateSelf(float dt);
        void drawSelf(sf::RenderTarget& target, sf::RenderStates states, float interpolation);



};

#endif // ENTITY_H
