#pragma once
#include <SFML\Graphics.hpp>


class Wall
{
public:
	Wall();
	~Wall();

	void update();

	sf::RectangleShape rect;
	sf::Sprite sprite;
};

