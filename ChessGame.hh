#ifndef ChessGame_hh
#define ChessGame_hh

#include "Player.hh"
using namespace std;


class ChessGame {
private:

	int 	chess_board[8][8];
	int 	currMove;
	Color	nextTurn;

	/* 2 players of the Chess Game */
	Player *player1;
	Player *player2;

	/* Copy Constructor */
	ChessGame (const ChessGame &);
	/* Assignement Operator */
	ChessGame operator=(const ChessGame &);

	/* Array of Piece */
	typedef array<class Piece, 32> PieceBoard;
	PieceBoard pieceBoard;

	typedef vector<PieceBoard> ChessMoveHistory;
	ChessMoveHistory moveHistory;
 
	int 	GetCurrentMove() { return currMove; }
	int 	GetNextTurn() const { return nextTurn; }
	int 	GetChessBoardValues (int x, int y);
	int 	GetChessBoardValuesIfTaken (int x, int y);
	Color	GetPieceColorFromPieceType (int value);
	Player  *GetPlayerFromColor(Color color);

	void 	SetCurrentMove (int move) { this->currMove = move; }
	void 	SetNextTurn(Color color) { this->nextTurn = color; } 
	int 	SetChessBoardAndMoveHistoryByPieceType (const PieceType type, const Color color);
	void SetChessBoardPosition (Position pos, PieceType value);

public:
	//Constructor 
	ChessGame ();

	//Destructor
	~ChessGame();

	/* API's available to the user */
	/* Moving a Piece */
	int PlayerMovePiece (const Color color, const PieceType type, const Position pos);
	int RestoreToMove (int move);

	//Debugging
	void PrintBoardValues();
};

#endif
