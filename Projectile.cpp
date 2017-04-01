#include "projectile.h"

projectile::projectile()
{
	rect.setSize(sf::Vector2f(3, 3));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::White);
	//sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void projectile::update()
{
	if (direction == 1) // Up
	{
		rect.move(0, -movementSpeed);
	}
	if (direction == 2) // Down
	{
		rect.move(0, movementSpeed);
	}
	if (direction == 3) // Left
	{
		rect.move(-movementSpeed, 0);
	}
	if (direction == 4) // Right
	{
		rect.move(movementSpeed, 0);
	}
}