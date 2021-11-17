#include "WhiteBishop.h"

WhiteBishop::WhiteBishop()
{
	initWhiteBishopsVector();
	this->type = -4;
}

int WhiteBishop::getType()
{
	return type;
}

void WhiteBishop::initWhiteBishopsVector()
{
	//A nagysaga:
	initializationWhiteBishop.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	whiteBishopTexture.loadFromFile("textures/white/FeherFuto.png");
	//Textura raadasa:
	initializationWhiteBishop.setTexture(&whiteBishopTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	whiteBishopsVector.push_back(initializationWhiteBishop);
	whiteBishopsVector[0].setPosition(sf::Vector2f(2 * 118.f + 41.f, 7 * 118.f + 41.f));

	whiteBishopsVector.push_back(initializationWhiteBishop);
	whiteBishopsVector[1].setPosition(sf::Vector2f(5 * 118.f + 41.f, 7 * 118.f + 41.f));
}

void WhiteBishop::DrawWhiteBishops(sf::RenderWindow* window)
{
	for (int i = 0; i < whiteBishopsVector.size(); i++)
	{
		window->draw(whiteBishopsVector[i]);
	}
}
