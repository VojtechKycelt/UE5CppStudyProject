// FabulousYTB project by sir Wok


#include "FabCharacterBase.h"
#include "AbilitySystem/FabulousAbilitySystemComponent.h"

// Sets default values
AFabCharacterBase::AFabCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* AFabCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UFabulousAttributeSet* AFabCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AFabCharacterBase::GiveDefaultAbilities()
{
	//check if ASC was initialized
	check(AbilitySystemComponent);

	//only give abilities if local role of the actor has network authority
	if (!HasAuthority()) return;

	//iterate over all default ability classes
	for (TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		//create gameplay ability spec
		const FGameplayAbilitySpec AbilitySpec(AbilityClass,1);

		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
	
}

void AFabCharacterBase::InitDefaultAttributes()
{
	if (!AbilitySystemComponent || !DefaultAttributeEffect) return;

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	if (SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

