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

	//Gerardo 4/3 Gun Sound Empty Gun Sound
	sf::Sound gunSound;
	sf::SoundBuffer gunSoundBuffer;

	sf::Sound gunEmptySound;
	sf::SoundBuffer gunEmptySoundBuffer;

	sf::Sound gunPickupSound;
	sf::SoundBuffer gunPickupBuffer;

	sf::Music backgroundmusic1;


};

