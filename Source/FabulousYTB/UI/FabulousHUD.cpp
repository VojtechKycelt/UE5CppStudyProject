// FabulousYTB project by sir Wok


#include "FabulousHUD.h"

void AFabulousHUD::Init()
{
	AttributesWidget = CreateWidget<UAttributesWidget>(GetOwningPlayerController(), AttributesWidgetClass);
	AttributesWidget->BindToAttributes();
	AttributesWidget->AddToViewport();
}
