#pragma once
#include <SFML/Graphics.hpp>

//#include "entity.h"
#include "random.h"

class enemy
{
public:
	//float movementSpeed = 0.5; //slower
	int movementSpeed = 5;
	int movementLength = 100; //50 move shorter
	int attackDamage = 2;
	//////Miguel
	double enemyAttackDamage1 = 0.1;
	double enemyAttackDamage2 = 0.2;
	//////
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int counter = 0;

	//----------------------------- Add on 03/23 for projectile
	int hp = 3;
	bool alive = true;

	// Add for collision with wall
	bool faceRight = true;
	bool faceLeft = true;
	bool faceUp = true;
	bool faceDown = true;

	// Add for chasing AI
	bool chase = true;

	//Added from Entity.h
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;

	enemy();
	void update();
	void updateMovement();
};


