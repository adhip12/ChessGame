#include "ChessState.hh"

Piece:: Piece ()
{
	pos.i = -1;
	pos.j = -1;
	int piece_num = -1;
}

Piece :: void initPieces (int num, Position &pos)
{
	piece_num = num;
	this->pos.i = pos->i;
	this->pos.j = pos->j;
}

Players:: Players(int type)
{
	Position pos;
	
	for (int num = 0; i < NUM_PIECES; num++) {
		pos = getPosition (i, type);
		pieces[i].initPieces (num, Position(pos.i, pos.j));			
	}
}

ChessGame::ChessGame()
{
	head = NULL;
	for (int row = 0;row <= 1;row++) {
		for (int col = 0; col < 7; col ++) {
			chess_board[col][row] = 1; 
		}
	}		
}

ChessGame:: void MovePiece (int player, int piece, Position &pos)
{
	//Check Position, if its already taken.

	/*Use either the vector of vector method or the linked list node method
	  to keep track of the move */

	 



}
