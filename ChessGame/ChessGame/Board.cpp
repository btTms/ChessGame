#include "Board.h"


Board::Board()
{
	this->build(segedNegyzet);
	this->initPrincipledChessBoard();
	this->initBorder();
	this->initSetterString();
	this->intitFont();
	this->initGui();
}

void Board::initPrincipledChessBoard()
{
	for (int i = 0; i <= 3; i++)
	{
		if (i != 3)
		{
			PrincipledChessBoard[0][i] = i + 2;
			PrincipledChessBoard[0][7 - i] = i + 2;
		}

		else
		{
			PrincipledChessBoard[0][i] = 5;
			PrincipledChessBoard[0][7 - i] = 6;
		}
	}

	for (int i = 0; i < 8; i++)
		PrincipledChessBoard[1][i] = 1; ///1!!!!!!!!1


	for (int i = 2; i <= 5; i++)
	{
		for (int j = 0; j < 8; j++)
			PrincipledChessBoard[i][j] = 0;
	}

	for (int i = 0; i < 8; i++)
		PrincipledChessBoard[6][i] = 0; /// -1!!!!!!!!!!

	for (int i = 0; i <= 3; i++)
	{
		if (i != 3)
		{
			PrincipledChessBoard[7][i] = - (i + 2);
			PrincipledChessBoard[7][7 - i] = - (i + 2);
		}

		else
		{
			PrincipledChessBoard[7][i] = -5;
			PrincipledChessBoard[7][7 - i] = -6;
		}
	}

	//Az elmeteli sakk plya inicalizasa:
	/*2 3 4 5 6 4 3 2 
	1 1 1 1 1 1 1 1
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	-1 -1 -1 -1 -1 -1 -1 -1
	-2 -3 -4 -5 -6 -4 -3 -2*/
}

void Board::build(sf::RectangleShape shape)
{
	shape.setSize(sf::Vector2f(118.f, 118.f));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				shape.setFillColor(sf::Color::White);
				shape.setPosition(sf::Vector2f(j * 118 + 32.f, i * 118.f + 32.f));
				ChessBoard[i][j] = shape;
			}

			else
			{
				shape.setFillColor(sf::Color(172, 180, 134, 255));
				shape.setPosition(sf::Vector2f(j * 118.f + 32.f, i * 118.f + 32.f));
				ChessBoard[i][j] = shape;
			}
			
		}
	}
}
void Board::initBorder()
{
	this->border.setSize(sf::Vector2f(957.f, 957.f));
	this->border.setPosition(sf::Vector2f(25.f, 25.f));
	this->border.setFillColor(sf::Color::Black);
}

void Board::initSetterString()
{
	//Szamok:
	setterString.push_back("?");
	setterString.push_back("8");
	setterString.push_back("7");
	setterString.push_back("6");
	setterString.push_back("5");
	setterString.push_back("4");
	setterString.push_back("3");
	setterString.push_back("2");
	setterString.push_back("1");

	//Betuk:
	setterString.push_back("A");
	setterString.push_back("B");
	setterString.push_back("C");
	setterString.push_back("D");
	setterString.push_back("E");
	setterString.push_back("F");
	setterString.push_back("G");
	setterString.push_back("H");


}

void Board::intitFont()
{
	this->font.loadFromFile("fonts/Dosis-Light.ttf");
}

void Board::initGui()
{
	//Szamok inicializalasa:
	// 
	//Jobb:
	for (int i = 1; i <= 8; i++)
	{
		boardTexts[i].setFont(font);
		boardTexts[i].setFillColor(sf::Color::Black);
		boardTexts[i].setCharacterSize(20);
		boardTexts[i].setPosition(sf::Vector2f(12.f, i * 118 - 59 + 20));
		boardTexts[i].setString(setterString[i]);
	}

	//Bal:
	for (int i = 9; i <= 16; i++)
	{
		boardTexts[i].setFont(font);
		boardTexts[i].setFillColor(sf::Color::Black);
		boardTexts[i].setCharacterSize(20);
		boardTexts[i].setPosition(sf::Vector2f(986.f, (i - 8) * 118 - 59 + 20));
		boardTexts[i].setString(setterString[i - 8]);
	}
	//1->16-ig csak szamok vannak a tombben


	//Betuk:

	//Fent:
	for (int i = 17; i <= 24; i++)
	{
		boardTexts[i].setFont(font);
		boardTexts[i].setFillColor(sf::Color::Black);
		boardTexts[i].setCharacterSize(16);
		boardTexts[i].setPosition(sf::Vector2f((i - 16) * 118 - 69 + 32, 8.f));
		boardTexts[i].setString(setterString[i - 8]);

	}

	//Lent:
	for (int i = 25; i <= 32; i++)
	{
		boardTexts[i].setFont(font);
		boardTexts[i].setFillColor(sf::Color::Black);
		boardTexts[i].setCharacterSize(16);
		boardTexts[i].setPosition(sf::Vector2f((i - 24) * 118 - 65 + 32, 983.f));
		boardTexts[i].setString(setterString[i - 16]);
	}
	

	//17->32-ig csak betuk vannak a tombben
}

void Board::RenderGui(sf::RenderWindow* window)
{
	for (int i = 1; i <= 32; i++)
		window->draw(boardTexts[i]);
}

void Board::DrawBorder(sf::RenderWindow* window)
{
	window->draw(border);
}

void Board::DrawChessBoard(sf::RenderWindow* window)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			window->draw(ChessBoard[i][j]);
		}
	}
}

