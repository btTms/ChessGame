#include "WhiteRook.h"

WhiteRook::WhiteRook()
{
	initWhiteRooksVector();
	this->type = -2;
}

int WhiteRook::getType()
{
	return type;
}
void WhiteRook::initWhiteRooksVector()
{
	//A nagysaga:
	initializationWhiteRook.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	whiteRookTexture.loadFromFile("textures/white/FeherBastya.png");
	//Textura raadasa:
	initializationWhiteRook.setTexture(&whiteRookTexture);

	//A vector megtoltese initizalizationWhiteRook tipusu negyzetekkel, plusz poziciot adunk nekik:
	whiteRooksVector.push_back(initializationWhiteRook);
	whiteRooksVector[0].setPosition(sf::Vector2f(41.f, 7.f * 118.f + 41.f));

	whiteRooksVector.push_back(initializationWhiteRook);
	whiteRooksVector[1].setPosition(sf::Vector2f(7 * 118.f + 41.f, 7.f * 118.f + 41.f));
}

void WhiteRook::DrawWhiteRooks(sf::RenderWindow* window)
{
	for (int i = 0; i < whiteRooksVector.size(); i++)
	{
		window->draw(whiteRooksVector[i]);
	}
}