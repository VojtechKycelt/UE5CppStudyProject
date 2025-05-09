// FabulousYTB project by sir Wok

#pragma once

#include "CoreMinimal.h"
#include "FabCharacterBase.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class FABULOUSYTB_API APlayerCharacter : public AFabCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	virtual void Tick(float DeltaSeconds) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void InitAbilitySystemComponent();
	void InitHud() const;
};


