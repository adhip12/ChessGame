#include "ChessState.hh"

int main()
{
	ChessGame *game1 = new ChessGame();
	//game1.PrintPieceValues();
	game1->PrintBoardValues();
	game1->PlayerMovePiece(White, KNIGHT1, Position(3,4));
	game1->PrintBoardValues();

	return 0;
}
