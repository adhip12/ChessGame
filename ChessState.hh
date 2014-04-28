#include <iostream>

using namespace std;

namespace {
	static const int NUM_PIECES = 16;	
}

typedef enum Colors_t {
	White = 0,
	Black
}Color;

typedef enum Error_t {
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
	INVALID_PIECE_TYPE
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
};

// Class defintion for a give piece.
class Piece {
private :
	PieceType pieceType;
	Position pos;
public :
	//Constructor
	Piece();
	Piece(const PieceType type, const Position &pos);

	PieceType getPieceType () const { return pieceType; }
	Position getPosition() const { return pos; }
	void setPieceType (const PieceType type) { this->pieceType = type; }
	void setPosition (const Position &pos) { this->pos = pos; }

	//Move Piece
	void initPiece (const PieceType type, Position &pos);
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
};


// Chess Game includes a chess board and 2 players. 
//Compiler by default generates a copy constructror, if I havent defined one.
class ChessGame {
private:

	int chess_board[8][8];
	struct Move_History_Node_t *head;
	struct Move_History_Node_t *tail;
	int currMove;

	// 2 players of the Chess Game;
	Player *player1;
	Player *player2;

	//Copy Constructor
	ChessGame (const ChessGame &);
	// Assignement Operator
	ChessGame operator=(const ChessGame &);

public:
	//Constructor 
	ChessGame ();

	//Destructor
	~ChessGame();

	void RestoreMove (int move);
};


typedef struct Move_History_Node_t {
	PieceType type;
	Piece *pieceInfo;
	struct Move_History_Node_t *next;
	struct Move_History_Node_t *prev;
	
}MoveHistoryNode;

Position GetInitialPositionOfPiece (PieceType type, Color color);
