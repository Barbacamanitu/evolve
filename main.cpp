#include <Game.h>
int main()
{
	srand(time(0));
    Game game;
	game.createWorld();
    game.createWindow();
    game.mainLoop();
    return 0;
}
