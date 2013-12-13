#include <Game.h>
int main()
{
    Game game;
	game.createWorld();
    game.createWindow();
    game.mainLoop();
    return 0;
}
