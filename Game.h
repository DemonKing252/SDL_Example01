#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Player.h"
#include "TextureManager.h"
using namespace std;
class Game
{
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	bool m_bRunning;	//	Keep the game running
public:
	SDL_Renderer* getRenderer();
	bool running();
	bool init(const char*, int, int, int, int, int);
	void update();
	void render();
	void handleEvents();
	void clean();
	Player* player;

	static Game* Instance()
	{
		static Game* instance = new Game;
		return instance;
	}



	bool m_bUpPressed, m_bDownPressed, m_bLeftPressed, m_bRightPressed;

	Game();
	~Game();
};

