#include "BlackBishop.h"

BlackBishop::BlackBishop()
{
	initBlackBishopsVector();
	this->type = 4;
}

int BlackBishop::getType()
{
	return type;
}

void BlackBishop::initBlackBishopsVector()
{
	//A nagysaga:
	initializationBlackBishop.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	blackBishopTexture.loadFromFile("textures/black/FeketeFuto.png");
	//Textura raadasa:
	initializationBlackBishop.setTexture(&blackBishopTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	blackBishopsVector.push_back(initializationBlackBishop);
	blackBishopsVector[0].setPosition(sf::Vector2f(2 * 118.f + 41.f, 41.f));

	blackBishopsVector.push_back(initializationBlackBishop);
	blackBishopsVector[1].setPosition(sf::Vector2f(5 * 118.f + 41.f, 41.f));
}

void BlackBishop::DrawBlackBishops(sf::RenderWindow* window)
{
	for (int i = 0; i < blackBishopsVector.size(); i++)
	{
		window->draw(blackBishopsVector[i]);
	}
}