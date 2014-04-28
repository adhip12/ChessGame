#include <iostream>

using namespace std;

namespace {
	static const int num_pieces = 16;	
	static const int position = 2;
	static const int chess_board[8][8];
}

typedef enum Colors_t {
	White = 0,
	Black
}Color;

typedef enum ChessPieceNames{
	PAWN_1 = 0,
	ROOK_1,
	BISHOP_1,
	KNIGHT_1,
	KING_1,
	QUEEN_1,
	KNIGHT_2,
	BISHOP_2,
	ROOK_2
}Names;

//Class to maintain the position on the Chess Board.
Class Position {
private:
	int x;
	int y;
public:
	int GetX() const { return x; }
	int GetY() const { return y; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
};

// Class defintion for a give piece.
class Piece {
private :
	PieceType pieceType;
	Position pos;
public :
	//Constructor
	Piece(PieceType type, Position &pos);

	PieceType getPieceType () const { return pieceType; }
	void setPieceType (PieceType type) { this->pieceType = type; }

	// void initPiece(int, Poistion &);

	Position getPosition() const { return pos; }
	void setPosition (Position pos) { this->pos = pos; }
};

// A Player is defined by the color of the pieces as well as the 16 pieces assigned.
class Player {
private:
	Color color;
	Pieces	*piece[16];
public:
	//Constructor
	Player(Color);	

	
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

