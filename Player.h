#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Animation.h"
#include <iostream>

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	//Sound settings
	sf::SoundBuffer soundBuf;
	sf::Sound sound;
	sf::View view;

	sf::Vector2f movement;
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	int direction = 0;
	bool face;
	bool faceRight = true;
	bool faceLeft = true;
	bool faceUp = true;
	bool faceDown = true;

	//Miguel
	//Player Health+Ammo+Tower
	int health = 5;
	int ammo = 3;
	int tower = 3;


private:
	//sf::RectangleShape body;
	//Animation animation;
	//unsigned int row;
	//float speed;
	//bool faceRight;



};






