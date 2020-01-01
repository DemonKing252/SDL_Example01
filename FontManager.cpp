#include "FontManager.h"
#include "Game.h"


FontManager::FontManager()
{
}


FontManager::~FontManager()
{
}

FontManager * FontManager::Instance()
{
	static FontManager* instance = new FontManager();
	return instance;
}

bool FontManager::Load(string ID, string file, int size)
{
	TTF_Font* pFont = TTF_OpenFont(file.c_str(), size);
	if (pFont == nullptr)
	{
		cout << "Problem loading font!" << endl;
		return false;
	}
	m_fontMap[ID] = pFont;
}

void FontManager::Render(string ID, SDL_Color color, string text, int xpos, int ypos)
{
	SDL_Surface* pSurf = TTF_RenderText_Blended(m_fontMap[ID], text.c_str(), color);

	SDL_Texture* pTex = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), pSurf);
	
	SDL_Rect destRect = { xpos, ypos, pSurf->w, pSurf->h };



	SDL_FreeSurface(pSurf);

	
	SDL_RenderCopy(Game::Instance()->getRenderer(), pTex, NULL, &destRect);

	SDL_DestroyTexture(pTex);

}
