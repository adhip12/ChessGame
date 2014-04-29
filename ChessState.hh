#include <iostream>

using namespace std;

#define INV_POS		-1

namespace {
	static const int NUM_PIECES = 16;	
}

typedef enum Colors_t {
	White = 0,
	Black
}Color;

typedef enum Error_t {
	SUCCESS = 0,
	POSITION_ERROR = 1,
	PLAYER_ERROR,
	INVALID_MOVE_ERROR,
	NOT_CORRECT_PLAYER_ERROR
}Errors;

typedef enum ChessPieceTypes{
	PAWN1 = 1,
	PAWN2,
	PAWN3,
	PAWN4,
	PAWN5,
	PAWN6,
	PAWN7,
	PAWN8,
	ROOK1,
	BISHOP1,
	KNIGHT1,
	KING1,
	QUEEN1,
	KNIGHT2,
	BISHOP2,
	ROOK2,
	INVALID_PIECE_TYPE = 33
}PieceType;

//Class to maintain the position on the Chess Board.
class Position {
private:
	int x;
	int y;
public:
	Position();
	Position(const int x, const int y);
	int GetX() const { return x; }
	int GetY() const { return y; }
	void SetX(const int x) { this->x = x; }
	void SetY(const int y) { this->y = y; }
	bool  InvalidPositionForPieceType();
};

// Class defintion for a give piece.
class Piece {
private :
	PieceType pieceType;
	Position pos;
	bool	killed;
public :
	//Constructor
	Piece();
	Piece(const PieceType type, const Position &pos, const bool killStatus);

	PieceType GetPieceType () const { return pieceType; }
	Position GetPosition() const { return pos; }
	bool GetKilledStatus() const { return killed; }
	void SetKilledStatus(const bool killed) { this->killed = killed; }
	void SetPieceType (const PieceType type) { this->pieceType = type; }
	void SetPosition (const Position &pos) { this->pos = pos; }

	//Move Piece
	void initPiece (const PieceType type, const Position &pos);
	int MovePiece (const PieceType piece, Position &pos); 
};

// A Player is defined by the color of the pieces as well as the 16 pieces assigned.
class Player {
private:
	Color   color;
	Piece	piece[NUM_PIECES];
	void setColor(Color color) { this->color = color; }
public:
	//Constructor
	Player(const Color color);	

	Color getColor() const { return color; }
	Piece& GetPieceObjectFromPieceType (PieceType type);
	Position GetInitialPositionOfPiece (PieceType type, Color color);
};


// Chess Game includes a chess board and 2 players. 
//Compiler by default generates a copy constructror, if I havent defined one.
class ChessGame {
private:

	int 	chess_board[8][8];
	struct 	Move_History_Node_t *head;
	struct 	Move_History_Node_t *tail;
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
	typedef vector<Piece> ChessBoard;

	/* Array of Chessboard for each move */
	typedef vector<ChessBoard> ChessGameMoves;

public:
	//Constructor 
	ChessGame ();

	//Destructor
	~ChessGame();


	int GetCurrentMove() { return currMove; }
	int GetNextTurn() const { return nextTurn; }
	int GetChessBoardValues (int x, int y);

	void SetCurrentMove (int move) { this->currMove = move; }
	void SetNextTurn(Color color) { this->nextTurn = color; } 
	int SetChessBoardByPieceType (const PieceType type, const Color color);

	Color	GetColorFromTypeNumber (int value);

	//Moving a Piece	
	int PlayerMovePiece (const Color color, const PieceType type, const Position pos);
	
	void RestoreMove (int move);

	//Debugging
	void PrintBoardValues();
};


typedef struct Move_History_Node_t {
	PieceType type;
	Piece *pieceInfo;
	struct Move_History_Node_t *next;
	struct Move_History_Node_t *prev;
	
}MoveHistoryNode;

