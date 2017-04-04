#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "Animation.h"
#include "Player.h"
#include "Audio.h"
#include "Graphic.h"
#include "Wall.h"
#include "Resource.h"
#include "enemy.h"
#include "Projectile.h"
#include "enemy.h"

using namespace std;
int exitgame = 0;
int pausedgame = 20;

int main() {
	
	//Global Variables
	sf::RenderWindow window(sf::VideoMode(720, 480), "Fight Hard Yeah! Tower Defense Game", sf::Style::Close | sf::Style::Titlebar);
	//sf::RenderWindow window(sf::VideoMode(1024, 576), "Fight Hard Yeah! Tower Defense Game", sf::Style::Close | sf::Style::Titlebar);

	Audio audio;
	Graphic graphics;
	int flag = 0, counter = 0, help = 0, drawtower = 0;
	sf::Clock clock1; // clock for AI Cuong
	sf::Clock clock2;
	sf::Clock clock3;
	int counter2 = 0, counter3 = 0;
		
	//---------------------------------------------------------------------------------------------------------------
	//Gerardo 
	//Player character texture, rectangle bound to box
	sf::Texture playerTexture;
	playerTexture.loadFromFile("char_sprite_walk3.png");

	sf::RectangleShape playerRect;
	sf::Texture playerTexture2;
	playerTexture2.loadFromFile("player.png");
	playerRect.setSize(sf::Vector2f(40.0f, 40.0f));
	playerRect.setPosition(220.0f, 220.0f);
	playerRect.setTexture(&playerTexture2);
	sf::RectangleShape tower1;
	sf::RectangleShape tower2;
	sf::RectangleShape tower3;
	sf::Texture towertex1;
	sf::Texture towertex2;
	sf::Texture towertex3;
	towertex1.loadFromFile("tower1.png");
	tower1.setSize(sf::Vector2f(30.0f, 40.0f));
	towertex2.loadFromFile("tower2.png");
	tower2.setSize(sf::Vector2f(30.0f, 40.0f));
	towertex3.loadFromFile("tower3.png");
	tower3.setSize(sf::Vector2f(30.0f, 40.0f));
	tower1.setTexture(&towertex1);
	tower2.setTexture(&towertex2);
	tower3.setTexture(&towertex3);
	tower1.setPosition(0.0f, 0.0f);
	tower2.setPosition(0.0f, 0.0f);
	tower3.setPosition(0.0f, 0.0f);


	//---------------------------------------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------------------------------------
	//Miguel text on screen
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "can't open ttf file" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(15);
	//text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setString("Level - 1\n");

	sf::Text textHelp;
	textHelp.setFont(font);
	textHelp.setCharacterSize(15);
	textHelp.setString("\n(H) Help?\n");
	sf::Text textHelp2;
	textHelp2.setFont(font);
	textHelp2.setCharacterSize(15);
	textHelp2.setString("\n(H) Help?\n(F) - Flashlight\n(Space) - Shoot\n(1) - Melee\n(2) - Sword\n(3) - Tower\n");
	//---------------------------------------------------------------------------------------------------------------

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//																4/2/17
	//Miguel Health Bar
	sf::Texture textureHealthBar;
	if (!textureHealthBar.loadFromFile("healthBar2.png")) {
		cout << "Health Bar texture not found!\n";
	}
	sf::Sprite spriteHealth0, spriteHealth1, spriteHealth2, spriteHealth3, spriteHealth4, spriteHealth5;
	spriteHealth5.setTexture(textureHealthBar); spriteHealth5.setTextureRect(sf::IntRect(0, 0, 111, 47)); spriteHealth5.setPosition(sf::Vector2f(609, 0));
	spriteHealth4.setTexture(textureHealthBar); spriteHealth4.setTextureRect(sf::IntRect(0, 48, 111, 47)); spriteHealth4.setPosition(sf::Vector2f(609, 0));
	spriteHealth3.setTexture(textureHealthBar); spriteHealth3.setTextureRect(sf::IntRect(0, 94, 111, 47)); spriteHealth3.setPosition(sf::Vector2f(609, 0));
	spriteHealth2.setTexture(textureHealthBar); spriteHealth2.setTextureRect(sf::IntRect(0, 142, 111, 47)); spriteHealth2.setPosition(sf::Vector2f(609, 0));
	spriteHealth1.setTexture(textureHealthBar); spriteHealth1.setTextureRect(sf::IntRect(0, 190, 111, 47)); spriteHealth1.setPosition(sf::Vector2f(609, 0));
	spriteHealth0.setTexture(textureHealthBar); spriteHealth0.setTextureRect(sf::IntRect(0, 237, 111, 47)); spriteHealth0.setPosition(sf::Vector2f(609, 0));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	//---------------------------------------------------------------------------------------------------------------
	//Miguel Walls
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Miguel Walls							4/2/17				Just Copy and Paste whole wall section
	//For now I just did the borders for each section
	vector<Wall>::const_iterator wallit;
	vector<Wall> wallArray;

	class Wall wall0, wall1, wall2, wall3, wall4;

	sf::Texture textureWall;
	textureWall.loadFromFile("wall.jpg");
	wall0.rect.setTexture(&textureWall);
	//East Walls
	///Top+Bottom+Right
	for (int i = 720; i <= 1370; i += 50)
	{
		wall0.rect.setPosition(i, 0);
		wallArray.push_back(wall0);
		wall0.rect.setPosition(i, 430);
		wallArray.push_back(wall0);
		for (int j = 0; j <= 450; j += 50)
		{
			wall0.rect.setPosition(1390, j);
			wallArray.push_back(wall0);
		}
	}
	///LeftTop
	for (int j = 0; j <= 100; j += 50)
	{
		wall0.rect.setPosition(720, j);
		wallArray.push_back(wall0);
	}
	wall0.rect.setPosition(720, 110);
	wallArray.push_back(wall0);

	//West Walls
	///Top+Bottom+Left
	for (int i = -720; i <= -50; i += 50)
	{
		wall0.rect.setPosition(i, 0);
		wallArray.push_back(wall0);
		wall0.rect.setPosition(i, 430);
		wallArray.push_back(wall0);
		for (int j = 0; j <= 450; j += 50)
		{
			wall0.rect.setPosition(-720, j);
			wallArray.push_back(wall0);
		}
	}
	///RightTop
	for (int j = 0; j <= 100; j += 50)
	{
		wall0.rect.setPosition(-50, j);
		wallArray.push_back(wall0);
	}
	wall0.rect.setPosition(-50, 110);
	wallArray.push_back(wall0);
	///RightBottom
	for (int j = 340; j <= 450; j += 50)
	{
		wall0.rect.setPosition(-50, j);
		wallArray.push_back(wall0);
	}

	//North
	///Top+Right+Left
	for (int i = 0; i <= 720; i += 50) {
		//wall0.rect.setPosition(i, 0);
		//wallArray.push_back(wall0);
		wall0.rect.setPosition(i, -480);
		wallArray.push_back(wall0);
		for (int j = -480; j <= -50; j += 50)
		{
			wall0.rect.setPosition(0, j);
			wallArray.push_back(wall0);
			wall0.rect.setPosition(670, j);
			wallArray.push_back(wall0);
		}
	}
	///Bottom Left
	for (int i = 0; i <= 250; i += 50)
	{
		wall0.rect.setPosition(i, -50);
		wallArray.push_back(wall0);
	}
	///Bottom Right
	for (int i = 400; i <= 720; i += 50)
	{
		wall0.rect.setPosition(i, -50);
		wallArray.push_back(wall0);
	}

	//South
	///Bottom+Right+Left
	for (int i = 0; i <= 720; i += 50) {
		wall0.rect.setPosition(i, 910);
		wallArray.push_back(wall0);
		for (int j = 480; j <= 910; j += 50)
		{
			wall0.rect.setPosition(0, j);
			wallArray.push_back(wall0);
			wall0.rect.setPosition(670, j);
			wallArray.push_back(wall0);
		}
	}
	///Top Right
	for (int i = 149; i <= 720; i += 50)
	{
		wall0.rect.setPosition(i, 480);
		wallArray.push_back(wall0);
	}

	//Center
	///Top Left
	wall1.rect.setFillColor(sf::Color::Transparent);
	wall1.rect.setPosition(0, 0);
	wall1.rect.setSize(sf::Vector2f(300, 160));
	wallArray.push_back(wall1);
	///Top Right
	wall1.rect.setPosition(400, 0);
	wall1.rect.setSize(sf::Vector2f(320, 160));
	wallArray.push_back(wall1);
	///Bottom Left
	wall1.rect.setPosition(0, 340);
	wall1.rect.setSize(sf::Vector2f(50, 140));
	wallArray.push_back(wall1);
	wall1.rect.setPosition(149, 340);
	wall1.rect.setSize(sf::Vector2f(1, 140));
	wallArray.push_back(wall1);
	///Bottom Right
	wall1.rect.setPosition(150, 430);
	wall1.rect.setSize(sf::Vector2f(570, 50));
	wallArray.push_back(wall1);
	///Tree
	wall1.rect.setPosition(560, 240);
	wall1.rect.setSize(sf::Vector2f(30, 10));
	wallArray.push_back(wall1);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	
	vector<Wall>::const_iterator wallit;
	vector<Wall> wallArray;
	
	class Wall wall1, wall2, wall3, wall4;

	wall1.rect.setPosition(0, 0);
	wall1.rect.setSize(sf::Vector2f(720, 160));
	wallArray.push_back(wall1);
	wall2.rect.setPosition(0, 340);
	wall2.rect.setSize(sf::Vector2f(150, 150));
	wallArray.push_back(wall2);
	wall3.rect.setPosition(150, 430);
	wall3.rect.setSize(sf::Vector2f(570, 50));
	wallArray.push_back(wall3);
	wall4.rect.setPosition(560, 240);
	wall4.rect.setSize(sf::Vector2f(30, 10));
	wallArray.push_back(wall4);
	*/
	//---------------------------------------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------------------------------------
	//Miguel Resources
	vector<Resource>::const_iterator resourceit;
	vector<Resource> resourceArray;
	class Resource resource1;
	//sf::Texture textureResource1;
	sf::Texture textureResource1, textureResource2, textureResource3;


	//Miguel Resource Allocation
	/*resource1.resource1 = true;
	resource1.resource2 = false;
	resource1.resource3 = false;
	resource1.rect.setFillColor(sf::Color::Green);
	resource1.rect.setPosition(300, 350);
	resourceArray.push_back(resource1);
	resource1.resource1 = false;
	resource1.resource2 = true;
	resource1.resource3 = false;
	resource1.rect.setFillColor(sf::Color::Blue);
	resource1.rect.setPosition(400, 250);
	resourceArray.push_back(resource1);
	resource1.resource1 = false;
	resource1.resource2 = false;
	resource1.resource3 = true;
	resource1.rect.setFillColor(sf::Color::Red);
	resource1.rect.setPosition(200, 250);
	resourceArray.push_back(resource1);*/
	//Miguel Resource Allocation

	resource1.resource1 = true;
	resource1.resource2 = false;
	resource1.resource3 = false;
	textureResource1.loadFromFile("res1.png");
	resource1.rect.setTexture(&textureResource1);
	//resource1.rect.setFillColor(sf::Color::Green);
	resource1.rect.setPosition(300, 350);
	resourceArray.push_back(resource1);
	resource1.rect.setPosition(300, 400);
	resourceArray.push_back(resource1);
	resource1.resource1 = false;

	resource1.resource1 = false;
	resource1.resource2 = true;
	resource1.resource3 = false;
	textureResource2.loadFromFile("res2.png");
	resource1.rect.setTexture(&textureResource2);
	//resource1.rect.setFillColor(sf::Color::Blue);
	resource1.rect.setPosition(450, 250);
	resourceArray.push_back(resource1);
	resource1.rect.setPosition(400, 400);
	resourceArray.push_back(resource1);
	resource1.resource2 = false;

	resource1.resource1 = false;
	resource1.resource2 = false;
	resource1.resource3 = true;
	textureResource3.loadFromFile("res3.png");
	resource1.rect.setTexture(&textureResource3);
	//resource1.rect.setFillColor(sf::Color::Red);
	resource1.rect.setPosition(200, 250);
	resourceArray.push_back(resource1);
	resource1.rect.setPosition(200, 400);
	resourceArray.push_back(resource1);
	resource1.resource3 = false;
	//---------------------------------------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------------------------------------
	//Gerardo Player Sprite/Sound
	Player player(&playerTexture, sf::Vector2u(3, 3), 0.3f, 100.0f);
	//Assigning Player Footstep Sounds
	if (!player.soundBuf.loadFromFile("foot.wav"))
		std::cout << "can't open sound file" << std::endl;
	player.sound.setBuffer(player.soundBuf);
	player.sound.setVolume(100);
	//---------------------------------------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------------------------------------
	//Cuong
	// Adding enemy texture - need to work more for sprite sheet
	sf::Texture textureEnemy;
	if (!textureEnemy.loadFromFile("ghost.png")) {
		return EXIT_FAILURE;
	}
	// Adding enemy texture type 2 spawning randomly //////////////////// added on 04/01
	sf::Texture textureEnemy2;
	if (!textureEnemy2.loadFromFile("monster.png")) {
		return EXIT_FAILURE;
	}
	
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;
	vector<enemy> enemy1Array;   //////////////////////////////added on 04/01
	

	// Enemy Objects - make 2 enemies try
	class enemy enemy1, enemy2;

	enemy1.sprite.setTexture(textureEnemy);
	enemy1.rect.setPosition(700, 250); // y: 200 is the border with the wall
	enemyArray.push_back(enemy1);
	
	enemy2.sprite.setTexture(textureEnemy2);
	enemy2.rect.setPosition(500, 260);
	enemy1Array.push_back(enemy2); ////////////////////add 04/01 enemy type 2 spawn randomly

	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;

	class projectile projectile1;
	//---------------------------------------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------------------------------------
	//Gerardo Clock
	float deltaTime = 0.0f;
	sf::Clock clock;
	//if(music = 1) play
	//if(music = 2) play

	cout << "Playing background music" << endl;
	audio.backgroundmusic1.play();
	audio.backgroundmusic1.setVolume(25);
	//---------------------------------------------------------------------------------------------------------------
	
	sf::Time elapsed1 = clock1.getElapsedTime();

	player.tower = 3;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		//if (pausedgame == 0) {
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
				if (evnt.type == sf::Event::KeyPressed)
				{
					if (evnt.key.code == sf::Keyboard::Escape)
					{
						std::cout << "Menu Being Displayed" << std::endl;
						if (exitgame == 0)
							exitgame = 1;
						else
							exitgame = 0;
					}
				}
				if (evnt.type == sf::Event::KeyPressed)
				{
					if (evnt.key.code == sf::Keyboard::P) {
						//pausedgame = 1;
						//Pauses the game for alloted seconds you only have so many seconds to pause
						if (pausedgame > 0) {
							sf::sleep(sf::seconds(10));
							std::cout << "Game Paused" << std::endl;
							pausedgame -= 10;
						}
					}

					//Gerardo 4/3 Moved Cuongs Code ---------------------------------------------------------------------
					//Added Gun Sound, and Empty Gun Sound
					if (evnt.key.code == sf::Keyboard::Space) {

						if (player.ammo > 0) {
							audio.gunSound.play();
							std::cout << "playing gunshot " << std::endl;

							if (player.ammo == 0)
								player.ammo = 0;
							else
								player.ammo -= 1;
							std::cout << "ammo left: " << player.ammo << std::endl;

							if (elapsed1.asSeconds() >= 0.1)
							{
								clock1.restart();
								projectile1.rect.setPosition(player.body.getPosition().x + player.body.getSize().x / 2 - projectile1.rect.getSize().x / 2, player.body.getPosition().y + player.body.getSize().y / 2 - projectile1.rect.getSize().y / 2);
								projectile1.direction = player.direction;
								projectileArray.push_back(projectile1);
								std::cout << "space bar hit" << std::endl;
							}
						}
						else {
							audio.gunEmptySound.play();
						}
						//-----------------------------------------------------------------------------------------------------


					}
				}
				//---------------------------------------------------------------------------------------------------------------
				//Gerardo
				//Grabbing Left Button
				if (evnt.type == sf::Event::MouseButtonPressed)
				{
					/*if (evnt.key.code == sf::Mouse::Left)
					{
						std::cout << "left button clicked" << std::endl;
						sf::Vector2i position = sf::Mouse::getPosition(window);
						std::cout << position.x << std::endl;
						std::cout << position.y << std::endl;
					}*/
					if (evnt.key.code == sf::Mouse::Right)
					{
						std::cout << "player towers left" << player.tower << std::endl;
						drawtower = 1;
						sf::Vector2i positionTower = sf::Mouse::getPosition(window);
						std::cout << "right click X(" << positionTower.x << ")" << std::endl;
						std::cout << "right click Y(" << positionTower.y << ")" << std::endl;
						
						//float posx = positionTower.x;
						//float posy = positionTower.y;

						if (player.tower == 3)
						{
							//tower1.setPosition(positionTower.x + 304.0f, positionTower.y + 96.0f);
							tower1.setPosition(positionTower.x, positionTower.y);
							player.tower--;
							std::cout << "Placing tower on x: " << positionTower.x << ",y: " << positionTower.y << std::endl;
							//window.draw(tower1);
						}
						else if (player.tower == 2)
						{
							tower2.setPosition(positionTower.x, positionTower.y);
							player.tower--;
							std::cout << "Placing tower on x: " << positionTower.x << ",y: " << positionTower.y << std::endl;
							//window.draw(tower2);
						}
						else if (player.tower == 1)
						{
							tower3.setPosition(positionTower.x, positionTower.y);
							player.tower--;
							std::cout << "Placing tower on x: " << positionTower.x << ",y: " << positionTower.y << std::endl;
							//window.draw(tower3);
						}
						//tower1.setPosition(positionTower.x, positionTower.y);
						//std::cout << "Placing tower on x: " << positionTower.x << ",y: " << positionTower.y << std::endl;

					}
				}
				//---------------------------------------------------------------------------------------------------------------
			}
		//} 
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H))
		{
			help ^= 1;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
		{
			flag = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
		{
			flag = 1;
		}
		if (flag == 0)
		{
			playerTexture.loadFromFile("char_sprite_walk3.png");
		}
		else if (flag == 1)
		{
			playerTexture.loadFromFile("char_sprite_walk_gun_1.png");
		}
		
		//sf::Vector2f playerpos = player.body.getPosition();
		//std::cout << playerpos.x << std::endl;
		//std::cout << playerpos.y << std::endl;
				
		//---------------------------------------------------------------------------------------------------------------
		//Cuong 04/01
		//Enemy Wall Collision
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			int counter2 = 0;

			for (wallit = wallArray.begin(); wallit != wallArray.end(); wallit++)
			{
				if (enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
				{	//Hit wall
					if (enemyArray[counter].direction == 1) //Up
					{
						enemyArray[counter].faceUp = false;
						enemyArray[counter].rect.move(0, 1);
					}
					else if (enemyArray[counter].direction == 2) //Down
					{
						enemyArray[counter].faceDown = false;
						enemyArray[counter].rect.move(0, -1);
					}
					else if (enemyArray[counter].direction == 3) //Left
					{
						enemyArray[counter].faceLeft = false;
						enemyArray[counter].rect.move(1, 0);
					}
					else if (enemyArray[counter].direction == 4) //Right
					{
						enemyArray[counter].faceRight = false;
						enemyArray[counter].rect.move(-1, 0);
					}
					else
					{
					}
				}
				counter2++;
			}

			counter++;
		}


		//Enemy Wall Collision type 2 ////////////////////////////////////////////////////// added 04/01
		counter = 0;
		for (iter4 = enemy1Array.begin(); iter4 != enemy1Array.end(); iter4++)
		{
			int counter2 = 0;

			for (wallit = wallArray.begin(); wallit != wallArray.end(); wallit++)
			{
				if (enemy1Array[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
				{	//Hit wall
					if (enemy1Array[counter].direction == 1) //Up
					{
						enemy1Array[counter].faceUp = false;
						enemy1Array[counter].rect.move(0, 1);
					}
					else if (enemy1Array[counter].direction == 2) //Down
					{
						enemy1Array[counter].faceDown = false;
						enemy1Array[counter].rect.move(0, -1);
					}
					else if (enemy1Array[counter].direction == 3) //Left
					{
						enemy1Array[counter].faceLeft = false;
						enemy1Array[counter].rect.move(1, 0);
					}
					else if (enemy1Array[counter].direction == 4) //Right
					{
						enemy1Array[counter].faceRight = false;
						enemy1Array[counter].rect.move(-1, 0);
					}
					else
					{
					}
				}
				counter2++;
			}

			counter++;
		}
		//---------------------------------------------------------------------------------------------------------------


		window.setView(player.view);
		
		//start---------------------------------------------------------------------------------------------------------------
		//Miguel
		//Player Wall Collision
		counter = 0;
		for (wallit = wallArray.begin(); wallit != wallArray.end(); wallit++) {
			if (player.body.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
			{
				//Hit wall
				if (player.direction == 1) //Up
				{
					player.faceUp = false;
					player.body.move(0, 1);
				}
				else if (player.direction == 2) //Down
				{
					player.faceDown = false;
					player.body.move(0, -1);
				}
				else if (player.direction == 3) //Left
				{
					player.faceLeft = false;
					player.body.move(1, 0);
				}
				else if (player.direction == 4) //Right
				{
					player.faceRight = false;
					player.body.move(-1, 0);
				}
				else {}
			}
			counter++;
		}

		//Collision with Resources
		counter = 0;
		for (resourceit = resourceArray.begin(); resourceit != resourceArray.end(); resourceit++) {
			if (player.body.getGlobalBounds().intersects(resourceArray[counter].rect.getGlobalBounds()))
			{
				//Hit Resource
				if (resourceArray[counter].resource1 == true) //resource 1
				{
					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					//													4/2/17		Should there be a max HP?  I added it because of the health bar
					player.health += 1;
					if (player.health >= player.maxHealth)
					{
						player.health = player.maxHealth;
					}
					cout << "health: " << player.health << endl;
					resourceArray[counter].gathered = true;
					//////////////////////////////////////////////////////////////////////////////////
				}
				if (resourceArray[counter].resource2 == true) //resource 2
				{
					player.ammo += 1;
					cout << "ammo: " << player.ammo << endl;
					resourceArray[counter].gathered = true;
				}
				if (resourceArray[counter].resource3 == true) //resource 3
				{
					player.tower += 1;
					cout << "tower: " << player.tower << endl;
					resourceArray[counter].gathered = true;
				}
			}
			counter++;
		}
		//Remove Resource
		counter = 0;
		for (resourceit = resourceArray.begin(); resourceit != resourceArray.end(); resourceit++)
		{
			if (resourceArray[counter].gathered == true)
			{
				resourceArray.erase(resourceit);  //clear() removes all
				break;
			}
			counter++;
		}
		//end---------------------------------------------------------------------------------------------------------------
				
		//what is this?
		//window.setView(player.view);

		player.Update(deltaTime);
		window.clear(sf::Color(125, 125, 125));
		window.draw(graphics.background);
		window.draw(graphics.background2);
		window.draw(graphics.background3);
		window.draw(graphics.background4);
		window.draw(graphics.background5);

		//Draw Wall
		counter = 0;
		for (wallit = wallArray.begin(); wallit != wallArray.end(); wallit++)
		{
			wallArray[counter].update();

			window.draw(wallArray[counter].rect);
			window.draw(wallArray[counter].sprite);
			counter++;
		}
		player.Draw(window);

		//window.setPosition(sf::Vector2i(50, 50));
		//Miguel
		//////////////////////////////////////////////////////////////////////////////////////////////////
		//											4/2/17  
		/*window.draw(wall1.sprite);
		window.draw(wall2.sprite);
		window.draw(wall3.sprite);
		window.draw(wall4.sprite);*/
		window.draw(wall0.sprite);
		window.draw(graphics.backgroundTree);
		window.draw(graphics.backgroundExitBottom);
		window.draw(graphics.backgroundExitTop);
		////////////////////////////////////////////////////////////////////////////////////////////////////
/*
		window.draw(wall1.sprite);
		window.draw(wall2.sprite);
		window.draw(wall3.sprite);
		window.draw(wall4.sprite);
*/
		window.draw(graphics.backgroundTree);


		//window.draw(playerRect);

		//start---------------------------------------------------------------------------------------------------------------
		//Cuong 
		// Enemy Vector Array

		//Drawing Enemy
		//sf::Time elapsed1 = clock1.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();

		// Enemy Chasing (AI)
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].chase == true)
			{
				if (elapsed3.asSeconds() >= 0.5) //Changed to .5 on 04/01

				{
					clock3.restart();

					int tempRand = generateRandom(3);
//Added 04/01
					if (tempRand == 2) // Enemy Chases Player
					{
						if (player.body.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 1;
						}
						else if (player.body.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 2;
						}
						else if (player.body.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 3;
						}
						else if (player.body.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 4;
						}
					}
					else // Enemy Chases Player
					{
						if (player.body.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 3;
						}
						else if (player.body.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 4;
						}
						else if (player.body.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 1;
						}
						else if (player.body.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 2;
						}
					}
//------

		/* Removed by Cuong 04/01
					if (tempRand == 1) // Track Player Position
					{
						// Player to Right
						if ((player.body.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(player.body.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
						{
							enemyArray[counter].direction = 3;
						}
						// Player to Left
						if ((player.body.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(player.body.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
						{
							enemyArray[counter].direction = 4;
						}
						// Player to Top
						if ((player.body.getPosition().y < enemyArray[counter].rect.getPosition().y) && (abs(player.body.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
						{
							enemyArray[counter].direction = 1;
						}
						// Player to Bottom
						if ((player.body.getPosition().y > enemyArray[counter].rect.getPosition().y) && (abs(player.body.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
						{
							enemyArray[counter].direction = 2;
						}
					}
					else if (tempRand == 2) // Enemy Chases Player
					{
						if (player.body.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 1;
						}
						else if (player.body.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 2;
						}
						else if (player.body.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 3;
						}
						else if (player.body.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 4;
						}
					}
					else // Enemy Chases Player
					{
						if (player.body.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 3;
						}
						else if (player.body.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 4;
						}
						else if (player.body.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 1;
						}
						else if (player.body.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 2;
						}
					}
		*/

				}
			}

			counter++;
		}

		//Cuong
		//Projectiles colliding with enemies 3/31
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					cout << "bullet collision with enemy" << endl;

					projectileArray[counter].destroy = true;

					enemyArray[counter2].hp -= projectileArray[counter].attackDamage;
					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
					}

					// Chasing
					enemyArray[counter2].chase = true;

				}

				counter2++;
			}

			counter++;
		}

		// Delete Dead Enemy
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].alive == false)
			{
				cout << "Enemy was killed" << endl;
				enemyArray.erase(iter4);
				break;
			}

			counter++;
		}

		// Delete Projectile
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			if (projectileArray[counter].destroy == true)
			{
				cout << "projectile deleted" << endl;
				projectileArray.erase(iter);
				break;
			}

			counter++;
		}

		//--------------------------------------------------------------------------------------------------
		//Cuong
		// Projectile Collides with Enemy type 2 /////////////////////////////////////////added on 04/01
		//start---------------------------------------------------------------------------------------
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemy1Array.begin(); iter4 != enemy1Array.end(); iter4++)
			{
				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemy1Array[counter2].rect.getGlobalBounds()))
				{
					cout << "bullet collision with enemy" << endl;

					projectileArray[counter].destroy = true;

					enemy1Array[counter2].hp -= projectileArray[counter].attackDamage;
					if (enemy1Array[counter2].hp <= 0)
					{
						enemy1Array[counter2].alive = false;
					}

				}

				counter2++;
			}

			counter++;
		}

		// Delete Dead Enemy
		counter = 0;
		for (iter4 = enemy1Array.begin(); iter4 != enemy1Array.end(); iter4++)
		{
			if (enemy1Array[counter].alive == false)
			{
				cout << "Enemy was killed" << endl;
				enemy1Array.erase(iter4);
				break;
			}

			counter++;
		}


		//end-------------------------------------------------------------------------------------------------------------




		// Player Fires Shoot  (Space bar)
		/*
		if (elapsed1.asSeconds() >= 0.1)
		{
			clock1.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (player.ammo <= 0)
					break;
				else {
					projectile1.rect.setPosition(player.body.getPosition().x + player.body.getSize().x / 2 - projectile1.rect.getSize().x / 2, player.body.getPosition().y + player.body.getSize().y / 2 - projectile1.rect.getSize().y / 2);
					projectile1.direction = player.direction;
					projectileArray.push_back(projectile1);
					std::cout << "space bar hit" << std::endl;
				}
				//Gerardo 4/3 Gunshot Sound

			}

		}
		*/

		// Draw Projectiles
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			projectileArray[counter].update(); // Update Projectile
			window.draw(projectileArray[counter].rect);

			counter++;
		}


