#pragma once
#include <stdio.h>

class Input
{
private:
	bool keys[128];

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


};

