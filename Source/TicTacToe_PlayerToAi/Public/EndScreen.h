// Lehan Li's project for Kuluo

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "EndScreen.generated.h"


UCLASS(Blueprintable)
class TICTACTOE_PLAYERTOAI_API UEndScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ResultText; 
};
