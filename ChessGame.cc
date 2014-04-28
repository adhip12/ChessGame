#include "ChessState.hh"

Position::Position(const int row, const int col) : x(row), y(col) {}

Piece:: Piece (const PieceType type, const Position &posn) : pieceType(type), pos(posn) {}

Position::Position() : x(-1), y(-1) {}

Piece::Piece()
{
	setPieceType(INVALID_PIECE_TYPE);
	setPosition(Position(-1, -1));

}

void Piece :: initPiece (const PieceType type, Position &pos)
{
	setPieceType (type);	
	setPosition (pos);
	//piece_num = num;
	//this->pos.SetX(pos.x);
	//this->pos.SetY(pos.y);
}

Player:: Player(Color color)
{
	setColor(color);	

	for (int type = 0; type < NUM_PIECES; type++) {
		Position pos = GetInitialPositionOfPiece ((PieceType)type, color);
		piece[type].initPiece((PieceType)type, pos);
		//newPiece.initPiece (num, Position(pos.i, pos.j));			
		//piece[num] = *newPiece;
	}
}

ChessGame::ChessGame() : head (0), tail(0), currMove(0) 
{
	int x = 0, y = 0; 
	player1 = new Player (White);
	player2 = new Player (Black);
	Color color = White;
	// Initialize the Chess board, and mark the initial positions with the Piece info.
	memset (chess_board, 0, sizeof(chess_board[0][0]) * 8 * 8);

	for (int type = 0; type < NUM_PIECES; type++) {
		color = White;
		Position pos = GetInitialPositionOfPiece ((PieceType)type, color);
		x = pos.GetX();	
		y = pos.GetY();	
		chess_board[x][y] = type;
		color = Black;
		pos = GetInitialPositionOfPiece ((PieceType)type, color);
		x = pos.GetX();	
		y = pos.GetY();	
		chess_board[x][y] = 2 * type;
	}		
}

ChessGame::~ChessGame ()
{
	delete player1;
	delete player2;
}

Position GetInitialPositionOfPiece (PieceType type, Color color)
{
	int position;

	if (color == White) {
		if (type < PAWN8) {
			return (Position(1, type - 1));
		} else {
			return (Position(0, type - PAWN_8 - 1));
		}
	} else {
		if (type < PAWN8) {
			return (Position (6, type - 1));		
		} else {
			return (Position (7, type - PAWN_8 - 1));
		}		
	}
}

#if 0
ChessGame::int RestoreToMove(int move) 
{
	int count = move;
	// Go back to initial positions.
	ChessGame();

	if ((move > currMove) || (move < 0)) {
		return NO_SUCH_MOVE_ERROR;
	}

	// Traverse the list, until we reach the move number
	while (count != 0) {
		Node *node = head;
		RestorePiece(node->type, )

	}



}
	 



int Piece::MovePiece (PieceType piece, Position &pos)
{
	//Check Position, if its already taken.
	if (chess_board[pos->i, pos->j] == TAKEN) {
		return SLOT_TAKEN_ERROR;
	}
	/*Use either the vector of vector method or the linked list node method
	  to keep track of the move */

	//Also have to keep track of the current position of the piece.
	//Not ading code for the above right now. Only checking the code to add moves, irrespective of it being an invalid move.

	Node *move = new Node();	
	Piece *piece = this->piece[piece_num];
	move->pieceInfo = piece->setPieceInfo (piece_num, pos);
	move->playerType = player->type;

	if (head == NULL) {
		head = move;
		move->next = NULL;
		move->prev = NULL;
		tail = move;
	} else {
		tail->next = move;
		move->prev = tail;
		tail = move;
	}

	currMove ++;
	
}

#endif



