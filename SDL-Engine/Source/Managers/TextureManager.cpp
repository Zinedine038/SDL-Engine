#include "TextureManager.h"

//Takes in a file location, loads the texture and returns it for later use and storage
SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;
}

//Takes in a texture, source rect and destination rect and draws the texture.
//Where it is and how much is renderer is based and the rects
void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}