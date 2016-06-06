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
		
		Vector2i temp = Input::getInstance().getMousePosition();
		printf("%d %d\n", temp.x, temp.y);
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
			printf("button pressed!\n");
			break;
		case Event::KeyReleased:
			Input::getInstance().registerKeyUp(evt.key.code);
			printf("button released!\n");
			break;
		case Event::MouseMoved:
			//Vector2f mousePosition(evt.mouseMove.x, evt.mouseMove.y);
			Input::getInstance().setMousePosition(Vector2i(evt.mouseMove.x, evt.mouseMove.y));
			break;
		default:
			break;
		}
	}
}

void draw(RenderWindow& window, Ball& ball)
{
	window.clear();

	ball.draw(window);

	window.display();
}