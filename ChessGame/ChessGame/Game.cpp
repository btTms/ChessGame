#include "Game.h"

//Kosntuctor:
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

//Destructor:
Game::~Game()
{
	delete this->window;
}

//Init variables that soon will be added to the code:
void Game::initVariables()
{
	this->window = nullptr;
	this->isMouseHeld = false;
	this->lookedForSquareIsFound = false;
	this->startX = -1;
	this->startY = -1;
}

//Initialize window
void Game::initWindow()
{
	this->videoMode.height = 1008;
	this->videoMode.width = 1008;
	this->window = new sf::RenderWindow(this->videoMode, "Chess!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	this->window->setFramerateLimit(60);
}


const bool Game::running() const
{
	return this->window->isOpen();
}

double Game::resetClockAndDeltaTime()
{
	return this->clock.restart().asSeconds();
}

//Update the events:
void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;

			case sf::Event::KeyPressed:
				if (this->event.key.code == sf::Keyboard::Escape)
					this->window->close();
						break;
		}
	}
}

//Clear
void Game::Clear()
{
	this->window->clear(sf::Color(78, 78, 78, 255));
}

//Draw
void Game::Draw()
{
	//Draw ChessBoard:
	this->gameBoard.DrawBorder(this->window);

	this->gameBoard.DrawChessBoard(this->window);
	this->gameBoard.RenderGui(this->window);


	//------DRAW FIGURES:

	//--------WHITES:
	// 
	//Draw WhitePawns:
	this->whitePawns.DrawWhitePawns(this->window);
	this->whiteRooks.DrawWhiteRooks(this->window);
	this->whiteKnights.DrawWhiteKnights(this->window);
	this->whiteBishops.DrawWhiteBishops(this->window);
	this->whiteQueen.DrawWhiteQueen(this->window);
	this->whiteKing.DrawWhiteKing(this->window);



	//-------BLACKS:
	// 
	//Draw BlackPawns
	this->blackPawns.DrawBlackPawns(this->window);
	this->blackRooks.DrawBlackRooks(this->window);
	this->blackKnights.DrawBlackKnights(this->window);
	this->blackBishops.DrawBlackBishops(this->window);
	this->blackQueen.DrawBlackQueen(this->window);
	this->blackKing.DrawBlackKing(this->window);
	
}


//----------------------------------------------------------------Functions for figures wheter if they want to move and/or so they did, or not -----------------------------------------------------


void Game::drawPossibleWays(Board& board, int type, int boardPositionX, int boardPositionY)
{
	switch (type)
	{
		case -1:
			drawWhitePawnWays(board, boardPositionX, boardPositionY);
				break;
			//kirajzoltatjuk a feher gyalog lehetseges utjait es frissitjuk a logikai tablat
		case -2:
			drawWhiteRookWays(board, boardPositionX, boardPositionY);
				break;
			//kirajzoltatjuk a feher bastya lehetseges utjait es frissitjuk a logikai tablat
		case -3:
			drawWhiteKnightWays(board, boardPositionX, boardPositionY);
				break;	
			//kirajzoltatjuk a feher lovag lehetseges utjait es frissitjuk a logikai tablat
		case -4:
			drawWhiteBishopWays(board, boardPositionX, boardPositionY);
				break;
			//kirajzoltatjuk a feher futo lehetseges utjait es frissitjuk a logikai tablat
		case -5:
			drawWhiteQueenWays(board, boardPositionX, boardPositionY);
				break;

			//kirajzoltatjuk a feher kiralyno lehetseges utjait es frissitjuk a logikai tablat
		case -6:
			drawWhiteKingWays(board, boardPositionX, boardPositionY);
				break;
			//kirajzoltatjuk a feher kiraly lehetseges utjait es frissitjuk a logikai tablat
		case 1:
			drawBlackPawnWays(board, boardPositionX, boardPositionY);
				break;

			//kirajzoltatjuk a fekete gyalog lehetseges utjait es frissitjuk a logikai tablat
		case 2:
			drawBlackRookWays(board, boardPositionX, boardPositionY);
				break;

			//kirajzoltatjuk a fekete bastya lehetseges utjait es frissitjuk a logikai tablat
		case 3:
			drawBlackKnightWays(board, boardPositionX, boardPositionY);
				break;

			//kirajzoltatjuk a fekete lovag lehetseges utjait es frissitjuk a logikai tablat
		case 4:
			drawBlackBishopWays(board, boardPositionX, boardPositionY);
				break;

			//kirajzoltatjuk a fekete futo lehetseges utjait es frissitjuk a logikai tablat
		case 5:
			drawBlackQueenWays(board, boardPositionX, boardPositionY);
				break;

			//kirajzoltatjuk a fekete kiralyno lehetseges utjait es frissitjuk a logikai tablat
		case 6:
			drawBlackKingWays(board, boardPositionX, boardPositionY);
				break;

			//kirajzoltatjuk a fekete kiralyno lehetseges utjait es frissitjuk a logikai tablat
	}
}

