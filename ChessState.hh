#include <iostream>

using namespace std;

namespace {
	static const int num_pieces = 16;	
	static const int position = 2;
	static const int chess_board[8][8];
}

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
	int GetX();
	int GetY();
	void SetX(int );
	void SetY(int );
};

// Class defintion for a give piece.
class Pieces {
private :
	int piece_num;
	Position pos;
public :
	Piece();
	void initPiece(int, Poistion &);
	Pieces getPieceInfo();
	Pieces setPieceInfo(int piece_num, Position pos);
};

// A Player is defined by the color of the pieces as well as the 16 pieces assigned.
class Players {
private:
	int type;
	Pieces	*piece[16];
public:
	Players(int type);	
	int MovePiece (int piece, Position &pos); 
};

// Chess Game includes a chess board and 2 players. 
class ChessGame() {
private:
	// 2 players of the Chess Game;
	Players	WhitePl;
	Players BlackPl;
	// Data Structure to store State of the game
//	vector<vector><Position> moveState;
	int chess_board[8][8];
	int currMove;
	Node *head;
	Node *tail;

public:
	ChessGame ();
	void RestoreMove (int move);
};


typedef struct Node_t {
	int type;
	Piece *pieceInfo;
	Node_t *next;
	Node_t *prev;
	
}Node;

