#pragma once
#include "../Game.h"
#include "../Vector2.h"
class PlayerInputManager
{
private:
	//Axis based on WASD and the arrow keys
	float xAxis = 0.0f;
	float yAxis = 0.0f;
	bool shiftPressed = false;
	bool spacePressed = false;
public:
	void SetInputs();
	float GetXAxis();
	float GetYAxis();
	Vector2 GetAxis();
	bool SpacePressed();
	bool ShiftPressed();
};