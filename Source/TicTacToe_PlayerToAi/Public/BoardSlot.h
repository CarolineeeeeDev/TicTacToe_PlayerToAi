// Lehan Li's project for Kuluo

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "BoardSlot.generated.h"

UCLASS()
class TICTACTOE_PLAYERTOAI_API UBoardSlot : public UButton
{
	GENERATED_BODY()

public:
	UBoardSlot();
	virtual ~UBoardSlot() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slot")
	FVector2D SlotPosition;

	UFUNCTION(BlueprintCallable)
	void PlayerInteracted();


protected:
	
};
