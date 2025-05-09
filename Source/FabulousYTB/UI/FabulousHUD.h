// FabulousYTB project by sir Wok

#pragma once

#include "CoreMinimal.h"
#include "AttributesWidget.h"
#include "GameFramework/HUD.h"
#include "FabulousHUD.generated.h"

class UAttributesWidget;
/**
 * 
 */
UCLASS()
class FABULOUSYTB_API AFabulousHUD : public AHUD
{
	GENERATED_BODY()

public:
	void Init();
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAttributesWidget> AttributesWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UAttributesWidget> AttributesWidget;
};
