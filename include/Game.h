#ifndef GAME_H
#define GAME_H

#include <Timing/Timestep.h>
#include <SFML/Graphics.hpp>
#include <Debug/DebugInfo.h>
#include <Render/SceneNode.h>

class Game
{
    public:
        Game();
        virtual ~Game();

        void createWindow();
        void mainLoop();
        void update(const float dt);
        void render(const float alpha);
    protected:
    private:
        sf::RenderWindow gameWindow;
        Timestep mTimestep;
        void processEvents();
        DebugInfo debugInfo;
        SceneNode graph;



};

#endif // GAME_H
