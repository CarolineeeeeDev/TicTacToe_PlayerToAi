// Lehan Li's project for Kuluo

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "TicTacToe.generated.h"

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
	static UTicTacToe* Instance;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* PlayerImage;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* AiImage;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BP_EndEvent(int ResultIndex);

	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void ResetData();

	void PlayerMove(int X, int Y);

	static UTicTacToe* Get();

	int Minimax(int Depth, bool IsMaximizing);
	int EvaluateTempBoard();
	int EvaluateBoard();//0 = 游戏中， 1 = 玩家获胜， -1 = ai获胜， 2 = 平局
	TPair<int, int> FindBestMove();
	bool IsBoardFull();
	void UpdateBoardImages();

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

private:
	TArray<TArray<int>> Board = { {0,0,0},{0,0,0},{0,0,0} };
	TArray<TArray<UButton*>> ButtonsArray;
	TArray<TArray<UImage*>> ImagesArray;
};
