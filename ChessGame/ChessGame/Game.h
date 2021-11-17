#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Board.h"

#include "WhitePawn.h"
#include "BlackPawn.h"
#include "WhiteRook.h"
#include "BlackRook.h"
#include "BlackKnight.h"
#include "WhiteKnight.h"
#include "WhiteBishop.h"
#include "BlackBishop.h"
#include "WhiteQueen.h"
#include "BlackQueen.h"
#include "WhiteKing.h"
#include "BlackKing.h"


class Game
{
public:

	/// Konstructor and destructor:
	Game();
	~Game();


	//Public Functions:

	//Update game logic
	void updateGameLogic();

	//After updating the logic, we need to Clear the window, draw, if someting is necessary, and then display it!
	void render();

	//Check if the window is still open or not!
	const bool running() const;




private:

	// Variables:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	double deltaTime;
	int type;



	//Legacy members:

	//----FIGURES:

	//ChessBoard:
	Board gameBoard;

	//--------WHITES:

	//WhitePawns:
	WhitePawn whitePawns;
	
	//WhiteRooks:
	WhiteRook whiteRooks;

	//WhiteKnights:
	WhiteKnight whiteKnights;

	//WhiteBishops
	WhiteBishop whiteBishops;

	//WhiteQueen
	WhiteQueen whiteQueen;

	//WhiteKing:
	WhiteKing whiteKing;

	//---------BLACKS:

	//BlackPawns:
	BlackPawn blackPawns;

	//BlackRooks:
	BlackRook blackRooks;

	//BlackKnights:
	BlackKnight blackKnights;

	//BlackBishops:
	BlackBishop blackBishops;

	//BlackQueen:
	BlackQueen blackQueen;

	//BlackKing:
	BlackKing blackKing;

//----------------------------------------------------------------Functions for figures wheter if they want to move and/or so they did, or not -----------------------------------------------------
 
	//Altalanos fuggvenyek:
	void drawPossibleWays(Board& board, int type, int boardPositionX, int boardPositionY);

	void moveFigure(Board& board, double deltaTime, int currentPosY, int currentPosX, int willingPosY, int willingPosX);

	//-----

	//Feher Gyalog:
	void drawWhitePawnWays(Board& board, int boardPositionX, int boardPositionY);

	//FeherBastya:
	void drawWhiteRookWays(Board& board, int boardPositionX, int boardPositionY);

	//feher Lo:
	void drawWhiteKnightWays(Board& board, int boardPositionX, int boardPositionY);

	//feher Futo:
	void drawWhiteBishopWays(Board& board, int boardPositionX, int boardPositionY);

	//Feher Kiralyno:
	void drawWhiteQueenWays(Board& board, int boardPositionX, int boardPositionY);

	//Feher Kiraly:
	void drawWhiteKingWays(Board& board, int boardPositionX, int boardPositionY);

	//Fekete Gyalog:
	void drawBlackPawnWays(Board& board, int boardPositionX, int boardPositionY);

	//Fekete Bastya:
	void drawBlackRookWays(Board& board, int boardPositionX, int boardPositionY);

	//Fekete Lo:
	void drawBlackKnightWays(Board& board, int boardPositionX, int boardPositionY);

	//Fekete Futo:
	void drawBlackBishopWays(Board& board, int boardPositionX, int boardPositionY);

	//Fekete Kiralyno:
	void drawBlackQueenWays(Board& board, int boardPositionX, int boardPositionY);

	//Fekete Kiraly:
	void drawBlackKingWays(Board& board, int boardPositionX, int boardPositionY);



//----------------------------------------------------------------------------- End of functions ---------------------------------------------------------------------------------------------------

	
	//Az elozo megnyomott figura elmeleti tombben levo helye: ---> atszinezzuk a kockajat, 
	//majd ha egy masikra ranyomunk, akkor az elozo visszaszinezodik feherre, vagy feketere
	int startX;
	int startY;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	bool isMouseHeld;
	bool lookedForSquareIsFound;


	// Private functions:

	void initVariables();
	void initWindow();
	//Reset clock:
	double resetClockAndDeltaTime();
	//Update veents:
	void pollEvents();
	//Setter functions:
	void updateMousePosition();
	void isFigurePressed(Board& colourableSquare); //Checks if we clicked on a figure or not
	//Clear
	void Clear();
	//Draw()
	void Draw();
	//Display()
	void Display();
	

	
};

