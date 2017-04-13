#include "Graphic.h"



Graphic::Graphic()
{
	//Changed cave image 4/4
	//Main Background
	background.setSize(sf::Vector2f(720.0f, 480.0f));
	background.setPosition(0.0f, 0.0f);
	backgroundImage.loadFromFile("cave3.png");
	background.setTexture(&backgroundImage);

	//East Background
	background2.setSize(sf::Vector2f(720.0f, 480.0f));
	background2.setPosition(720.0f, 0.0f);
	backgroundImage2.loadFromFile("cave_side.png");
	background2.setTexture(&backgroundImage2);

	//South Background
	background3.setSize(sf::Vector2f(720.0f, 480.0f));
	background3.setPosition(0.0f, 480.0f);
	backgroundImage3.loadFromFile("cave.png");
	background3.setTexture(&backgroundImage3);

	//Gerardo 4/4
	//Player starts at west
	//West Background
	background4.setSize(sf::Vector2f(720.0f, 480.0f));
	background4.setPosition(-720.0f, 0.0f);
	backgroundImage4.loadFromFile("cave_side.png");
	background4.setTexture(&backgroundImage4);

	//Gerardo 4/4
	//South west background
	background6.setSize(sf::Vector2f(720.0f, 480.0f));
	background6.setPosition(-720.0f, 480.0f);
	backgroundImage6.loadFromFile("cave_side.png");
	background6.setTexture(&backgroundImage6);

	//South East background 4/4
	background7.setSize(sf::Vector2f(720.0f, 480.0f));
	background7.setPosition(720.0f, 480.0f);
	backgroundImage7.loadFromFile("cave_side.png");
	background7.setTexture(&backgroundImage7);


	/*Gerardo North removed 4/4
	//North Background
	background5.setSize(sf::Vector2f(720.0f, 480.0f));
	background5.setPosition(0.0f, -480.0f);
	backgroundImage5.loadFromFile("cave_side.png");
	background5.setTexture(&backgroundImage5);
	*/
	//Transparent Tree
	backgroundTree.setSize(sf::Vector2f(150.0f, 150.0f));
	backgroundTree.setPosition(500.0f, 100.0f);
	treeTexture.loadFromFile("dark_tree.png");
	backgroundTree.setTexture(&treeTexture);

	///////////////////////////////////////////////////////////////////////////////////////
	//Miguel									4/2/17
	//CenterCenter Bottom Exit
	backgroundExitBottom.setPosition(50, 340);
	backgroundExitBottom.setSize(sf::Vector2f(100, 140));
	exitbottomTexture.loadFromFile("exitBottom.png");
	backgroundExitBottom.setTexture(&exitbottomTexture);

	//CenterCenter Top Exit
	backgroundExitTop.setPosition(310, 0);
	backgroundExitTop.setSize(sf::Vector2f(100, 160));
	exittopTexture.loadFromFile("exitTop.png");
	backgroundExitTop.setTexture(&exittopTexture);

	//CenterSouth Top Exit
	backgroundExitTop2.setPosition(50, 480);
	backgroundExitTop2.setSize(sf::Vector2f(100, 160));
	backgroundExitTop2.setTexture(&exittopTexture);
	/////////////////////////////////////////////////////////////////////////////////////////



	//Menu Image
	menuImage.setSize(sf::Vector2f(720.0f, 480.0f));
	menuTexture.loadFromFile("menu_1.png");
	menuImage.setTexture(&menuTexture);




}


Graphic::~Graphic()
{



}