/*
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].chase == true)
			{
				if (elapsed1.asSeconds() >= 1)
				{
					clock1.restart();
					int tempRand = generateRandom(3);
					if (tempRand == 1) // Track Player Position
					{
						// Player to Right
						if ((player.body.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(player.body.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40)) {
							enemyArray[counter].direction = 3;
						}
						// Player to Left
						if ((player.body.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(player.body.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40)){
							enemyArray[counter].direction = 4;
						}
						// Player to Top
						if ((player.body.getPosition().y < enemyArray[counter].rect.getPosition().y) && (abs(player.body.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40)) {
							enemyArray[counter].direction = 1;
						}
						// Player to Bottom
						if ((player.body.getPosition().y > enemyArray[counter].rect.getPosition().y) && (abs(player.body.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40)) {
							enemyArray[counter].direction = 2;
						}
					}
					else if (tempRand == 2) // Enemy Chases Player
					{
						if (player.body.getPosition().y < enemyArray[counter].rect.getPosition().y)	{
							enemyArray[counter].direction = 1;
						}
						else if (player.body.getPosition().y > enemyArray[counter].rect.getPosition().y) {
							enemyArray[counter].direction = 2;
						}
						else if (player.body.getPosition().x < enemyArray[counter].rect.getPosition().x) {
							enemyArray[counter].direction = 3;
						}
						else if (player.body.getPosition().x > enemyArray[counter].rect.getPosition().x) {
							enemyArray[counter].direction = 4;
						}
					}
					else // Enemy Chases Player
					{
						if (player.body.getPosition().x < enemyArray[counter].rect.getPosition().x) {
							enemyArray[counter].direction = 3;
						}
						else if (player.body.getPosition().x > enemyArray[counter].rect.getPosition().x) {
							enemyArray[counter].direction = 4;
						}
						else if (player.body.getPosition().y < enemyArray[counter].rect.getPosition().y) {
							enemyArray[counter].direction = 1;
						}
						else if (player.body.getPosition().y > enemyArray[counter].rect.getPosition().y) {
							enemyArray[counter].direction = 2;
						}
					}
				}
			}
			counter++;
		}
		*/


		//enemyArray[counter2].chase = true;		//Removed 3/31
		// Draw Enemies
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			enemyArray[counter].update();
			enemyArray[counter].updateMovement();
			//window.draw(enemyArray[counter].rect);
			window.draw(enemyArray[counter].sprite);
			counter++;
		}
		//end---------------------------------------------------------------------------------------------------------------

		//Cuong 
		// Draw Enemies type 2 no chasing - spawn randomly ///////////////////////////////////// added on 04/01
		counter = 0;
		for (iter4 = enemy1Array.begin(); iter4 != enemy1Array.end(); iter4++)
		{
			enemy1Array[counter].update();
			enemy1Array[counter].updateMovement();
			//window.draw(enemyArray[counter].rect);
			window.draw(enemy1Array[counter].sprite);

			counter++;
		}
		//---------------------------------------------------------------------------------------------------------------------



		//start---------------------------------------------------------------------------------------------------------------
		//Miguel Draw Resources
		counter = 0;
		for (resourceit = resourceArray.begin(); resourceit != resourceArray.end(); resourceit++)
		{
			resourceArray[counter].update();

			window.draw(resourceArray[counter].rect);
			window.draw(resourceArray[counter].sprite);
			counter++;
		}

		window.draw(text);
		help == 0 ? window.draw(textHelp) : window.draw(textHelp2);

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//																4/2/17
		//Miguel draw Health Bar
		if (player.health == 5)
			window.draw(spriteHealth5);
		else if (player.health == 4)
			window.draw(spriteHealth4);
		else if (player.health == 3)
			window.draw(spriteHealth3);
		else if (player.health == 2)
			window.draw(spriteHealth2);
		else if (player.health == 1)
			window.draw(spriteHealth1);
		else
			window.draw(spriteHealth0);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//end---------------------------------------------------------------------------------------------------------------
		
		/*if (player.tower == 3)
		{
			window.draw(tower1);
		}
		if (player.tower == 2)
		{
			window.draw(tower2);
		}
		if (player.tower == 1)
		{
			window.draw(tower3);
		}*/
		window.draw(tower1);
		window.draw(tower2);
		window.draw(tower3);

		//displaying Escape Menu
		if (exitgame == 1) window.draw(graphics.menuImage);
		else	graphics.menuImage.setTexture(&graphics.menuTexture);

		window.display();


		}
	return 0;
}


