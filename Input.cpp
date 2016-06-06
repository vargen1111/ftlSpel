#include "Input.h"

void Input::registerKeyDown(int keyCode)
{
	keys[keyCode] = true;
	
	//printf("button state: %d\n", keys[keyCode]);
}

void Input::registerKeyUp(int keyCode)
{
	keys[keyCode] = false;
	
	//printf("button state: %d\n", keys[keyCode]);
}

bool Input::getKeyState(int keyCode)
{
	return keys[keyCode];
}

void Input::setMousePosition(Vector2i newPosition)
{
	mousePosition = newPosition;
}

Vector2i Input::getMousePosition()
{
	return mousePosition;
}