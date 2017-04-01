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

	sf::RectangleShape backgroundTree;
	sf::Texture treeTexture;



	sf::RectangleShape menuImage;
	sf::Texture menuTexture;



};

