#include "TextureManager.h"
#include "Game.h"


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

bool TextureManager::Load(string ID, string file)
{
	SDL_Texture* pTexture = IMG_LoadTexture(Game::Instance()->getRenderer(), file.c_str());
	if (pTexture == nullptr)
	{
		cout << "Could not load texture" << endl;
		return false;
	}
	else
	{
		m_textureMap[ID] = pTexture;
		return true;
	}

}

void TextureManager::Render(string ID, int xpos, int ypos, int width, int height, SDL_Rect srcRect, SDL_RendererFlip flip)
{
	SDL_Rect destRect = { xpos, ypos, width, height };
	SDL_RenderCopyEx(Game::Instance()->getRenderer(), m_textureMap[ID], &srcRect, &destRect, 0.0f, NULL, flip);
}
