#include "Game.h"
#include "Player.h"
#define FPS 60
int main(int args, char* arvs[])
{

	Uint32 frameStart, frameTime, delayTime = 1000.0f / FPS;
	Game::Instance()->init("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	
	

	
	while (Game::Instance()->running())
	{
		frameStart = SDL_GetTicks();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < delayTime)
		{
			SDL_Delay((Uint32)delayTime - frameTime);
			Game::Instance()->update();
			Game::Instance()->render();
			Game::Instance()->handleEvents();
		}
	}
	Game::Instance()->clean();
	

	return 0;
}