void Game::moveFigure(Board& board, double deltaTime, int currentPosY, int currentPosX, int willingPosY, int willingPosX)
{
	deltaTime = resetClockAndDeltaTime();
	double vx = ((currentPosX - willingPosX) * 118 - 41) / deltaTime;
	double vy = ((currentPosY - willingPosY) * 118 - 41) / deltaTime;

	while (!board.ChessBoard[willingPosY][willingPosX].getGlobalBounds().intersects(board.ChessBoard[currentPosY][currentPosX].getGlobalBounds()))
	{
		board.ChessBoard[currentPosY][currentPosX].move(vx, vy);
	}

	board.ChessBoard[currentPosY][currentPosX].setPosition(willingPosX * 118 + 41, willingPosY * 118 + 41);

}



//Feher Gyalog:

void Game::drawWhitePawnWays(Board& board, int boardPositionX, int boardPositionY)
{
		if (boardPositionY - 1 >= 0)
		{
			if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 1] > 0 && boardPositionX - 1 >= 0)
			{
				board.ChessBoard[boardPositionY - 1][boardPositionX - 1].setFillColor(sf::Color(215, 49, 49, 200));

				board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 1] *=  10; // ez jelzi az elmeleti tombnek, ha ilyen jelzesu helyre lepunk, akkor tudjunk lepni csak
			}


			if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 1] > 0 && boardPositionX + 1 <= 7)
			{
				board.ChessBoard[boardPositionY - 1][boardPositionX + 1].setFillColor(sf::Color(215, 49, 49, 200));

				board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 1] *=  10;
				}

			if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX] == 0)
			{
				
				if ((boardPositionX + boardPositionY - 1 ) % 2 == 0)
					board.ChessBoard[boardPositionY - 1][boardPositionX].setFillColor(sf::Color(197, 207, 145, 255));
				else
					board.ChessBoard[boardPositionY - 1][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 1][boardPositionX] = 10;
			} //Game.cpp-ben fbefejezni
		}

}

void Game::drawWhiteRookWays(Board& board, int boardPositionX, int boardPositionY)
{
	// Y tengelyen valo lehetseges utak
	short int seged = boardPositionY - 1;


	while (board.PrincipledChessBoard[seged][boardPositionX] == 0 && seged >= 0)
	{
		if ((boardPositionX + seged) % 2 == 0)
			board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(197, 207, 145, 255));
		else
			board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));

		board.PrincipledChessBoard[seged][boardPositionX] = 10;

		seged--;
	}

	if (seged >= 0)
	{

		if (board.PrincipledChessBoard[seged][boardPositionX] > 0)
		{
			board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[seged][boardPositionX] *= 10;
		}
	}


	seged = boardPositionY + 1;

	while (board.PrincipledChessBoard[seged][boardPositionX] == 0 && seged <= 7)
	{

		if ((boardPositionX + seged) % 2 == 0)
			board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(197, 207, 145, 255));
		else
			board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));

		board.PrincipledChessBoard[seged][boardPositionX] = 10;

		seged++;
	}

	if (seged <= 7)
	{
		if (board.PrincipledChessBoard[seged][boardPositionX] > 0)
		{
			board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[seged][boardPositionX] *= 10;
		}
	}

	seged = boardPositionX + 1;

	while (board.PrincipledChessBoard[boardPositionY][seged] == 0 && seged <= 7)
	{

		if ((boardPositionY + seged) % 2 == 0)
			board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(197, 207, 145, 255));
		else
			board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(163, 179, 84, 255));

		board.PrincipledChessBoard[boardPositionY][seged] = 10;

		seged++;
	}

	if (seged <= 7)
	{
		if (board.PrincipledChessBoard[boardPositionY][seged] > 0)
		{
			board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY][seged] *= 10;
		}
	}

	seged = boardPositionX - 1;

	while (board.PrincipledChessBoard[boardPositionY][seged] == 0 && seged >= 0)
	{

		if ((boardPositionY + seged) % 2 == 0)
			board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(197, 207, 145, 255));
		else
			board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(163, 179, 84, 255));

		board.PrincipledChessBoard[boardPositionY][seged] = 10;

		seged--;
	}

	if (seged >= 0)
	{
		if (board.PrincipledChessBoard[boardPositionY][seged] > 0)
		{
			board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY][seged] *= 10;
		}
	}
	
}

