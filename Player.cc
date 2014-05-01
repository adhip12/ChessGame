#include "Player.hh"

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


