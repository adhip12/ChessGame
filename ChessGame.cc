#include "ChessState.hh"

Position::Position(const int row, const int col) : x(row), y(col) {}

bool Position::InvalidPositionForPieceType() 
{
	int x = GetX();	
	int y = GetY();

	if (((x < 0) || (y < 0)) || (x > 7) || (y > 7)) {
		return true;
	} else {
		return false;
	}
	
}	

Piece:: Piece (const PieceType type, const Position &posn, const bool killStatus) : pieceType(type), pos(posn), killed(killStatus) {}

Position::Position() : x(INV_POS), y(INV_POS) {}

Piece::Piece(): pieceType(INVALID_PIECE_TYPE), pos(INV_POS, INV_POS), killed(false)
{
//	setPieceType(INVALID_PIECE_TYPE);
//	setPosition(Position(-1, -1));

}

void Piece :: initPiece (const PieceType type, const Position &pos)
{
	SetPieceType (type);
	SetPosition (pos);
	//piece_num = num;
	//this->pos.SetX(pos.x);
	//this->pos.SetY(pos.y);
}

Player:: Player(Color pieceColor): color(pieceColor)
{
	for (int type = 1; type <= NUM_PIECES; type++) {
		Position pos = GetInitialPositionOfPiece ((PieceType)type, color);
		piece[type - 1].initPiece((PieceType)type, pos);
		//newPiece.initPiece (num, Position(pos.i, pos.j));			
		//piece[num] = *newPiece;
	}
}

Position Player::GetInitialPositionOfPiece (PieceType type, Color color)
{
	int position;

	if (color == White) {
		if (type <= PAWN8) {
			return (Position(1, type - 1));
		} else {
			return (Position(0, type - PAWN8 - 1));
		}
	} else if (color == Black) {
		if (type <= PAWN8) {
			return (Position (6, type - 1));		
		} else {
			return (Position (7, type - PAWN8 - 1));
		}		
	} else {
		return Position(INV_POS, INV_POS);
	}
}

Piece& Player::GetPieceObjectFromPieceType(PieceType type)
{
	return (this->piece[(int)type - 1]);
}


ChessGame::ChessGame() : head (0), tail(0), currMove(0), nextTurn (White) 
{
	player1 = new Player (White);
	player2 = new Player (Black);

	// Initialize the Chess board, and mark the initial positions with the Piece info.
	memset (chess_board, 0, sizeof(chess_board));

	for (int type = 1; type <= NUM_PIECES; type++) {
		SetChessBoardByPieceType ((PieceType)type, White); 
		SetChessBoardByPieceType ((PieceType)type, Black); 
	}
}

ChessGame::~ChessGame ()
{
	delete player1;
	delete player2;
}

int ChessGame::SetChessBoardByPieceType (const PieceType type, const Color color)
{
	int x = 0, y = 0; 
	Position pos;
	if (color == White) {
		const Piece &piece = player1->GetPieceObjectFromPieceType(type);
		pos = piece.GetPosition();
	} else if (color == Black) {
		const Piece &piece = player2->GetPieceObjectFromPieceType(type);
		pos = piece.GetPosition();
	}

	if (pos.InvalidPositionForPieceType()) {
		return POSITION_ERROR;
	}

	x = pos.GetX();	
	y = pos.GetY();	

	if (color == White) {
		chess_board[x][y] = type;
	} else if (color == Black) {
		chess_board[x][y] = type + 16;
	}
	return SUCCESS;

}

int ChessGame::GetChessBoardValues (int x, int y)
{
	return chess_board[x][y];

}

void ChessGame::PrintBoardValues() 
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout <<" "<<GetChessBoardValues(i,j);
		}
		cout <<endl<<"------------------------"<<endl;
	}
}

Color ChessGame::GetColorFromTypeNumber(int value)
{
	if (value > 16) {
		return Black;
	} else {
		return White;
	}
}

int ChessGame::PlayerMovePiece (const Color color, const PieceType type, const Position pos)
{
	// If the Position is taken by another piece.
	int value = 0;
	if (GetNextTurn() != color) {
		return NOT_CORRECT_PLAYER_ERROR;
	}
	if ((value = GetChessBoardValues(pos.GetX(), pos.GetY())) != 0) {	
		/* If the color of the piece at pos is the same as the one making 
		   the move, then the move is Invalid 
		 */
		if (GetColorFromTypeNumber(value) == color) {
			return INVALID_MOVE_ERROR;
		} else {
		 //Kill the Piece of the opposite player
			if (value > 16) {
			  // Killing a Black Piece.
			   Piece &piece = player2->GetPieceObjectFromPieceType((PieceType) 									(value % 16));
			   piece.SetPosition(Position(INV_POS, INV_POS));
			   piece.SetKilledStatus (true);
			} else {
			  //Killing a White Piece.
			   Piece &piece = player1->GetPieceObjectFromPieceType((PieceType) 										 value);
			   piece.SetPosition(Position(INV_POS, INV_POS));
			   piece.SetKilledStatus (true);

			}
		}
	}

	if (color == White) {
		Piece &piece = player1->GetPieceObjectFromPieceType(type);
		piece.SetPosition (pos);
	} else if (color == Black) {
		Piece &piece = player2->GetPieceObjectFromPieceType(type);
		piece.SetPosition (pos);
	} else {
		return PLAYER_ERROR;
	}
	// Store the Latest Positions on the Chess board.
	SetChessBoardByPieceType (type, color);
	// Change Turn
	SetNextTurn(color == White ? Black : White);
	/* Set Current Move number */
	SetCurrentMove (GetCurrentMove() ++);

	//Store Move History.
	AddMoveToHistory ()

	return SUCCESS;

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




