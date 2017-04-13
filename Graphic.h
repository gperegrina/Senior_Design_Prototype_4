#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Graphic
{
public:
	Graphic();
	~Graphic();

	//Starting background image
	sf::RectangleShape background;
	sf::Texture backgroundImage;

	//East background image
	sf::RectangleShape background2;
	sf::Texture backgroundImage2;
	//South background image
	sf::RectangleShape background3;
	sf::Texture backgroundImage3;
	//West background image
	sf::RectangleShape background4;
	sf::Texture backgroundImage4;
	//North background image
	sf::RectangleShape background5;
	sf::Texture backgroundImage5;
	//Southwest background
	sf::RectangleShape background6;
	sf::Texture backgroundImage6;
	//Southeast background
	sf::RectangleShape background7;
	sf::Texture backgroundImage7;

	sf::RectangleShape backgroundTree;
	sf::Texture treeTexture;

	////////////////////////////////////////////////////////////////////
	//						4/2/17
	//ExitTop image
	sf::RectangleShape backgroundExitTop;
	sf::RectangleShape backgroundExitTop2;
	sf::Texture exittopTexture;
	//ExitBottom image
	sf::RectangleShape backgroundExitBottom;
	sf::Texture exitbottomTexture;
	////////////////////////////////////////////////////////////////////

	sf::RectangleShape menuImage;
	sf::Texture menuTexture;



};

