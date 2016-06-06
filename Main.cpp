#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Ball.h"

using namespace std;
using namespace sf;

void eventRunner(RenderWindow& window, bool& gameRunning);
void draw(RenderWindow& window, Ball& ball);

int main() 
{
	RenderWindow window(VideoMode(1280, 720), "Space... And Stuff!");
	
	Ball ball;

	bool gameRunning = true;

	while (gameRunning)
	{
		eventRunner(window, gameRunning);

		ball.move();
		
		draw(window, ball);
		
	}


	return 0;
}

void eventRunner(RenderWindow& window, bool& gameRunning)
{
	Event evt;
	while (window.pollEvent(evt))
	{
		if (evt.type == Event::Closed)
		{
			window.close();
			gameRunning = false;
		}

		if (evt.type == Event::KeyPressed)
		{
			Input::getInstance().registerKeyDown(evt.key.code);
			printf("button pressed!\n");
		}
		else if (evt.type == Event::KeyReleased)
		{
			Input::getInstance().registerKeyUp(evt.key.code);
			printf("button released!\n");
		}
	}
}

void draw(RenderWindow& window, Ball& ball)
{
	window.clear();

	ball.draw(window);

	window.display();
}