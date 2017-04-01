#include "Resource.h"

Resource::Resource() {
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(0, 0);
	//rect.setFillColor(sf::Color::Yellow);
	//sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Resource::update() {
	sprite.setPosition(rect.getPosition());
}