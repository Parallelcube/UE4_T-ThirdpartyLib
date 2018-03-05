#ifndef SoundManager_Fmod_H
#define SoundManager_Fmod_H

#include <string>

namespace FMOD 
{
	class System;
	class Channel;
	class Sound;
};

class SoundManager_Fmod
{
public:
	SoundManager_Fmod();
	~SoundManager_Fmod();

	int initialize();
	int loadSoundFromPath(std::string pathToFile);
	int loadSoundFromMemory(char* memoryPtr, unsigned int memorySize);
	void playSound();
	void pauseSound(bool unPause = false);
		
private:
	FMOD::System* _system;
	FMOD::Channel* _channel;
	FMOD::Sound* _sound;

};

#endif