void Game::drawWhiteKnightWays(Board& board, int boardPositionX, int boardPositionY)
{
	if ((boardPositionY - 2 >= 0 && boardPositionY - 2 <= 7) && (boardPositionX - 1 >= 0 && boardPositionX - 1 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY - 2][boardPositionX - 1] > 0)
		{
			board.ChessBoard[boardPositionY - 2][boardPositionX - 1].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY - 2][boardPositionX - 1] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY - 2][boardPositionX - 1] == 0)
			{
				board.ChessBoard[boardPositionY - 2][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 2][boardPositionX - 1] = 10;
			}
		}
	}

	if ((boardPositionY - 1 >= 0 && boardPositionY - 1 <= 7) && (boardPositionX - 2 >= 0 && boardPositionX - 2 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 2] > 0)
		{
			board.ChessBoard[boardPositionY - 1][boardPositionX - 2].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 2] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 2] == 0)
			{
				board.ChessBoard[boardPositionY - 1][boardPositionX - 2].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 2] = 10;
			}
		}
	}

	if ((boardPositionY - 2 >= 0 && boardPositionY - 2 <= 7) && (boardPositionX + 1 >= 0 && boardPositionX + 1 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY - 2][boardPositionX + 1] > 0)
		{
			board.ChessBoard[boardPositionY - 2][boardPositionX + 1].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY - 2][boardPositionX + 1] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY - 2][boardPositionX + 1] == 0)
			{
				board.ChessBoard[boardPositionY - 2][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 2][boardPositionX + 1] = 10;
			}
		}
	}

	if ((boardPositionY - 1 >= 0 && boardPositionY - 1 <= 7) && (boardPositionX + 2 >= 0 && boardPositionX + 2 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 2] > 0)
		{
			board.ChessBoard[boardPositionY - 1][boardPositionX + 2].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 2] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 2] == 0)
			{
				board.ChessBoard[boardPositionY - 1][boardPositionX + 2].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 2] = 10;
			}
		}
	}

	if ((boardPositionY + 1 >= 0 && boardPositionY + 1 <= 7) && (boardPositionX - 2 >= 0 && boardPositionX - 2 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 2] > 0)
		{
			board.ChessBoard[boardPositionY + 1][boardPositionX - 2].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 2] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 2] == 0)
			{
				board.ChessBoard[boardPositionY + 1][boardPositionX - 2].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 2] = 10;
			}
		}
	}

	if ((boardPositionY + 2 >= 0 && boardPositionY + 2 <= 7) && (boardPositionX + 1 >= 0 && boardPositionX + 1 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY + 2][boardPositionX + 1] > 0)
		{
			board.ChessBoard[boardPositionY + 2][boardPositionX + 1].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY + 2][boardPositionX + 1] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY + 2][boardPositionX + 1] == 0)
			{
				board.ChessBoard[boardPositionY + 2][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY + 2][boardPositionX + 1] = 10;
			}
		}
	}

	if ((boardPositionY + 2 >= 0 && boardPositionY + 2 <= 7) && (boardPositionX - 1 >= 0 && boardPositionX - 1 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY + 2][boardPositionX - 1] > 0)
		{
			board.ChessBoard[boardPositionY + 2][boardPositionX - 1].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY + 2][boardPositionX - 1] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY + 2][boardPositionX - 1] == 0)
			{
				board.ChessBoard[boardPositionY + 2][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY + 2][boardPositionX - 1] = 10;
			}
		}
	}

	if ((boardPositionY + 1 >= 0 && boardPositionY + 1 <= 7) && (boardPositionX + 2 >= 0 && boardPositionX + 2 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 2] > 0)
		{
			board.ChessBoard[boardPositionY + 1][boardPositionX + 2].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 2] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 2] == 0)
			{
				board.ChessBoard[boardPositionY + 1][boardPositionX + 2].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 2] = 10;
			}
		}
	}

}

