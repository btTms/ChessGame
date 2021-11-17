#include "BlackQueen.h"

BlackQueen::BlackQueen()
{
	initBlackQueenVector();
	this->type = 5;
}

int BlackQueen::getType()
{
	return type;
}

void BlackQueen::initBlackQueenVector()
{
	//A nagysaga:
	initializationBlackQueen.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	blackQueenTexture.loadFromFile("textures/black/FeketeKiralyno.png");
	//Textura raadasa:
	initializationBlackQueen.setTexture(&blackQueenTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	blackQueenVector.push_back(initializationBlackQueen);
	blackQueenVector[0].setPosition(sf::Vector2f(3 * 118 + 41.f, 41.f));
}

void BlackQueen::DrawBlackQueen(sf::RenderWindow* window)
{
	for (int i = 0; i < blackQueenVector.size(); i++)
	{
		window->draw(blackQueenVector[i]);
	}
}