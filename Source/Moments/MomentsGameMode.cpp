// Copyright Epic Games, Inc. All Rights Reserved.

#include "MomentsGameMode.h"
#include "MomentsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMomentsGameMode::AMomentsGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/TwinblastPlayerCharacter"));
	
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
