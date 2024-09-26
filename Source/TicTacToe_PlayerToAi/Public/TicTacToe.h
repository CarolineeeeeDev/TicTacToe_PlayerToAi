// Lehan Li's project for Kuluo

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "TicTacToe.generated.h"

class UUniformGridPanel;

USTRUCT(BlueprintType)
struct FImageRows
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<UImage*> ImageRowsArray;
};

UCLASS(Blueprintable)
class TICTACTOE_PLAYERTOAI_API UTicTacToe : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_0;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_1;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_2;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_3;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_4;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_5;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_6;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_7;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UButton* BoardSlot_8;

	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_0;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_1;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_2;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_3;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_4;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_5;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_6;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_7;
	UPROPERTY(BlueprintReadOnly, Category = "UI", meta = (BindWidget))
	UImage* Image_8;


	UPROPERTY(EditDefaultsOnly)
	UTexture2D* PlayerImage;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* AiImage;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BP_EndEvent(int ResultIndex);

	UFUNCTION(BlueprintCallable)
	void ResetData();

	void NativeConstruct() override;

	void PlayerMove(int X, int Y);

	static UTicTacToe* Get();
	static UTicTacToe* Instance;

	int Minimax(int Depth, bool IsMaximizing);
	int EvaluateTempBoard();
	TPair<int, int> FindBestMove();
	bool IsBoardFull();
	void UpdateBoardImages();

private:
	TArray<TArray<int>> Board = { {0,0,0},{0,0,0},{0,0,0} };
	TArray<TArray<UButton*>> ButtonsArray;
	TArray<TArray<UImage*>> ImagesArray;
	int PlayerIndex; // 1 = player; -1 = ai
};
