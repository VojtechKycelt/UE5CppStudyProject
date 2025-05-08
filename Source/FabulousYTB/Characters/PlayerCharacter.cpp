// FabulousYTB project by sir Wok


#include "PlayerCharacter.h"

#include "FabMacros.h"
//can be directly imported because in FabulousYTB.Build.cs we included this folder as public

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
	LINE_TICK(GetActorLocation(), FVector(0,0,0));
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(__FUNCTION__));
	UE_LOG(LogTemp, Error, TEXT("dsadasd"));

	GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Purple,TEXT("OnScreen"));
	PRINT("macro hahahaha, %s", *FString(__FUNCTION__));

	FVector TargetLocation(2200.f, 700.f, 150.f);
	SPHERE(TargetLocation);
	LINE(GetActorLocation(),TargetLocation);
}