void Game::drawWhiteBishopWays(Board& board, int boardPositionX, int boardPositionY)
{
	int segedY = boardPositionY - 1;
	int segedX = boardPositionX + 1;

	while (board.PrincipledChessBoard[segedY][segedX] == 0 && segedX <= 7 && segedY >= 0)
	{

		board.ChessBoard[segedY][segedX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[segedY][segedX] = 10;

		segedX++;
		segedY--;
	}

	if (segedX <= 7 && segedY >= 0)
	{
		if (board.PrincipledChessBoard[segedY][segedX] > 0)
		{
			board.ChessBoard[segedY][segedX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[segedY][segedX] *= 10;
		}
	}

	cout << segedX << " " << segedY << endl;

	segedY = boardPositionY + 1;
	segedX = boardPositionX - 1;

	while (board.PrincipledChessBoard[segedY][segedX] == 0 && segedY <= 7 && segedX >= 0)
	{

		board.ChessBoard[segedY][segedX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[segedY][segedX] = 10;

		segedY++;
		segedX--;
	}

	if (segedY <= 7 && segedX >= 0)
	{
		if (board.PrincipledChessBoard[segedY][segedX] > 0)
		{
			board.ChessBoard[segedY][segedX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[segedY][segedX] *= 10;
		}
	}

	cout << segedX << " " << segedY << endl;

	segedY = boardPositionY - 1;
	segedX = boardPositionX - 1;

	while (board.PrincipledChessBoard[segedY][segedX] == 0 && segedY >= 0 && segedX >= 0)
	{

		board.ChessBoard[segedY][segedX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[segedY][segedX] = 10;

		segedY--;
		segedX--;
	}

	if (segedY >= 0 && segedX >= 0)
	{
		if (board.PrincipledChessBoard[segedY][segedX] > 0)
		{
			board.ChessBoard[segedY][segedX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[segedY][segedX] *= 10;
		}
	}

	cout << segedX << " " << segedY << endl;

	segedY = boardPositionY + 1;
	segedX = boardPositionX + 1;

	while (board.PrincipledChessBoard[segedY][segedX] == 0 && segedY <= 7 && segedX <= 7)
	{

		board.ChessBoard[segedY][segedX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[segedY][segedX] = 10;

		segedY++;
		segedX++;
	}

	if (segedX <= 7 && segedY <= 7)
	{
		if (board.PrincipledChessBoard[segedY][segedX] > 0)
		{
			board.ChessBoard[segedY][segedX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[segedY][segedX] *= 10;
		}
	}

}

void Game::drawWhiteQueenWays(Board& board, int boardPositionX, int boardPositionY)
{
	drawWhiteBishopWays(board, boardPositionX, boardPositionY);
	drawWhiteRookWays(board, boardPositionX, boardPositionY);
}

void Game::drawWhiteKingWays(Board& board, int boardPositionX, int boardPositionY)
{
	if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX] == 0)
		board.ChessBoard[boardPositionY - 1][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX] == 0)
		board.ChessBoard[boardPositionY + 1][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY][boardPositionX - 1] == 0)
		board.ChessBoard[boardPositionY][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY][boardPositionX + 1] == 0)
		board.ChessBoard[boardPositionY][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 1] == 0)
		board.ChessBoard[boardPositionY - 1][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 1] == 0)
		board.ChessBoard[boardPositionY - 1][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 1] == 0)
		board.ChessBoard[boardPositionY + 1][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 1] == 0)
		board.ChessBoard[boardPositionY + 1][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));
}


