#include "Game.h"



SDL_Renderer * Game::getRenderer()
{
	return m_pRenderer;
}

bool Game::running()
{
	return m_bRunning;
}

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
	cout << "SDL init success" << endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)
		{
			cout << "window creation success" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		else
		{
			cout << "window creation fail" << endl;
			return false;
		}
		if (IMG_Init(IMG_INIT_PNG))
		{
			cout << "image init success" << endl;
		}
		else
		{
			cout << "image init fail" << endl;
			return false;
		}
	}
	else
	{
		cout << "SDL init fail" << endl;
		return false;
	}

	m_bRunning = true;
	return true;
}

void Game::update(Player& p)
{
	if (m_bUpPressed)
	{
		p.MoveY(-1);
	}
	if (m_bDownPressed)
	{
		p.MoveY(1);
	}
	if (m_bLeftPressed)
	{
		p.MoveX(-1);
		p.m_pRendererFlip = SDL_FLIP_HORIZONTAL;
	}
	if (m_bRightPressed)
	{
		p.MoveX(1);
		p.m_pRendererFlip = SDL_FLIP_NONE;
		
	}

	if (!m_bUpPressed && !m_bDownPressed && !m_bLeftPressed && !m_bRightPressed)
	{
		p.m_iFrameX = 0;
		p.m_rSrc.x = 0;
	}
	else
	{
		p.m_iTick++;

		if (p.m_iTick % 4 == 0)
			p.AdvanceAnimation();

	}
		
	
}

void Game::render(Player& p)
{
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopyEx(m_pRenderer, p.m_pTexture, &p.m_rSrc, &p.m_rDst, 0.0f, NULL, p.m_pRendererFlip);

	SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				m_bUpPressed = true;
				break;
			case SDLK_a:
				m_bLeftPressed = true;
				break;
			case SDLK_s:
				m_bDownPressed = true;
				break;
			case SDLK_d:
				m_bRightPressed = true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				m_bUpPressed = false;
				break;
			case SDLK_a:
				m_bLeftPressed = false;
				break;
			case SDLK_s:
				m_bDownPressed = false;
				break;
			case SDLK_d:
				m_bRightPressed = false;
				break;
			}
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();

}

Game::Game()
{
}


Game::~Game()
{
}
