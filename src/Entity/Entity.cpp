#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{
    //dtor
}

void Entity::drawSelf(sf::RenderTarget& target, sf::RenderStates states, float interpolation)
{
    target.draw(rectangle,states);
}

void Entity::updateSelf(float dt)
{
    int speed = 500;
    float sp = speed * dt;
    if (canControl)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            move(-sp,0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            move(sp,0);
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            move(0,-sp);
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            move(0,sp);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            rotate(100.f * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            scale(1.1f,1.1f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            scale(0.9f,0.9f);
       // if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
            //isInterpolating = !isInterpolating;


    }

}