void Game::drawBlackPawnWays(Board& board, int boardPositionX, int boardPositionY)
{
	if (boardPositionY + 1 <= 7)
	{
		if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 1] < 0 && boardPositionX - 1 >= 0)
		{
			board.ChessBoard[boardPositionY + 1][boardPositionX - 1].setFillColor(sf::Color(215, 49, 49, 200));

			board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 1] *= 10; // ez jelzi az elmeleti tombnek, ha ilyen jelzesu helyre lepunk, akkor tudjunk lepni csak
		}


		if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 1] < 0 && boardPositionX + 1 <= 7)
		{
			board.ChessBoard[boardPositionY + 1][boardPositionX + 1].setFillColor(sf::Color(215, 49, 49, 200));

			board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 1] *= 10;
		}

		if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX] == 0)
		{
			board.ChessBoard[boardPositionY + 1][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));

			board.PrincipledChessBoard[boardPositionY + 1][boardPositionX] = 10;
		}
	}
}

void Game::drawBlackRookWays(Board& board, int boardPositionX, int boardPositionY)
{
	// Y tengelyen valo lehetseges utak
	short int seged = boardPositionY - 1;


	while (board.PrincipledChessBoard[seged][boardPositionX] == 0 && seged >= 0)
	{

		board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[seged][boardPositionX] = 10;

		seged--;
	}

	if (seged >= 0)
	{

		if (board.PrincipledChessBoard[seged][boardPositionX] < 0)
		{
			board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[seged][boardPositionX] *= 10;
		}
	}


	seged = boardPositionY + 1;

	while (board.PrincipledChessBoard[seged][boardPositionX] == 0 && seged <= 7)
	{

		board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[seged][boardPositionX] = 10;

		seged++;
	}

	if (seged <= 7)
	{
		if (board.PrincipledChessBoard[seged][boardPositionX] < 0)
		{
			board.ChessBoard[seged][boardPositionX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[seged][boardPositionX] *= 10;
		}
	}

	seged = boardPositionX + 1;

	while (board.PrincipledChessBoard[boardPositionY][seged] == 0 && seged <= 7)
	{

		board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[boardPositionY][seged] = 10;

		seged++;
	}

	if (seged <= 7)
	{
		if (board.PrincipledChessBoard[boardPositionY][seged] < 0)
		{
			board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY][seged] *= 10;
		}
	}

	seged = boardPositionX - 1;

	while (board.PrincipledChessBoard[boardPositionY][seged] == 0 && seged >= 0)
	{

		board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[boardPositionY][seged] = 10;

		seged--;
	}

	if (seged >= 0)
	{

		if (board.PrincipledChessBoard[boardPositionY][seged] < 0)
		{
			board.ChessBoard[boardPositionY][seged].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY][seged] *= 10;
		}
	}

}

