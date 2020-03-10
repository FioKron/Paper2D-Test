// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Paper2DTestGameMode.h"
#include "Paper2DTestCharacter.h"

APaper2DTestGameMode::APaper2DTestGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = APaper2DTestCharacter::StaticClass();	
}
