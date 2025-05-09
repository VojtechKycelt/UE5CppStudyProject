// FabulousYTB project by sir Wok

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "FabulousAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#define NUMERIC_VALUE(AttributeSetName, PropertyName) \
	AttributeSetName->Get##PropertyName##Attribute().GetNumericValue(AttributeSetName)

/**
 * 
 */
UCLASS()
class FABULOUSYTB_API UFabulousAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UFabulousAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(BlueprintReadOnly, Replicated = OnRep_Health, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UFabulousAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Replicated = OnRep_MaxHealth, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UFabulousAttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, Replicated = OnRep_Stamina, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UFabulousAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, Replicated = OnRep_MaxStamina, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UFabulousAttributeSet, MaxStamina);

	UPROPERTY(BlueprintReadOnly, Replicated = OnRep_Strength, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UFabulousAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, Replicated = OnRep_MaxStrength, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS(UFabulousAttributeSet, MaxStrength);


	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	UFUNCTION()
	void OnRep_MaxStrength(const FGameplayAttributeData& OldMaxStrength) const;
};
