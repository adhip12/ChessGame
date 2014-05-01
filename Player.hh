#ifndef Player_hh
#define Player_hh

//#include "ChessState.hh"
//#include "Position.hh"
#include "Piece.hh"
/* A Player is defined by the color of the pieces as well as the 16 pieces assigned
   to it
 */
class Player {
private:
	Color   color;
	Piece	piece[NUM_PIECES];
	void setColor(Color color) { this->color = color; }
public:
	//Constructor
	Player(const Color color);	

	Color getColor() const { return color; }
	Piece& GetPieceObjectFromPieceType (PieceType type);
	Position GetInitialPositionOfPiece (PieceType type, Color color);
};
#endif


