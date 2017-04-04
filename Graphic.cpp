#include "Graphic.h"



Graphic::Graphic()
{

	//Main Background
	background.setSize(sf::Vector2f(720.0f, 480.0f));
	background.setPosition(0.0f, 0.0f);
	backgroundImage.loadFromFile("cave.png");
	background.setTexture(&backgroundImage);

	//East Background
	background2.setSize(sf::Vector2f(720.0f, 480.0f));
	background2.setPosition(720.0f, 0.0f);
	backgroundImage2.loadFromFile("mario.png");
	background2.setTexture(&backgroundImage2);
	
	//South Background
	background3.setSize(sf::Vector2f(720.0f, 480.0f));
	background3.setPosition(0.0f, 480.0f);
	backgroundImage3.loadFromFile("cave.png");
	background3.setTexture(&backgroundImage3);

	//West Background
	background4.setSize(sf::Vector2f(720.0f, 480.0f));
	background4.setPosition(-720.0f, 0.0f);
	backgroundImage4.loadFromFile("mario.png");
	background4.setTexture(&backgroundImage4);

	//North Background
	background5.setSize(sf::Vector2f(720.0f, 480.0f));
	background5.setPosition(0.0f, -480.0f);
	backgroundImage5.loadFromFile("mario.png");
	background5.setTexture(&backgroundImage5);

	//Transparent Tree
	backgroundTree.setSize(sf::Vector2f(150.0f, 150.0f));
	backgroundTree.setPosition(500.0f, 100.0f);
	treeTexture.loadFromFile("dark_tree.png");
	backgroundTree.setTexture(&treeTexture);
	
	///////////////////////////////////////////////////////////////////////////////////////
	//Miguel									4/2/17
	//Bottom Exit
	backgroundExitBottom.setPosition(50, 340);
	backgroundExitBottom.setSize(sf::Vector2f(100, 140));
	exitbottomTexture.loadFromFile("exitBottom.png");
	backgroundExitBottom.setTexture(&exitbottomTexture);

	//Top Exit
	backgroundExitTop.setPosition(300, 0);
	backgroundExitTop.setSize(sf::Vector2f(100, 160));
	exittopTexture.loadFromFile("exitTop.png");
	backgroundExitTop.setTexture(&exittopTexture);
	/////////////////////////////////////////////////////////////////////////////////////////



	//Menu Image
	menuImage.setSize(sf::Vector2f(720.0f, 480.0f));
	menuTexture.loadFromFile("menu_1.png");
	menuImage.setTexture(&menuTexture);




}


Graphic::~Graphic()
{



}
