#include "BlackRook.h"

BlackRook::BlackRook()
{
	initBlackRooksVector();
	this->type = 2;
}

int BlackRook::getType()
{
	return type;
}

void BlackRook::initBlackRooksVector()
{
	//A nagysaga:
	initializationBlackRook.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	blackRookTexture.loadFromFile("textures/black/FeketeBastya.png");
	//Textura raadasa:
	initializationBlackRook.setTexture(&blackRookTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	blackRooksVector.push_back(initializationBlackRook);
	blackRooksVector[0].setPosition(sf::Vector2f(41.f, 41.f));

	blackRooksVector.push_back(initializationBlackRook);
	blackRooksVector[1].setPosition(sf::Vector2f(7 * 118.f + 41.f, 41.f));
}

void BlackRook::DrawBlackRooks(sf::RenderWindow* window)
{
	for (int i = 0; i < blackRooksVector.size(); i++)
	{
		window->draw(blackRooksVector[i]);
	}
}