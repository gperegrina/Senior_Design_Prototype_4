#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	face = true;

	body.setSize(sf::Vector2f(40.0f, 40.0f));
	body.setPosition(-360.0f, 240.0f);
	body.setTexture(texture);


	//Gerardo 4/4 View Change
	view.setSize(720, 480);
	view.setCenter(360.0f, 240.0f);
	//view.zoom(0.6f);
}


Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	movement.x = 0.0f;
	movement.y = 0.0f;

	//if (sf::Event::KeyPressed && sf::Keyboard::A) 


	//Gerardo 4/4
	//Added a +0.5 to movement speed, maybe could be a variable
	//on power up you can move faster
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sound.play();
		if (faceLeft == true) {
			//std::cout << "moving left" << std::endl;
			movement.x -= ((speed * deltaTime) + 0.5);		//Gerardo: added + 4 to move in blocks
			direction = 3;
			faceLeft = true; faceDown = true;
			faceRight = true; faceUp = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (faceRight == true) {
			//std::cout << "moving right" << std::endl;
			movement.x += ((speed * deltaTime) + 0.5);
			direction = 4;
			faceLeft = true; faceDown = true;
			faceRight = true; faceUp = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (faceUp == true) {
			//std::cout << "moving up" << std::endl;
			movement.y -= ((speed * deltaTime) + 0.5);
			direction = 1;
			faceLeft = true; faceDown = true;
			faceRight = true; faceUp = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (faceDown == true) {
			//std::cout << "moving down" << std::endl;
			movement.y += ((speed * deltaTime) + 0.5);
			direction = 2;
			faceLeft = true; faceDown = true;
			faceRight = true; faceUp = true;
		}
	}
	else {/*Player not moving*/ }


	//Switching map locations
	const float playerposx = body.getPosition().x;
	const float playerposy = body.getPosition().y;
	//std::cout << "x: " << playerposx << "     " << "y: " << playerposy << std::endl;

	//Gerardo
	//removed text on views 4/4
	//checking if player is in east quadrant
	if (body.getPosition().x > 720.0f && body.getPosition().y < 480.0f) {
		//std::cout << "out of bounds East" << std::endl;
		view.setCenter(1080.0f, 240.0f);
		N = false, E = true, C = false, S = false, W = false, SW = false, SE = false;
		here = 2;
	}
	else if (body.getPosition().x > 720.0f && body.getPosition().y > 480.0f) {
		//std::cout << "out of bounds South East" << std::endl;
		view.setCenter(1080.0f, 720.0f);
		N = false, E = false, C = false, S = false, W = false, SW = false, SE = true;
		here = 7;
	}
	//south quadrant
	else if (body.getPosition().y > 480.0f && body.getPosition().x > 0) {
		//std::cout << "out of bounds South" << std::endl;
		view.setCenter(360.0f, 720.0f);
		N = false, E = false, C = false, S = true, W = false, SW = false, SE = false;
		here = 3;
	}
	else if (body.getPosition().y > 480.0f && body.getPosition().x < 0) {
		//std::cout << "out of bounds South West" << std::endl;
		view.setCenter(-360.0f, 720.0f);
		N = false, E = false, C = false, S = false, W = false, SW = true, SE = false;
		here = 6;
	}
	//north quadrant
	else if (body.getPosition().y < -50.0f) {
		//std::cout << "out of bounds North" << std::endl;
		view.setCenter(360.0f, -240.0f);
		N = true, E = false, C = false, S = false, W = false, SW = false, SE = false;
		here = 1;
	}
	//west quadrant
	else if (body.getPosition().x < -50.0f) {
		//std::cout << "out of bounds West" << std::endl;
		view.setCenter(-360.0f, 240.0f);
		N = false, E = false, C = false, S = false, W = true, SW = false, SE = false;
		here = 4;
	}
	else {
		view.setCenter(360.0f, 240.0f);
		N = false, E = false, C = true, S = false, W = false, SW = false, SE = false;
		here = 5;
	}

	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (movement.x > 0.0f)
			face = true;
		else
			face = false;
	}
	if (movement.y < 0.0f) {
		row = 2;

	}

	animation.Update(row, deltaTime, face);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
