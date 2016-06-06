#include "Ball.h"


Ball::Ball()
{
	angle = 3.14; //180 grader ditt jävla pucko

	ball.setFillColor(Color::Green);
	ball.setRadius(10);
	ball.setPosition(100,100);

	ring.setRadius(44);
	ring.setFillColor(Color::Black);
	ring.setOutlineThickness(1);
	ring.setOutlineColor(Color::White);
	ring.setPosition(150 - ring.getRadius(), 100 - ring.getRadius());
}


Ball::~Ball()
{
}

void Ball::move()
{
	Time elapsed = clock.restart();
	Vector2f oldPos = ball.getPosition();
	oldPos = Vector2f(oldPos.x + ball.getRadius(), oldPos.y + ball.getRadius());

	Vector2f newPos = rotate_point(150, 100, angle * elapsed.asSeconds(), oldPos);
	ball.setPosition(newPos.x - ball.getRadius(), newPos.y - ball.getRadius());
}

Vector2f Ball::rotate_point(float cx, float cy, float angle, Vector2f p)
{
	float s = sin(angle);
	float c = cos(angle);

	// translate point back to origin:
	p.x -= cx;
	p.y -= cy;

	// rotate point
	float xnew = p.x * c - p.y * s;
	float ynew = p.x * s + p.y * c;

	// translate point back:
	p.x = xnew + cx;
	p.y = ynew + cy;
	return p;
}

void Ball::draw(RenderWindow& window)
{
	window.draw(ring);
	window.draw(ball);
}

CircleShape Ball::getShape()
{
	return ball;
}
