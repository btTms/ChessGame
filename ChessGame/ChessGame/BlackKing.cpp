#include "BlackKing.h"

BlackKing::BlackKing()
{
	initBlackKingVector();
	this->type = 6;
}

int BlackKing::getType()
{
	return type;
}

void BlackKing::initBlackKingVector()
{
	//A nagysaga:
	initializationBlackKing.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	blackKingTexture.loadFromFile("textures/black/FeketeKiraly.png");
	//Textura raadasa:
	initializationBlackKing.setTexture(&blackKingTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	blackKingVector.push_back(initializationBlackKing);
	blackKingVector[0].setPosition(sf::Vector2f(4 * 118 + 41.f, 41.f));
}

void BlackKing::DrawBlackKing(sf::RenderWindow* window)
{
	for (int i = 0; i < blackKingVector.size(); i++)
	{
		window->draw(blackKingVector[i]);
	}
}
