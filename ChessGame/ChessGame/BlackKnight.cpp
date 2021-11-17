#include "BlackKnight.h"

BlackKnight::BlackKnight()
{
	initBlackKnightsVector();
	this-> type = 3;
}

int BlackKnight::getType()
{
	return type;
}

void BlackKnight::initBlackKnightsVector()
{
	//A nagysaga:
	initializationBlackKnight.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	blackKnightTexture.loadFromFile("textures/black/FeketeLo.png");
	//Textura raadasa:
	initializationBlackKnight.setTexture(&blackKnightTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	blackKnightsVector.push_back(initializationBlackKnight);
	blackKnightsVector[0].setPosition(sf::Vector2f(118 + 41.f, 41.f));

	blackKnightsVector.push_back(initializationBlackKnight);
	blackKnightsVector[1].setPosition(sf::Vector2f(6 * 118.f + 41.f, 41.f));
}

void BlackKnight::DrawBlackKnights(sf::RenderWindow* window)
{
	for (int i = 0; i < blackKnightsVector.size(); i++)
	{
		window->draw(blackKnightsVector[i]);
	}
}