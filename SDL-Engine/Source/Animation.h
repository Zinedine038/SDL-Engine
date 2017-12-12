#pragma once
#include "Managers\TextureManager.h"
#include "SDL.h"
#include <vector>
#include <array>

class Animation
{
private:
	//Animation Speed
	int speed;
	//Number of frames per animation
	std::vector<int> frames;
public:
	//Root for the animation sheet
	const char* animationSheet;
	//Rect for the animation sheet
	SDL_Rect animRect; 
	Animation() {}

	//Constructor for the Animation
	//Root is the file location
	//f are the frames per one animation so each animation can have a different number of frames
	//s sets the speed of the animations
	//size sets the size of the rect
	Animation(const char* root, std::vector<int> f, int s, int size)
	{
		animationSheet = root;
		frames = f;
		speed=s;
		animRect.h = size;
		animRect.w = size;
	};

	//Generic method used to play an animation takes in the index number of the animation to play
	void Play(int index)
	{
		animRect.y = (animRect.h * index);
		animRect.x = animRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames[index]);
	}
};