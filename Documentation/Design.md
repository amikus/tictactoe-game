# Tic Tac Toe

## Goal:
To create a Tic Tac Toe game that plays a human against the computer.

### Features to include:
* Drag-and-drop game pieces
* Simple AI for making decisions about which moves to make in response to player moves
* Reset button for clearing the board
* Visible change to signal win (by drawing a line through pieces or by changing color of pieces)
* Name will be displayed somewhere in window

### Objects:
* GameBoard - Traditional tic tac toe board in octothorp shape
* GamePiece - Parent class for X and O pieces
    * draggable - Binary flag to determine whether this piece is currently able to be moved.
    * drawGamePiece() - Draw game piece
* XPiece - Human player piece, inherits from GamePiece
	* xShape - Array of values representing X-shaped piece
* OPiece - Computer opponent piece, inherits from GamePiece
    * xShape - Array of values representing O-shaped piece
* Text
    * drawWord() - Draw the word

