#include "Player.h"
Player::Player(int x, int y, int w, int h) : Sprite(x, y, w, h)
{
}

void Player::MoveX(int x)
{
	m_x += x * playerSpeed;
}

void Player::MoveY(int y)
{
	m_y += y * playerSpeed;
}

void Player::Render()
{
	TheTextureManager::Instance()->Render("player", m_x, m_y, width, height, m_rSrc, m_pRendererFlip);

	TheFontManager::Instance()->Render("arial", { 255, 0, 0 }, "Player: " + to_string((int)m_x) + " " + to_string((int)m_y), 0, 0);
}
