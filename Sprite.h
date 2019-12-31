#pragma once
#include "SDL_image.h"
#include "TextureManager.h"
class Sprite
{
public:
	int width, height;
	float m_x;
	float m_y;

	int m_iTick = 0;
	int m_iFrameX;
	int m_iMaxFrameX;

	SDL_Rect m_rSrc;

	SDL_RendererFlip m_pRendererFlip;

	Sprite(int x, int y, int w, int h) : m_x(x), m_y(y), width(w), height(h)
	{
		m_iFrameX = 0;
		m_iMaxFrameX = 8;
		width = 64;
		height = 64;

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