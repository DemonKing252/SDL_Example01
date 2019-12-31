#include "Game.h"
#include "Player.h"
#define FPS 60
int main(int args, char* arvs[])
{

	Uint32 frameStart, frameTime, delayTime = 1000.0f / FPS;
	Game::Instance()->init("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	
	SDL_Texture* pTexture = IMG_LoadTexture(Game::Instance()->getRenderer(), "Assets/Player.png");

	Player player(pTexture, 1024 / 2, 768 / 2);
	
	while (Game::Instance()->running())
	{
		frameStart = SDL_GetTicks();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < delayTime)
		{
			SDL_Delay((Uint32)delayTime - frameTime);
			Game::Instance()->update(player);
			Game::Instance()->render(player);
			Game::Instance()->handleEvents();
		}
	}
	Game::Instance()->clean();
	

	return 0;
}