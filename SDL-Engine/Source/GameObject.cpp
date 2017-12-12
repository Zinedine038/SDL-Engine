#include "GameObject.h"
#include <iostream>

//Constructor for a GameObject, only takes in a spriteRoot all other values are set to default
GameObject::GameObject(const char* spriteRoot)
{
	animated = false;
	defaultSprite = TextureManager::LoadTexture(spriteRoot);
	sourceDefault.x = sourceDefault.y = 0;
	sourceDefault.h = 32;
	sourceDefault.w = 32;
	scale = 1;
}

//Constructor for a GameObject, takes in the spriteRoot and its position. Sets the position accordingly
GameObject::GameObject(const char* spriteRoot, float xPos, float yPos)
{
	animated = false;
	defaultSprite = TextureManager::LoadTexture(spriteRoot);
	sourceDefault.x = sourceDefault.y = 0;
	sourceDefault.h = 32;
	sourceDefault.w = 32;
	position.x = xPos;
	position.y = yPos;
	scale = 1;
}

//Constructor for a GameObject,takes in the spriteRoot, its position and its scale.
GameObject::GameObject(const char* spriteRoot, float xPos, float yPos, int scale)
{
	animated = false;
	defaultSprite = TextureManager::LoadTexture(spriteRoot);
	sourceDefault.x = sourceDefault.y = 0;
	sourceDefault.h = 32;
	sourceDefault.w = 32;
	position.x = xPos;
	position.y = yPos;
	GameObject::scale = scale;
}

//Constructor for an animated Gameobject, takes in a spriteroot, its position, its scale and an animation
GameObject::GameObject(const char* spriteRoot, float xPos, float yPos, int scale, Animation* anim)
{
	animated = true;
	animation = anim;
	defaultSprite = TextureManager::LoadTexture(spriteRoot);
	animatedSprite = TextureManager::LoadTexture(anim->animationSheet);
	sourceDefault.x = sourceDefault.y = 0;
	sourceDefault.h = 32;
	sourceDefault.w = 32;
	position.x = xPos;
	position.y = yPos;
	GameObject::scale = scale;
}

void GameObject::Awake() 
{

}

//Updates the gameobject in this case it sets its position and its scale
void GameObject::Update() 
{
	destination.x = static_cast<int>(position.x);
	destination.y = static_cast<int>(position.y);
	destination.h = (32 * scale);
	destination.w = (32 * scale);
}

//Tells the texturemanager to draw the gameobject
void GameObject::Draw() 
{
	//Animates
	if (animated)
	{
		Animate();
		TextureManager::Draw(animatedSprite, sourceAnimated, destination);
	}
	//Draws the Default sprite
	else
	{
		TextureManager::Draw(defaultSprite, sourceDefault, destination);
	}
}

//public method to set a gameobjects position directly
void GameObject::SetPosition(Vector2 v2)
{
	position.x = v2.x;
	position.y = v2.y;
}

//public method to add a vector2 to the gameobjects current position
void GameObject::AddAxis(Vector2 v2)
{
	position.x += v2.x;
	position.y -= v2.y;
}

//calls to animation to play an animation based on the gameobjects animation index
//Also sets the rect correctly
void GameObject::Animate()
{
	animation->Play(animationIndex);
	sourceAnimated = animation->animRect;
}
