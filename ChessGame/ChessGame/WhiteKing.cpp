#include "WhiteKing.h"

WhiteKing::WhiteKing()
{
	initWhiteKingVector();
	this->type = -6;
}

int WhiteKing::getType()
{
	return type;
}

void WhiteKing::initWhiteKingVector()
{
	//A nagysaga:
	initializationWhiteKing.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	whiteKingTexture.loadFromFile("textures/white/FeherKiraly.png");
	//Textura raadasa:
	initializationWhiteKing.setTexture(&whiteKingTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	whiteKingVector.push_back(initializationWhiteKing);
	whiteKingVector[0].setPosition(sf::Vector2f(4 * 118 + 41.f, 7 * 118.f + 41.f));
}

void WhiteKing::DrawWhiteKing(sf::RenderWindow* window)
{
	for (int i = 0; i < whiteKingVector.size(); i++)
	{
		window->draw(whiteKingVector[i]);
	}
}
