#include "SoundManager_Fmod.h"

#include "fmod.hpp"

#include <string>

using namespace std;

SoundManager_Fmod::SoundManager_Fmod():_system(NULL),_channel(NULL),_sound(NULL)
{

}

int SoundManager_Fmod::initialize()
{
	FMOD_RESULT result = FMOD::System_Create(&_system);
	if (result != FMOD_OK)
	{
		return result;
	}
	else
	{
		_system->init(1, FMOD_INIT_NORMAL, NULL);
	}

	return 0;
}

SoundManager_Fmod::~SoundManager_Fmod()
{
	if (_sound)
	{
		_sound->release();
	}

	if (_system)
	{
		_system->close();
		_system->release();
	}
}

int SoundManager_Fmod::loadSoundFromPath(std::string pathToFile)
{
	FMOD_RESULT result = _system->createSound(pathToFile.c_str(), FMOD_LOOP_NORMAL, 0, &_sound);
	return result;
}

int SoundManager_Fmod::loadSoundFromMemory(char* memoryPtr, unsigned int memorySize)
{
	FMOD_CREATESOUNDEXINFO sndinfo = { 0 };
	sndinfo.cbsize = sizeof(sndinfo);
	sndinfo.length = memorySize;

	FMOD_RESULT result = _system->createSound(memoryPtr, FMOD_OPENMEMORY | FMOD_LOOP_NORMAL, &sndinfo, &_sound);
	return result;
}

void SoundManager_Fmod::playSound()
{
	_system->playSound(_sound, 0, false, &_channel);
}

void SoundManager_Fmod::pauseSound(bool unPause)
{
	bool isPaused;
	_channel->getPaused(&isPaused);
	if (isPaused && unPause)
	{
		_channel->setPaused(false);
	}
	else if(!isPaused && !unPause)
	{
		_channel->setPaused(true);
	}
}