void Game::drawBlackKnightWays(Board& board, int boardPositionX, int boardPositionY)
{
	if ((boardPositionY - 2 >= 0 && boardPositionY - 2 <= 7) && (boardPositionX - 1 >= 0 && boardPositionX - 1 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY - 2][boardPositionX - 1] < 0)
		{
			board.ChessBoard[boardPositionY - 2][boardPositionX - 1].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY - 2][boardPositionX - 1] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY - 2][boardPositionX - 1] == 0)
			{
				board.ChessBoard[boardPositionY - 2][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 2][boardPositionX - 1] = 10;
			}
		}
	}

	if ((boardPositionY - 1 >= 0 && boardPositionY - 1 <= 7) && (boardPositionX - 2 >= 0 && boardPositionX - 2 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 2] < 0)
		{
			board.ChessBoard[boardPositionY - 1][boardPositionX - 2].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 2] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 2] == 0)
			{
				board.ChessBoard[boardPositionY - 1][boardPositionX - 2].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 2] = 10;
			}
		}
	}

	if ((boardPositionY - 2 >= 0 && boardPositionY - 2 <= 7) && (boardPositionX + 1 >= 0 && boardPositionX + 1 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY - 2][boardPositionX + 1] < 0)
		{
			board.ChessBoard[boardPositionY - 2][boardPositionX + 1].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY - 2][boardPositionX + 1] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY - 2][boardPositionX + 1] == 0)
			{
				board.ChessBoard[boardPositionY - 2][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 2][boardPositionX + 1] = 10;
			}
		}
	}

	if ((boardPositionY - 1 >= 0 && boardPositionY - 1 <= 7) && (boardPositionX + 2 >= 0 && boardPositionX + 2 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 2] < 0)
		{
			board.ChessBoard[boardPositionY - 1][boardPositionX + 2].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 2] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 2] == 0)
			{
				board.ChessBoard[boardPositionY - 1][boardPositionX + 2].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 2] = 10;
			}
		}
	}

	if ((boardPositionY + 1 >= 0 && boardPositionY + 1 <= 7) && (boardPositionX - 2 >= 0 && boardPositionX - 2 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 2] < 0)
		{
			board.ChessBoard[boardPositionY + 1][boardPositionX - 2].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 2] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 2] == 0)
			{
				board.ChessBoard[boardPositionY + 1][boardPositionX - 2].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 2] = 10;
			}
		}
	}

	if ((boardPositionY + 2 >= 0 && boardPositionY + 2 <= 7) && (boardPositionX + 1 >= 0 && boardPositionX + 1 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY + 2][boardPositionX + 1] < 0)
		{
			board.ChessBoard[boardPositionY + 2][boardPositionX + 1].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY + 2][boardPositionX + 1] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY + 2][boardPositionX + 1] == 0)
			{
				board.ChessBoard[boardPositionY + 2][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY + 2][boardPositionX + 1] = 10;
			}
		}
	}

	if ((boardPositionY + 2 >= 0 && boardPositionY + 2 <= 7) && (boardPositionX - 1 >= 0 && boardPositionX - 1 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY + 2][boardPositionX - 1] < 0)
		{
			board.ChessBoard[boardPositionY + 2][boardPositionX - 1].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY + 2][boardPositionX - 1] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY + 2][boardPositionX - 1] == 0)
			{
				board.ChessBoard[boardPositionY + 2][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY + 2][boardPositionX - 1] = 10;
			}
		}
	}

	if ((boardPositionY + 1 >= 0 && boardPositionY + 1 <= 7) && (boardPositionX + 2 >= 0 && boardPositionX + 2 <= 7))
	{
		if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 2] < 0)
		{
			board.ChessBoard[boardPositionY + 1][boardPositionX + 2].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 2] *= 10;
		}

		else
		{
			if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 2] == 0)
			{
				board.ChessBoard[boardPositionY + 1][boardPositionX + 2].setFillColor(sf::Color(163, 179, 84, 255));

				board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 2] = 10;
			}
		}
	}
}

