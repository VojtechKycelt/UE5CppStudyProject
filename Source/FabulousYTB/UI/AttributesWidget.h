// FabulousYTB project by sir Wok

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttributesWidget.generated.h"

/**
 * 
 */
UCLASS()
class FABULOUSYTB_API UAttributesWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindToAttributes();
	
protected:
	UPROPERTY(BlueprintReadOnly)
	float HealthPercent;

	UPROPERTY(BlueprintReadOnly)
	float StaminaPercent;
	
};
