﻿// FabulousYTB project by sir Wok


#include "FabulousAbilitySystemComponent.h"


// Sets default values for this component's properties
UFabulousAbilitySystemComponent::UFabulousAbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
	// ...
}

