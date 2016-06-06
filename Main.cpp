#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Planet.h"

using namespace std;
using namespace sf;

void eventRunner(RenderWindow& window, bool& gameRunning);
void draw(RenderWindow& window, Planet& ball);

int main() 
{
	RenderWindow window(VideoMode(1280, 720), "Space... And Stuff!");
	//RenderWindow window(VideoMode(1920, 1080), "Space... And Stuff!", sf::Style::Fullscreen);

	Planet ball(window, 50);

	bool gameRunning = true;

	while (gameRunning)
	{
		eventRunner(window, gameRunning);

		ball.update(window);
		
		draw(window, ball);
	}
	return 0;
}

void eventRunner(RenderWindow& window, bool& gameRunning)
{
	Event evt;
	while (window.pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
		{
			window.close();
			gameRunning = false;
		}
			break;
		case Event::KeyPressed:
			Input::getInstance().registerKeyDown(evt.key.code);
			printf("button %d pressed!\n", evt.key.code);
			break;
		case Event::KeyReleased:
			Input::getInstance().registerKeyUp(evt.key.code);
			printf("button %d released!\n", evt.key.code);
			break;
		case Event::MouseMoved:
			Input::getInstance().setMousePosition(Vector2i(evt.mouseMove.x, evt.mouseMove.y));
			break;
		default:
			break;
		}
	}
}

void draw(RenderWindow& window, Planet& ball)
{
	window.clear();

	ball.draw(window);

	window.display();
}
