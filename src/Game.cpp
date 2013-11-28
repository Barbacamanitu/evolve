#include "Game.h"
#include <Entity/Entity.h>
Game::Game()
{
    //ctors
}

Game::~Game()
{
    //dtor
}

void Game::createWindow()
{
    gameWindow.create(sf::VideoMode(1280, 720), "SFML window");
    gameWindow.setVerticalSyncEnabled(false);


    Entity::Ptr mainEntity(new Entity());
    mainEntity->canControl = true;
    sf::Vector2f mSize(50.f,50.f);
    sf::Vector2f xSize(20.f,20.f);

    sf::RectangleShape mRect(mSize);
    sf::RectangleShape xRect(xSize);

    mRect.setOrigin(mSize/2.f);
    xRect.setOrigin(xSize/2.f);

    mRect.setFillColor(sf::Color::Cyan);
    xRect.setFillColor(sf::Color::Red);

    mainEntity->rectangle = mRect;

    Entity::Ptr xEntity(new Entity());
    xEntity->rectangle = xRect;

    xEntity->move(50.f,50.f);
    mainEntity->attachChild(std::move(xEntity));
    graph.attachChild(std::move(mainEntity));
    graph.move(gameWindow.getDefaultView().getCenter());
}

void Game::mainLoop()
{
    while (gameWindow.isOpen())
    {
        //Game Loop
        mTimestep.startLoop();

        processEvents();

        while(mTimestep.canUpdate())
            update(mTimestep.TIMESTEP);

        render(mTimestep.getAlpha());

        //End Game Loop
    }
}

void Game::render(const float alpha)
{
    gameWindow.clear();
    sf::RenderStates states;
    gameWindow.draw(debugInfo);
    graph.draw(gameWindow,states,alpha);
    gameWindow.display();
    debugInfo.updateFPS();

}

void Game::update(const float dt)
{
    debugInfo.update(gameWindow);
    graph.update(dt);

}



void Game::processEvents()
{
     sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                gameWindow.close();
            }
            if (event.type == sf::Event::EventType::KeyPressed)
            {

            }
        }
}
