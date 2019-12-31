#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Player.h"
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
	void update(Player& p);
	void render(Player& p);
	void handleEvents();
	void clean();


	static Game* Instance()
	{
		static Game* instance = new Game;
		return instance;
	}



	bool m_bUpPressed, m_bDownPressed, m_bLeftPressed, m_bRightPressed;

	Game();
	~Game();
};

