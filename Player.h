#pragma once
#include "Sprite.h"
class Player : public Sprite
{
private:
	int m_x;
	int m_y;
	const int playerSpeed = 5;
public:
	Player(SDL_Texture* pTexture, int x, int y) : Sprite(x, y)
	{
		m_pTexture = pTexture;
		m_x = x;
		m_y = y;
	}
	void UpdateDest()
	{
		m_rDst.x = m_x;
		m_rDst.y = m_y;
	}
	void MoveX(int x)
	{
		m_x += x * playerSpeed;
		UpdateDest();
	}
	void MoveY(int y)
	{
		m_y += y * playerSpeed;
		UpdateDest();
	}
};