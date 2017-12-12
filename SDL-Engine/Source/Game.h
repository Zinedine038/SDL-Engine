#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

class Game
{
public:
	Game();
	~Game();
	void Init(const char* title, int xPos, int yPos, int width, int heigth, bool fullScreen);
	void HandleEvents();
	void Update();
	bool Running()
	{
		return isRunning;
	};
	void Render();
	void Clean();
	static SDL_Renderer *renderer;
	static SDL_Event event;

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window *window;
	void MoveAndAnimatePlayer();
};