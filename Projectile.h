#pragma once
#include <SFML/Graphics.hpp>
//#include "entity.h"

class projectile
{
public:
	int movementSpeed = 10;
	int attackDamage = 5;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	bool destroy = false;
	int counterLifetime = 0;

	//Added from Entity.h
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;


	projectile();
	void update();
	//void updateMovement();
};