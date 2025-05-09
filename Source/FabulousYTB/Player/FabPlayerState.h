// FabulousYTB project by sir Wok

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "FabPlayerState.generated.h"

//Store the Ability System Component of the player controlled actor on the player state not to get lost with respawn
class UFabulousAbilitySystemComponent;
class UFabulousAttributeSet;

UCLASS()
class FABULOUSYTB_API AFabPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFabPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UFabulousAttributeSet* GetAttributeSet() const;

protected:
	UPROPERTY()
	TObjectPtr<UFabulousAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UFabulousAttributeSet> AttributeSet;
};
