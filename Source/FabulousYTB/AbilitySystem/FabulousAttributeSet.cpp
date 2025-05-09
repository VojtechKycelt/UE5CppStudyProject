// FabulousYTB project by sir Wok


#include "FabulousAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "FabMacros.h"

UFabulousAttributeSet::UFabulousAttributeSet()
{
	InitHealth(69.f);
}

void UFabulousAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UFabulousAttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UFabulousAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UFabulousAttributeSet, Stamina, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UFabulousAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UFabulousAttributeSet, Strength, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UFabulousAttributeSet, MaxStrength, COND_None, REPNOTIFY_Always)
}

void UFabulousAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
}

void UFabulousAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)

{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}

	// We can get bunch of info about the ASC of the instigator or his location etc...
	// UAbilitySystemComponent* ASC = Data.EffectSpec.GetContext().GetInstigatorAbilitySystemComponent();
	// AActor* ASCOwner = ASC->AbilityActorInfo->OwnerActor.Get();
	// ASCOwner->GetActorLocation();
	
}

void UFabulousAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	//inform GAS about the attribute change
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabulousAttributeSet, Health, OldHealth);
}

void UFabulousAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabulousAttributeSet, MaxHealth, OldMaxHealth);
}

void UFabulousAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabulousAttributeSet, Stamina, OldStamina);
}

void UFabulousAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabulousAttributeSet, MaxStamina, OldMaxStamina);
}

void UFabulousAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabulousAttributeSet, Strength, OldStrength);
}

void UFabulousAttributeSet::OnRep_MaxStrength(const FGameplayAttributeData& OldMaxStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabulousAttributeSet, MaxStrength, OldMaxStrength);
}
