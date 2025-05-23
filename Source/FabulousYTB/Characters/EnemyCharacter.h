﻿// FabulousYTB project by sir Wok

#pragma once

#include "CoreMinimal.h"
#include "FabCharacterBase.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class FABULOUSYTB_API AEnemyCharacter : public AFabCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
