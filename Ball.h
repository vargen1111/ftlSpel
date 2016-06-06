#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
public:
	Ball();
	~Ball();

	CircleShape getShape();
	void move();
	void draw(RenderWindow& window);

private:
	sf::Clock clock;
	Vector2f velocity;
	CircleShape ball;
	CircleShape ring;
	float angle;

	Vector2f rotate_point(float cx, float cy, float angle, Vector2f p);
};