void Game::drawBlackBishopWays(Board& board, int boardPositionX, int boardPositionY)
{
	int segedY = boardPositionY - 1;
	int segedX = boardPositionX + 1;

	while (board.PrincipledChessBoard[segedY][segedX] == 0 && segedX <= 7 && segedY >= 0)
	{

		board.ChessBoard[segedY][segedX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[segedY][segedX] = 10;

		segedX++;
		segedY--;
	}

	if (segedX <= 7 && segedY >= 0)
	{
		if (board.PrincipledChessBoard[segedY][segedX] < 0)
		{
			board.ChessBoard[segedY][segedX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[segedY][segedX] *= 10;
		}
	}

	cout << segedX << " " << segedY << endl;

	segedY = boardPositionY + 1;
	segedX = boardPositionX - 1;

	while (board.PrincipledChessBoard[segedY][segedX] == 0 && segedY <= 7 && segedX >= 0)
	{

		board.ChessBoard[segedY][segedX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[segedY][segedX] = 10;

		segedY++;
		segedX--;
	}

	if (segedY <= 7 && segedX >= 0)
	{
		if (board.PrincipledChessBoard[segedY][segedX] < 0)
		{
			board.ChessBoard[segedY][segedX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[segedY][segedX] *= 10;
		}
	}


	segedY = boardPositionY - 1;
	segedX = boardPositionX - 1;

	while (board.PrincipledChessBoard[segedY][segedX] == 0 && segedY >= 0 && segedX >= 0)
	{

		board.ChessBoard[segedY][segedX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[segedY][segedX] = 10;

		segedY--;
		segedX--;
	}

	if (segedY >= 0 && segedX >= 0)
	{
		if (board.PrincipledChessBoard[segedY][segedX] < 0)
		{
			board.ChessBoard[segedY][segedX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[segedY][segedX] *= 10;
		}
	}

	cout << segedX << " " << segedY << endl;

	segedY = boardPositionY + 1;
	segedX = boardPositionX + 1;

	while (board.PrincipledChessBoard[segedY][segedX] == 0 && segedY <= 7 && segedX <= 7)
	{

		board.ChessBoard[segedY][segedX].setFillColor(sf::Color(163, 179, 84, 255));
		board.PrincipledChessBoard[segedY][segedX] = 10;

		segedY++;
		segedX++;
	}

	if (segedX <= 7 && segedY <= 7)
	{
		if (board.PrincipledChessBoard[segedY][segedX] < 0)
		{
			board.ChessBoard[segedY][segedX].setFillColor(sf::Color(215, 49, 49, 200));
			board.PrincipledChessBoard[segedY][segedX] *= 10;
		}
	}
}

void Game::drawBlackQueenWays(Board& board, int boardPositionX, int boardPositionY)
{
	drawBlackRookWays(board, boardPositionX, boardPositionY);
	drawBlackBishopWays(board, boardPositionX, boardPositionY);
}

void Game::drawBlackKingWays(Board& board, int boardPositionX, int boardPositionY)
{
	if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX] == 0)
		board.ChessBoard[boardPositionY - 1][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX] == 0)
		board.ChessBoard[boardPositionY + 1][boardPositionX].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY][boardPositionX - 1] == 0)
		board.ChessBoard[boardPositionY][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY][boardPositionX + 1] == 0)
		board.ChessBoard[boardPositionY][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX - 1] == 0)
		board.ChessBoard[boardPositionY - 1][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY - 1][boardPositionX + 1] == 0)
		board.ChessBoard[boardPositionY - 1][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX - 1] == 0)
		board.ChessBoard[boardPositionY + 1][boardPositionX - 1].setFillColor(sf::Color(163, 179, 84, 255));

	if (board.PrincipledChessBoard[boardPositionY + 1][boardPositionX + 1] == 0)
		board.ChessBoard[boardPositionY + 1][boardPositionX + 1].setFillColor(sf::Color(163, 179, 84, 255));
}


//----------------------------------------------------------------------------- End of functions ---------------------------------------------------------------------------------------------------

//Display
void Game::Display()
{
	this->window->display();
}

void Game::isFigurePressed(Board& board)
{
	//Megnezzuk, hogy valamire kattintott-e egy olyan mezore, ahol all babu?
	//--> ha igen, akkor az elozo szinezest toroljuk, es atfessuk az ideiglenes mezot mas szinure
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if(this->isMouseHeld == false)
		{
			lookedForSquareIsFound = false;
			isMouseHeld = true;
			for (int i = 0; i < 8 && !lookedForSquareIsFound; i++)
			{
				for (int j = 0; j < 8 && !lookedForSquareIsFound; j++)
				{
					if (board.PrincipledChessBoard[i][j] != 0)
					{
						if (board.ChessBoard[i][j].getGlobalBounds().contains(this->mousePosView))
						{
							
							board.ChessBoard[i][j].setFillColor(sf::Color(163, 179, 84, 255));
							type = board.PrincipledChessBoard[i][j];

							drawPossibleWays(board, type, j, i);

							if (startX >= 0 && startY >= 0)
							{
								if ((startX + startY) % 2 == 0)
								{
									board.ChessBoard[startY][startX].setFillColor(sf::Color::White);
								}

								else
								{
									board.ChessBoard[startY][startX].setFillColor(sf::Color(172, 180, 134, 255));

								}
							}

							if (j == startX && i == startY)
							{
								startX = -1;
								startY = -1;
							}
							else
							{
								startX = j;
								startY = i;
							}

							for (int i = 0; i < 8; i++)
							{
								for (int j = 0; j < 8; j++)
									cout << board.PrincipledChessBoard[i][j] << " ";

								cout << endl;
							}

							lookedForSquareIsFound = true;

						}

					}
					
				}
				
			}
		}
	}

	else
	{
		isMouseHeld = false;
	}
}

void Game::updateMousePosition()
{
	this->resetClockAndDeltaTime();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);

	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateGameLogic()
{
	//1.) update the events:
	this->pollEvents();

	//2.) Update the mouse mosition relative to the window
	updateMousePosition();

	isFigurePressed(this->gameBoard);
}

void Game::render()
{
	Clear();

	Draw();

	Display();
}