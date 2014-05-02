#include "ChessGame.hh"
#include <iostream>
#include <assert.h>

ChessGame::ChessGame() : currMove(0), nextTurn (White) 
{
	player1 = new Player (White);
	player2 = new Player (Black);

	// Initialize the Chess board, and mark the initial positions with the Piece info.
	memset (chess_board, 0, sizeof(chess_board));

	for (int type = 1; type <= NUM_PIECES; type++) {
		SetChessBoardAndMoveHistoryByPieceType ((PieceType)type, White); 
		SetChessBoardAndMoveHistoryByPieceType ((PieceType)type, Black); 
	}
	/* This will push back the Initial setup to the Move History */
	moveHistory.push_back(pieceBoard);

}

ChessGame::~ChessGame ()
{
	delete player1;
	delete player2;
}

int ChessGame::SetChessBoardAndMoveHistoryByPieceType (const PieceType type, const Color color)
{
	int x = 0, y = 0; 
	Position pos;
	/* Get Player object from color */
	Player *tmpPlayer = GetPlayerFromColor(color);

	if (tmpPlayer == NULL) {
		return INVALID_PLAYER_ERROR;
	}

	/* Get the Piece object from PieceType */
	const Piece &piece = tmpPlayer->GetPieceObjectFromPieceType(type);
	/* Get position */
	pos = piece.GetPosition();

	if (pos.InvalidPositionForPieceType()) {
		return POSITION_ERROR;
	}

	x = pos.GetX();	
	y = pos.GetY();	

	assert(piece.GetPieceType() == type);
	if (color == White) {
		/* Set Chess Board */
		chess_board[x][y] = type;
		/* Set Move History */
		pieceBoard.at(type - 1) = piece;
	} else if (color == Black) {
		chess_board[x][y] = type + 16;
		pieceBoard.at(type  + 16 - 1) = piece;
	}
	return SUCCESS;

}


int ChessGame::GetChessBoardValuesIfTaken (int x, int y)
{
	return chess_board[x][y];

}

void ChessGame::PrintBoardValues() 
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout <<" "<<GetChessBoardValuesIfTaken(i,j);
		}
		cout <<endl<<"------------------------"<<endl;
	}
}

Color ChessGame::GetPieceColorFromPieceType(int value)
{
	if ((value < 0) || (value > BLACK_PIECE_TYPE_MAX)) {
		return INVALID_PIECE_COLOR;
	}
	if (value > WHITE_PIECE_TYPE_MAX) {
		return Black;
	} else {
		return White;
	}
}

Player *ChessGame::GetPlayerFromColor(Color color)
{
	if (color == White) {
		return player1;
	} else if (color == Black) {
		return player2;
	} else {
		return NULL;
	}

}

void ChessGame::SetChessBoardPosition (Position pos, PieceType value)
{
	int x = pos.GetX();
	int y = pos.GetY();
	chess_board[x][y] = value;

}

int ChessGame::PlayerMovePiece (const Color color, const PieceType pieceType, const Position pos)
{
	int value = 0;
	Color targetColor;
	Player *tmpPlayer = NULL;
	int currentMove = 0;

	/* Check if this Turn is Valid */
	if (GetNextTurn() != color) {
		return NOT_CORRECT_PLAYER_ERROR;
	}

#if 0
	/* Check if Piece is Valid */
	if (CheckIfPieceTypeIsValid(pieceType) == INVALID_PIECE_TYPE) {
		return INVALID_PIECE_TYPE_ERROR;
	}
	/* Check if POsition is Valid */
	if (pos.InvalidPositionForPieceType()) {
		return POSITION_ERROR;
	}
#endif
	/* If the Position is taken by another piece. */
	if ((value = GetChessBoardValuesIfTaken(pos.GetX(), pos.GetY())) != NOT_TAKEN) 	      {	
		/* If the color of the piece at pos is the same as the one making 
		   the move, then the move is Invalid 
		 */
		if ((targetColor = GetPieceColorFromPieceType(value)) == color) {
			return INVALID_MOVE_ERROR;
		}
		
		/* Get the Player : White or Black */
		tmpPlayer = GetPlayerFromColor(targetColor);

		if (tmpPlayer == NULL) {
			return INVALID_PLAYER_ERROR;
		}
		/*Kill the Piece of the opposite player */
		Piece &piece = tmpPlayer->GetPieceObjectFromPieceType((PieceType) 									(value % 16));
		/* Mark the position of the piece as Invalid */
		piece.SetPosition(Position(INV_POS, INV_POS));
		/* Set Killed status */
		piece.SetKilledStatus (true);
		/*Set Chess Board and Piece History Memory */
		SetChessBoardAndMoveHistoryByPieceType (piece.GetPieceType(), 
							targetColor);
	}


	/* Now update the Player's piece with the latest position */
	tmpPlayer = GetPlayerFromColor (color);
	if (tmpPlayer == NULL) {
		return INVALID_PLAYER_ERROR;
	}

	/* Get Piece Object from the pieceType */
	Piece &piece = tmpPlayer->GetPieceObjectFromPieceType(pieceType);

	/* Reset the earlier position of the piece */
	SetChessBoardPosition(piece.GetPosition(), FIRST_INVALID_PIECE);	

	/* Update the Piece, with the latest position */
	piece.SetPosition (pos);

	/* Store the Latest Positions on the Chess board and 
	   on the piece Move History. */
	SetChessBoardAndMoveHistoryByPieceType (pieceType, color);

	/* Change Turn */
	SetNextTurn(color == White ? Black : White);

	/* Set Current Move number */
	currentMove = GetCurrentMove();
	SetCurrentMove (++currentMove);

	/*Store Move History. */
	moveHistory.push_back(pieceBoard);	
	//UpdateMoveToHistory ()

	return SUCCESS;

}


int ChessGame::RestoreToMove(int move) 
{
	Color color;
	Player	*tmpPlayer = NULL;
	
	if ((move > GetCurrentMove()) || (move < 0)) {
		return INVALID_MOVE_ERROR;
	}

	PieceBoard &pieceState = moveHistory.at(move);

	memset (chess_board, 0, sizeof(chess_board));

	for (int type = 1; type <= NUM_PIECES * 2; type++) {
		/* Get color of the Piece */
		color = GetPieceColorFromPieceType(type);
		/* Object of the player associated */
		tmpPlayer = GetPlayerFromColor(color);
		/* Piece */
		Piece piece = tmpPlayer->GetPieceObjectFromPieceType((PieceType)type);
		/* Position of the piece on that move */
		Position pos = pieceState.at(type - 1).GetPosition();
		/* Set to the Chess Board and Piece */
		piece.SetPosition(pos);
		SetChessBoardPosition(piece.GetPosition(), (PieceType)type);
	}
	
	/* Erase the other elements in history */
	moveHistory.erase(moveHistory.begin() + move + 1, moveHistory.end());

	currMove = move;
	
	return SUCCESS;

} 

