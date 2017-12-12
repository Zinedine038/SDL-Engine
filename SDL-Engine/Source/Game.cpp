#include "Game.h"
#include <iostream>
#include "Managers/TextureManager.h"
#include "Managers/PlayerInputManager.h"
#include "Vector2.h"
#include "GameObject.h"
#include <vector>

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

PlayerInputManager *playerInput = nullptr;
GameObject *player = nullptr;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(const char* title, int xPos, int yPos, int width, int heigth, bool fullScreen)
{

	#pragma region Initialization
	int flags = 0;
	if (fullScreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	//Initializes all SDL systems
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xPos, yPos, width, heigth, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			//Sets the default background colour
			SDL_SetRenderDrawColor(renderer, 122, 122, 122, 255);
			std::cout << "Renderer Created!" << std::endl;
		}
		playerInput = new PlayerInputManager();
		isRunning = true;
	}
	else
	{
		//Fail safe if the system cannot be initialized the game loop won't run
		isRunning = false;
	}

	int tempPlayerFrames[] = { 3,8,8,4,4 };
	std::vector<int> playerFramesVector(tempPlayerFrames, tempPlayerFrames + sizeof(tempPlayerFrames) / sizeof(tempPlayerFrames[0]));
	Animation* playerAnim = new Animation("Assets/playerAnimations.png", playerFramesVector, 100, 32);
	player = new GameObject("Assets/player.png", 300, 300, 2, playerAnim);
	#pragma endregion

}

//Method used to handle and check for Events
void Game::HandleEvents()
{
	//Stores the 
	SDL_PollEvent(&event);
	//Checks if the game has been quit
	switch (event.type)
	{
		case SDL_QUIT:
			//Makes the game loop in main end
			isRunning = false;
			break;
		default:
			break;
	}
	//Call to the PlayerInput manager
	playerInput->SetInputs();
}

//Method used for updating all other values and doing calculations
void Game::Update()
{
	player->Update();
	MoveAndAnimatePlayer();
}

//Method used for cleaning up the renderer each frame and drawing the new frame
void Game::Render()
{
	SDL_RenderClear(renderer);
	player->Draw();
	SDL_RenderPresent(renderer);
}

//Method called when the game is quit to properly close everything off
void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Engine Closed" << std::endl;
}

//Updates the position of the player and sets the animation accordingly
void Game::MoveAndAnimatePlayer()
{
	if (playerInput->GetXAxis() == 0 && playerInput->GetYAxis() ==0)
	{
		player->animationIndex = 0;
	}
	else if(playerInput->GetXAxis()>0)
	{
		player->animationIndex = 1;
	}
	else if (playerInput->GetXAxis()<0)
	{
		player->animationIndex = 2;
	}
	else if (playerInput->GetYAxis() < 0)
	{
		player->animationIndex = 3;
	}
	else if (playerInput->GetYAxis() > 0)
	{
		player->animationIndex = 4;
	}

	player->AddAxis(playerInput->GetAxis()*2);
	if (playerInput->ShiftPressed())
	{
		player->AddAxis((playerInput->GetAxis()*4));
	}
}
