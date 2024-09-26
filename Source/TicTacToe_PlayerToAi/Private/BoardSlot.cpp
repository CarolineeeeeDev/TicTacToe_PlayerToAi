// Lehan Li's project for Kuluo

#include "BoardSlot.h"
#include "TicTacToe.h"

UBoardSlot::UBoardSlot()
{
	OnClicked.AddDynamic(this, &UBoardSlot::PlayerInteracted);
}

UBoardSlot::~UBoardSlot()
{
	OnClicked.RemoveDynamic(this, &UBoardSlot::PlayerInteracted);
}

void UBoardSlot::PlayerInteracted()
{
	UTicTacToe::Get()->PlayerMove((int)SlotPosition.X, (int)SlotPosition.Y);
	SetIsEnabled(false);
}
