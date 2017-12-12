#pragma once
#include "Vector2.h"
#include "SDL.h"
#include "Managers\TextureManager.h"
#include "Animation.h"

class GameObject
{
public:
	bool animated;
	Animation idle;
	GameObject(const char* spriteRoot);
	GameObject(const char* spriteRoot, float xPos, float yPos);
	GameObject(const char* spriteRoot, float xPos, float yPos, int scale);
	GameObject::GameObject(const char* spriteRoot, float xPos, float yPos, int scale, Animation* anim);
	Vector2 position;
	virtual void Awake();
	virtual void Update();
	virtual void Draw();
	void SetPosition(Vector2 v2);
	void AddAxis(Vector2 v2);
	int animationIndex;
	Animation* animation;
	void Animate();
	void SetAnimatedSprite(SDL_Texture* texture)
	{
		animatedSprite = texture;
	}
private:
	SDL_Rect sourceDefault;
	SDL_Rect sourceAnimated;
	SDL_Rect destination;
	SDL_Texture* defaultSprite;
	SDL_Texture* animatedSprite;
	int scale;
};