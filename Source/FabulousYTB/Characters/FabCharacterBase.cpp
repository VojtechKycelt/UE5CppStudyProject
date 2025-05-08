// FabulousYTB project by sir Wok


#include "FabCharacterBase.h"


// Sets default values
AFabCharacterBase::AFabCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFabCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFabCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

