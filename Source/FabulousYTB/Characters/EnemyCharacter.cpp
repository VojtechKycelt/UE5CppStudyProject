// FabulousYTB project by sir Wok


#include "EnemyCharacter.h"
#include "AbilitySystem/FabulousAbilitySystemComponent.h"
#include "AbilitySystem/FabulousAttributeSet.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	AbilitySystemComponent = CreateDefaultSubobject<UFabulousAbilitySystemComponent>("AbilitySystem_Component");

	//Gameplay effects are never replicated to anyone
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UFabulousAttributeSet>("AttributeSet");

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	//ASC needs to be initialized both on server and the client
	AbilitySystemComponent->InitAbilityActorInfo(this,this); //Owner and Avatar both same
	GiveDefaultAbilities();
	InitDefaultAttributes();
}


