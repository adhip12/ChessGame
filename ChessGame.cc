#include "ChessState.hh"

Piece:: Piece (PieceType type, int x, int y)
{
	
	//initPiece (pieceType, pos);
	pos.setX(x); = -1;
	pos.y = -1;
	int piece_num = -1;
}

Piece :: void initPiece (int num, Position &pos)
{
	piece_num = num;
	this->pos.SetX(pos.x);
	this->pos.SetY(pos.y);
}

Players:: Players(Color color)
{
	Position pos;
	setColor(color);	

	for (int type = 0; type < NUM_PIECES; type++) {
		pos = getPosition (num, color);
		Piece *newPiece = new Piece (type, new Position (pos.x, pos.y);
		//newPiece.initPiece (num, Position(pos.i, pos.j));			
		piece[num] = *newPiece;
	}
}

ChessGame::ChessGame()
{
	head = NULL;
	tail = NULL;
	currMove = 0;	

	player1 = new Player (White);
	player2 = new Player (Black);

	// Initialize the Chess board, and mark the initial positions with the Piece info.
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
