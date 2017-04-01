#pragma once
#include <SFML\Graphics.hpp>
class Resource
{
public:
	bool resource1 = false;
	bool resource2 = false;
	bool resource3 = false;
	bool gathered = false;

	sf::RectangleShape rect;
	sf::Sprite sprite;

	Resource();
	void update();


};