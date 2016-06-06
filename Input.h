#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Input
{
private:
	bool keys[128];
	Vector2i mousePosition;

	Input(Input const&);
	Input& operator=(Input const&);

	Input(){};
	~Input(){};
public:
	static Input& getInstance()
	{
		static Input instance;
		return instance;
	}

	void registerKeyDown(int keyCode);
	void registerKeyUp(int keyCode);
	bool getKeyState(int keyCode);
	void setMousePosition(Vector2i newPosition);
	Vector2i getMousePosition();
};
