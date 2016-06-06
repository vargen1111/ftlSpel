#include "Planet.h"
#include "Input.h"


Planet::Planet(RenderWindow& window, int radius)
{
	//3.14 radianer = 180 grader ditt jävla pucko
	//2 * 3.14 radianer = 360 grader ditt jävla pucko

	angle = 3.14;
	// problem: större radie ger snabbare rotation, duuh

	ball.setFillColor(Color::Green);
	ball.setRadius(10);
	ball.setPosition(window.getSize().x/2 + radius, window.getSize().y/2);

	ring.setRadius(radius + ball.getRadius());
	ring.setFillColor(Color::Black);
	ring.setOutlineThickness(1);
	ring.setOutlineColor(Color::White);
	ring.setPosition(window.getSize().x / 2 - ring.getRadius(), window.getSize().y / 2 - ring.getRadius());

	button.setFillColor(Color::Green);
	button.setSize(Vector2f(100, 50));
	button.setPosition(10, 100);
}


Planet::~Planet()
{
}

void Planet::update(RenderWindow& window)
{
	//move planet
	Time elapsed = clock.restart();
	Vector2f oldPos = ball.getPosition();
	oldPos = Vector2f(oldPos.x + ball.getRadius(), oldPos.y + ball.getRadius());
	Vector2f newPos = rotate_point(window.getSize().x/2, window.getSize().y/2, angle * elapsed.asSeconds(), oldPos);
	ball.setPosition(newPos.x - ball.getRadius(), newPos.y - ball.getRadius());

	if (intersect(button,Input::getInstance().getMousePosition()))
	{
		button.setOutlineColor(Color::White);
		button.setOutlineThickness(1);

		ring.setOutlineColor(Color::Green);
		ball.setOutlineColor(Color::White);
		ball.setOutlineThickness(1);
	}
	else
	{
		button.setOutlineColor(Color::White);
		button.setOutlineThickness(0);

		ring.setOutlineColor(Color::White);
		ball.setOutlineThickness(0);
	}
}

Vector2f Planet::rotate_point(float cx, float cy, float angle, Vector2f p)
{
	float s = sin(angle);
	float c = cos(angle);

	// translate point back to origin:
	p.x -= cx;
	p.y -= cy;

	// rotate point
	float xnew = p.x * c - p.y * s;
	float ynew = (p.x * s + p.y * c); //kan dela s med en faktor för att få en oval rotation

	// translate point back:
	p.x = xnew + cx;
	p.y = ynew + cy;
	return p;
}

bool Planet::intersect(sf::RectangleShape rect, Vector2i p)
{
	if (rect.getPosition().x > p.x || 
		rect.getPosition().y > p.y ||
		rect.getPosition().x + rect.getSize().x < p.x ||
		rect.getPosition().y + rect.getSize().y < p.y)
	{
		return false;
	}
	return true;
}

void Planet::draw(RenderWindow& window)
{
	window.draw(button);
	window.draw(ring);
	window.draw(ball);
}
