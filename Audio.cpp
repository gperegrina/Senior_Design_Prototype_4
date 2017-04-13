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
	//Gerardo 4/3
	//Gun Shot Sound
	if (!gunSoundBuffer.loadFromFile("gunshot.wav"))
		std::cout << "Unable to load gunshot" << std::endl;
	gunSound.setBuffer(gunSoundBuffer);
	gunSound.setVolume(100);

	if (!gunEmptySoundBuffer.loadFromFile("gunEmpty.wav"))
		std::cout << "Unable to load gun empty" << std::endl;
	gunEmptySound.setBuffer(gunEmptySoundBuffer);
	gunEmptySound.setVolume(100);

	if (!gunPickupBuffer.loadFromFile("gunload.wav"))
		std::cout << "Unable to load gun pickup" << std::endl;
	gunPickupSound.setBuffer(gunPickupBuffer);
	gunPickupSound.setVolume(80);

	//Loading in sound for Background Music
	if (!backgroundmusic1.openFromFile("Punks.wav"))
		std::cout << "Unable to load Music" << std::endl;

}


Audio::~Audio()
{
}
