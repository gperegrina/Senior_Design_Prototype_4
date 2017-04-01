#include "Audio.h"

Audio::Audio()
{

	//Initializing Background Music
	//Not needed since using sf::Music now...
	/*
	std::cout << "loading in background music" << std::endl;
	if (!mainsoundBuf.loadFromFile("Punks.wav"))
		std::cout << "can't open sound file" << std::endl;
	else
		std::cout << "sound loaded" << std::endl;
	mainSound.setBuffer(mainsoundBuf);
	*/

	//Loading in sound for Background Music
	if (!backgroundmusic1.openFromFile("Punks.wav"))
		std::cout << "Unable to load Music" << std::endl;

}


Audio::~Audio()
{
}
