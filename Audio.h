#pragma once
#include <SFML\Audio.hpp>
#include <iostream>

class Audio
{
	public:
	Audio();
	~Audio();

	//Sound settings
	sf::SoundBuffer mainsoundBuf;
	sf::Sound mainSound;
	
	sf::Sound attackSound;
	sf::SoundBuffer attackSoundBuf;

	sf::Music backgroundmusic1;


};

