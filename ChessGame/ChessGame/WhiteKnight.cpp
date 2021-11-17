#include "WhiteKnight.h"

WhiteKnight::WhiteKnight()
{
	initWhiteKnightsVector();
	this->type = -3;
}

int WhiteKnight::getType()
{
	return type;
}
void WhiteKnight::initWhiteKnightsVector()
{
	//A nagysaga:
	initializationWhiteKnight.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	whiteKnightTexture.loadFromFile("textures/white/FeherLo.png");
	//Textura raadasa:
	initializationWhiteKnight.setTexture(&whiteKnightTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	whiteKnightsVector.push_back(initializationWhiteKnight);
	whiteKnightsVector[0].setPosition(sf::Vector2f(118 + 41.f, 7 * 118.f + 41.f));

	whiteKnightsVector.push_back(initializationWhiteKnight);
	whiteKnightsVector[1].setPosition(sf::Vector2f(6 * 118.f + 41.f, 7 * 118.f + 41.f));
}

void WhiteKnight::DrawWhiteKnights(sf::RenderWindow* window)
{
	for (int i = 0; i < whiteKnightsVector.size(); i++)
	{
		window->draw(whiteKnightsVector[i]);
	}
}