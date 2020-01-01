#pragma once
#include "SDL_ttf.h"
#include "SDL.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;
class FontManager
{
public:
	map<string, TTF_Font*> m_fontMap;
	FontManager();
	~FontManager();
	static FontManager* Instance();

	bool Load(string ID, string file, int size);
	void Render(string ID, SDL_Color color, string text, int xpos, int ypos);
};
typedef FontManager TheFontManager;
