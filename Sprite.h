#pragma once
#include "SDL_image.h"
class Sprite
{
public:
	int m_iTick = 0;
	int m_iFrameX;
	int m_iMaxFrameX;

	SDL_Rect m_rSrc;
	SDL_Rect m_rDst;
	SDL_Texture* m_pTexture;
	SDL_RendererFlip m_pRendererFlip;

	Sprite(int x, int y)
	{
		m_iFrameX = 0;
		m_iMaxFrameX = 8;
		m_rDst = { x, y, 64, 64 };
		m_rSrc = { 0, 0, 128, 128 };
	}
	void AdvanceAnimation()
	{
		m_iFrameX++;
		m_rSrc.x = m_iFrameX * 128;
		
		if (m_iFrameX == m_iMaxFrameX)
		{
			m_iFrameX = 0;
		}
	}
};