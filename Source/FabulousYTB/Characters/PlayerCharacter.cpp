// FabulousYTB project by sir Wok

#include "PlayerCharacter.h"
#include "AbilitySystem/FabulousAbilitySystemComponent.h"
#include "Player/FabPlayerState.h"

//can be directly imported because in FabulousYTB.Build.cs we included this folder as public
//debug macros like UE_LOG, SPHERE, LINE, etc.
#include "FabMacros.h"
#include "UI/FabulousHUD.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SPHERE_TICK(GetActorLocation());
	LINE_TICK(GetActorLocation(), FVector(2200.f, 700.f, 150.f));
}

void APlayerCharacter::InitAbilitySystemComponent()
{
	//Get Player State and cast it to AFabPlayerState
	AFabPlayerState* FabPlayerState = GetPlayerState<AFabPlayerState>();

	//check if that's a null pointer so we can dereference it
	check(FabPlayerState);

	//next we can get Ability System Component from Player State, check cast and initialize our player characters var
	AbilitySystemComponent = CastChecked<UFabulousAbilitySystemComponent>(FabPlayerState->GetAbilitySystemComponent());
	//Owner is PlayerState so that the ASC is not lost when respawning or changing Avatar
	//Player is only the Avatar
	AbilitySystemComponent->InitAbilityActorInfo(FabPlayerState, this);
	AttributeSet = FabPlayerState->GetAttributeSet();
}

void APlayerCharacter::InitHud() const
{
	if (const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (AFabulousHUD* FabulousHUD = Cast<AFabulousHUD>(PlayerController->GetHUD()))
		{
			FabulousHUD->Init();
		}
	}
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities(); //we only want to give abilities on the server (idk why)
	InitDefaultAttributes(); //init default attributes on the server
	InitHud();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//initialize on client as well
	InitAbilitySystemComponent();
	InitDefaultAttributes(); //init default attributes on the client
	InitHud();

}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//DEBUG
	// UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(__FUNCTION__));
	// UE_LOG(LogTemp, Error, TEXT("dsadasd"));
	//
	// GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Purple,TEXT("OnScreen"));
	// PRINT("macro hahahaha, %s", *FString(__FUNCTION__));

	FVector TargetLocation(2200.f, 700.f, 150.f);
	SPHERE(TargetLocation);
	LINE(GetActorLocation(), TargetLocation);
}
