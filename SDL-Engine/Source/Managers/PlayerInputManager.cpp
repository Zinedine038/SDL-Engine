#include "PlayerInputManager.h"

void PlayerInputManager::SetInputs()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		//Switch to check if keyboard keys have been pressed
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_UP:
			yAxis = 1.0f;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			yAxis = -1.0f;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			xAxis = 1.0f;
			break;
		case SDLK_a:
		case SDLK_LEFT:
			xAxis = -1.0f;
			break;
		case SDLK_LSHIFT:
			shiftPressed = true;
			break;
		case SDLK_SPACE:
			spacePressed = true;
			break;
		default:
			break;
		}
	}
	if (Game::event.type == SDL_KEYUP)
	{
		//Switch to check if keyboard keys have been released
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_UP:
			yAxis = 0.0f;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			yAxis = 0.0f;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			xAxis = 0.0f;
		case SDLK_a:
		case SDLK_LEFT:
			xAxis = 0.0f;
			break;
		case SDLK_LSHIFT:
			shiftPressed = false;
			break;
		case SDLK_SPACE:
			spacePressed = false;
			break;
		default:
			break;
		}
	}
}

//Returns the X Axis 
float PlayerInputManager::GetXAxis()
{						
	return xAxis;
}						

//Returns the Y axis	
float PlayerInputManager::GetYAxis()
{
	return yAxis;
}

//Returns boths X and Y stored in a Vector2
Vector2 PlayerInputManager::GetAxis()
{
	return Vector2(xAxis, yAxis);
}

//Returns true if the shiftbutton is pressed
bool PlayerInputManager::ShiftPressed()
{
	return shiftPressed;
}

//Returns true if the spacebar has been pressed
bool PlayerInputManager::SpacePressed()
{
	return spacePressed;
}