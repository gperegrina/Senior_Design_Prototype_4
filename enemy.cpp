#include "enemy.h"

enemy::enemy()
{
	rect.setSize(sf::Vector2f(50.0f, 50.0f));
	rect.setPosition(360.0f, 240.0f);
	
	
}

void enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void enemy::updateMovement()
{
	
	if (direction == 1) // Up
	{  
		if (faceUp == true)
		{rect.move(0, -movementSpeed);}
		faceLeft = true; faceDown = true;  // Add enemy collision with walls
		faceRight = true; faceUp = true;
	}
	else if (direction == 2) // Down
	{
		if (faceDown == true)
		{rect.move(0, movementSpeed);}
		faceLeft = true; faceDown = true;
		faceRight = true; faceUp = true;
	}
	else if (direction == 3) // Left
	{
		if (faceLeft == true)
		{rect.move(-movementSpeed, 0); }
		faceLeft = true; faceDown = true;
		faceRight = true; faceUp = true;
		
	}
	else if (direction == 4) // Right
	{   
		if (faceRight == true)
		{rect.move(movementSpeed, 0); }
		faceLeft = true; faceDown = true;
		faceRight = true; faceUp = true;
		
	}
	else
	{
		// No movement
	}

	counterWalking++;
	if (counterWalking == 1)
	{
		counterWalking = 0;
	}

	counter++;
	if (counter >= movementLength)
		//if (counter >= 40)
	{
		//direction = generateRandom(20);
		direction = generateRandom(10);
		
		counter = 0;
	}

}
