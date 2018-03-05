// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SoundManager_Fmod.h"
#include <memory>

#include "UObject/NoExportTypes.h"
#include "AudioManager.generated.h"

UCLASS(Blueprintable, BlueprintType)
class TUTORIAL_SPECTRUM_API UAudioManager : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = Init)
		int32 InitializeManager();
		
	UFUNCTION(BlueprintCallable, Category = Actions)
		int32 PlaySong();
	UFUNCTION(BlueprintCallable, Category = Actions)
		void PauseSong(bool unPause);

	UFUNCTION(BlueprintPure, Category = Access)
		const FString& GetSongName() const;

	UAudioManager();
	~UAudioManager();

private:

	std::unique_ptr<SoundManager_Fmod> _soundManager;
	FString currentSongName;

};