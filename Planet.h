#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Planet
{
public:
	Planet(RenderWindow& window, int radius);
	~Planet();

	void update(RenderWindow& window);
	void draw(RenderWindow& window);

private:
	sf::Clock clock;

	CircleShape ball;
	CircleShape ring;
	float angle;

	RectangleShape button;

	Vector2f rotate_point(float cx, float cy, float angle, Vector2f p);
	bool intersect(RectangleShape shape, Vector2i p);
};
