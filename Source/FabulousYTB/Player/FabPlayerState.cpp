// FabulousYTB project by sir Wok


#include "FabPlayerState.h"
#include "AbilitySystem/FabulousAbilitySystemComponent.h"
#include "AbilitySystem/FabulousAttributeSet.h"

// Sets default values
AFabPlayerState::AFabPlayerState()
{
	SetNetUpdateFrequency(100.f); //default frequency is low and can lag when updating attributes

	
	AbilitySystemComponent = CreateDefaultSubobject<UFabulousAbilitySystemComponent>("AbilitySystem_Component");

	//Gameplay effects are replicated only to owner of character
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UFabulousAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AFabPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UFabulousAttributeSet* AFabPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

