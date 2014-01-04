#ifndef GAME_H
#define GAME_H

#include <Timing/Timestep.h>
#include <SFML/Graphics.hpp>
#include <Debug/DebugInfo.h>
//#include <Render/SceneNode.h>
#include <Box2D/Box2D.h>
#include <SceneNode.h>
#include <Bone.h>
class Game
{
    public:
        Game();
        virtual ~Game();

        void createWindow();
        void mainLoop();
        void update(const float dt);
        void render(const float alpha);
		void createWorld();
		Bone* newBone;
		sf::Texture* skinTexture;
		sf::RenderWindow* GetWindow();
		evolve::Vec2 GetMouseWorldPosition();
    protected:
    private:
        sf::RenderWindow gameWindow;
        Timestep mTimestep;
        void processEvents();
        DebugInfo debugInfo;
		sf::Vector2i oldMouse;
		sf::View mainView;
        SceneNode * SceneGraph;


};

#endif // GAME_H
