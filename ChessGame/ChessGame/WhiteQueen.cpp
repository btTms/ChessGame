#include "WhiteQueen.h"

WhiteQueen::WhiteQueen()
{
	initWhiteQueenVector();
	this->type = -5;
}

int WhiteQueen::getType()
{
	return type;
}
void WhiteQueen::initWhiteQueenVector()
{
	//A nagysaga:
	initializationWhiteQueen.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	whiteQueenTexture.loadFromFile("textures/white/FeherKiralyno.png");
	//Textura raadasa:
	initializationWhiteQueen.setTexture(&whiteQueenTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	whiteQueenVector.push_back(initializationWhiteQueen);
	whiteQueenVector[0].setPosition(sf::Vector2f(3 * 118 + 41.f, 7 * 118.f + 41.f));
}

void WhiteQueen::DrawWhiteQueen(sf::RenderWindow* window)
{
	for (int i = 0; i < whiteQueenVector.size(); i++)
	{
		window->draw(whiteQueenVector[i]);
	}
}