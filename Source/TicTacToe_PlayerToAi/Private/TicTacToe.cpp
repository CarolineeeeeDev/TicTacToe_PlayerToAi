// Lehan Li's project for Kuluo

#include "TicTacToe.h"
#include "Styling/SlateBrush.h"

UTicTacToe* UTicTacToe::Instance = nullptr;

void UTicTacToe::ResetData()
{
    for (auto Buttons : ButtonsArray)
    {
        for(auto ButtonInstance : Buttons) ButtonInstance->SetIsEnabled(true);
    }
    UTexture2D* EmptyTexture = NewObject<UTexture2D>();
    for (auto Images : ImagesArray)
    {
        for (auto ImageInstance : Images) ImageInstance->SetBrushFromTexture(EmptyTexture);
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            Board[i][j] = 0;
        }
    }
}

void UTicTacToe::NativeConstruct()
{
	Super::NativeConstruct();

    //Initialization
	Instance = this;
    ButtonsArray = { {BoardSlot_0, BoardSlot_1, BoardSlot_2},{BoardSlot_3, BoardSlot_4,
        BoardSlot_5},{BoardSlot_6, BoardSlot_7, BoardSlot_8} };
    ImagesArray = { {Image_0, Image_1, Image_2},{Image_3, Image_4,
        Image_5},{Image_6, Image_7, Image_8} };
}

void UTicTacToe::PlayerMove(int X, int Y)
{
    Board[X][Y] = 1;
    UpdateBoardImages();

    if (!IsBoardFull())
    {
        TPair<int, int> aiMove = FindBestMove();
        if (aiMove.Key != -1 && aiMove.Value != -1)
        {
            Board[aiMove.Key][aiMove.Value] = -1;
            ButtonsArray[aiMove.Key][aiMove.Value]->SetIsEnabled(false);
            UpdateBoardImages();
        }
    }
}

UTicTacToe* UTicTacToe::Get()
{
	return Instance;
}

int UTicTacToe::Minimax(int Depth, bool IsMaximizing)
{
    int Score = EvaluateTempBoard();

    if (Score == 10)
    {
        BP_EndEvent(-1);
        return Score - Depth; // AI wins
    }
    if (Score == -10)
    {
        BP_EndEvent(1);
        return Score + Depth; // Player wins
    }
    if (IsBoardFull())
    {
        BP_EndEvent(0);
        return 0; // Tie
    }

    if (IsMaximizing)
    {
        int bestVal = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Board[i][j] == 0) // 空位
                {
                    Board[i][j] = -1; // AI
                    bestVal = FMath::Max(bestVal, Minimax(Depth + 1, !IsMaximizing));
                    Board[i][j] = 0; // 撤销移动
                }
            }
        }
        return bestVal;
    }
    else
    {
        int bestVal = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Board[i][j] == 0) // 空位
                {
                    Board[i][j] = 1; // 玩家
                    bestVal = FMath::Min(bestVal, Minimax(Depth + 1, !IsMaximizing));
                    Board[i][j] = 0; // 撤销移动
                }
            }
        }
        return bestVal;
    }
}

int UTicTacToe::EvaluateTempBoard()
{
    // 评估当前棋盘
    for (int row = 0; row < 3; row++)
    {
        if (Board[row][0] == Board[row][1] && Board[row][1] == Board[row][2])
        {
            if (Board[row][0] == -1) return 10; // AI wins
            if (Board[row][0] == 1) return -10; // Player wins
        }
    }

    for (int col = 0; col < 3; col++)
    {
        if (Board[0][col] == Board[1][col] && Board[1][col] == Board[2][col])
        {
            if (Board[0][col] == -1) return 10; // AI wins
            if (Board[0][col] == 1) return -10; // Player wins
        }
    }

    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])
    {
        if (Board[0][0] == -1) return 10; // AI wins
        if (Board[0][0] == 1) return -10; // Player wins
    }

    if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])
    {
        if (Board[0][2] == -1) return 10; // AI wins
        if (Board[0][2] == 1) return -10; // Player wins
    }

    return 0; // 平局
}

TPair<int, int> UTicTacToe::FindBestMove()
{
    int bestVal = -1000;
    TPair<int, int> bestMove = TPair<int, int>(-1, -1);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] == 0) // 空位
            {
                Board[i][j] = -1; // AI
                int moveVal = Minimax(0, false);
                Board[i][j] = 0; // 撤销移动

                if (moveVal > bestVal)
                {
                    bestMove = TPair<int, int>(i, j);
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

bool UTicTacToe::IsBoardFull()
{
    for (const auto& Row : Board)
    {
        for (const auto& Cell : Row)
        {
            if (Cell == 0) // 如果有空位
            {
                return false; // 棋盘未满
            }
        }
    }
    return true; // 棋盘已满
}

void UTicTacToe::UpdateBoardImages()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (Board[i][j] == 1) ImagesArray[i][j]->SetBrushFromTexture(PlayerImage);
            else if (Board[i][j] == -1) ImagesArray[i][j]->SetBrushFromTexture(AiImage);
        }
    }
}

