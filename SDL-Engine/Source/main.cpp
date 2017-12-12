#include "Game.h"

Game *game = nullptr;

int main(int argc, char* argv[])
{
	//fps the game should be running at
	const int fps = 60;
	//how many ms a frame should take at the minimum
	const int frameDelay = 1000 / fps;
	//Variable to store the amount of ms passed at the start of the frame 
	Uint32 frameStart;
	//Variable to store how many ms have passed in this frame
	int frameTime;

	//Makes a new Game
	game = new Game();
	//Initializes the game with a Window name, window position, resolution and a bool for a full screen toggle
	game->Init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	//The Main Game Loop
	while (game->Running())
	{
		frameStart = SDL_GetTicks();
		//Calls the main methods from Game.cpp
		game->HandleEvents();
		game->Update();
		game->Render();
		//Calculation to prevent framerate going above the given framerate
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	//Exits the game
	game->Clean();
	return 0;
}