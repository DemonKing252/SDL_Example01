#pragma once
#include <map>
#include "SDL_image.h"
#include "SDL.h"
#include <string>
using namespace std;

class TextureManager
{
private:
	map<string, SDL_Texture*> m_textureMap;
public:
	TextureManager();
	~TextureManager();

	static TextureManager* Instance()
	{
		static TextureManager* instance = new TextureManager;
		return instance;
	}

	bool Load(string ID, string file);
	void Render(string ID, int xpos, int ypos, int width, int height, SDL_Rect srcRect, SDL_RendererFlip flip);

};
typedef TextureManager TheTextureManager;
