#include <iostream>

using namespace std;

namespace {
	static const int NUM_PIECES = 16;	
	static const int position = 2;
	static const int chess_board[8][8];
}

typedef enum Colors_t {
	White = 0,
	Black
}Color;

typedef enum ChessPieceTypes{
	PAWN_1 = 0,
	ROOK_1,
	BISHOP_1,
	KNIGHT_1,
	KING_1,
	QUEEN_1,
	KNIGHT_2,
	BISHOP_2,
	ROOK_2
}PieceTypes;

//Class to maintain the position on the Chess Board.
Class Position {
private:
	int x;
	int y;
public:
	Poistion(const int x, const int y);
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
	Piece(const PieceType type, const Position &pos);

	PieceType getPieceType () const { return pieceType; }
	Position getPosition() const { return pos; }
	void setPieceType (const PieceType type) { this->pieceType = type; }
	void setPosition (const Position pos) { this->pos = pos; }
};

// A Player is defined by the color of the pieces as well as the 16 pieces assigned.
class Player {
private:
	Color color;
	Pieces	*piece[NUM_PIECES];
public:
	//Constructor
	Player(Color color);	
	
	void setColor(Color color)
	{
		this->color = color;
	};

	Color getColor() const
	{
		return color;
	};

	int MovePiece (int piece, Position &pos); 
};


// Chess Game includes a chess board and 2 players. 
class ChessGame() {
private:
	// 2 players of the Chess Game;
	Players	player1;
	Players player2;

	int chess_board[8][8];
	int currMove;
	MoveHistoryNode *head;
	MoveHistoryNode *tail;

public:
	//Constructor 
	ChessGame ();
	void RestoreMove (int move);
};


typedef struct Move_History_Node_t {
	int type;
	Piece *pieceInfo;
	Node_t *next;
	Node_t *prev;
	
}MoveHistoryNode;

