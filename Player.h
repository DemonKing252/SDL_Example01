#pragma once
#include "Sprite.h"
#include "FontManager.h"
class Player : public Sprite
{
private:

	const float playerSpeed = 5;
public:
	Player(int x, int y, int w, int h);

	void MoveX(int x);
	void MoveY(int y);

	void Render();
};