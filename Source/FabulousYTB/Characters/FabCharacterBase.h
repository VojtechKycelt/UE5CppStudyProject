// FabulousYTB project by sir Wok

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "FabCharacterBase.generated.h"

//forward declaration for FabCharacterBase
//as long as don't dereference a pointer, we can do this instead of including whole file header
class UGameplayAbility;
class UFabulousAbilitySystemComponent;
class UFabulousAttributeSet;
class UGameplayEffect;

UCLASS()
class FABULOUSYTB_API AFabCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AFabCharacterBase();
	//IAbilitySystemInterface function - returns the ASC (Ability System Component)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UFabulousAttributeSet* GetAttributeSet() const;
	
protected:
	void GiveDefaultAbilities();
	void InitDefaultAttributes();
	//All characters are to be derived from FabCharacterBase and all are to have reference to Ability System Component
	UPROPERTY()
	TObjectPtr<UFabulousAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UFabulousAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;
};
