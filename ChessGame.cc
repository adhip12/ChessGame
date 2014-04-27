#include "ChessState.hh"

Piece:: Piece ()
{
	pos.x = -1;
	pos.y = -1;
	int piece_num = -1;
}

Piece :: void initPieces (int num, Position &pos)
{
	piece_num = num;
	this->pos.SetX(pos.x);
	this->pos.SetY(pos.y);
}

Players:: Players(int type)
{
	Position pos;
	this.type = type;	
	for (int num = 0; i < NUM_PIECES; num++) {
		pos = getPosition (i, type);
		pieces[i].initPieces (num, Position(pos.i, pos.j));			
	}
}

ChessGame::ChessGame()
{
	head = NULL;
	tail = NULL;
	currMove = 0;	
	
	// Initialize the Chess board, and mark the initial positions as filled 
	for (int row = 0, row1 = 6;row <= 1, row1 <= 7;row++, row1++) {
		for (int col = 0; col < 7; col ++) {
			chess_board[col][row] = TAKEN; 
			chess_board[col][row1] = TAKEN; 
		}
	}
}


Players:: int MovePiece (int piece, Position &pos)
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
	 





}
