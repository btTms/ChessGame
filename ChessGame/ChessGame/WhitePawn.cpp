#include "WhitePawn.h"


WhitePawn::WhitePawn()
{
	initWhitePawnsVector();
	this->type = -1;
	this->distanceX = 0;
	this->distanceY = 0;
	this->directionX = 0;
	this->directionY = 0;
}

int WhitePawn::getType()
{
	return type;
}

void WhitePawn::initWhitePawnsVector()
{
	//A nagysaga:
	initializationWhitePawn.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	whitePawnTexture.loadFromFile("textures/white/FeherGyalog.png");
	//Textura raadasa:
	initializationWhitePawn.setTexture(&whitePawnTexture);

	//A vector megtoltese initizalizationWhitePawn tipusu negyzetekkel, plusz poziciot adunk nekik:
	for (int i = 0; i < 8; i++)
	{
		whitePawnsVector.push_back(initializationWhitePawn);
		whitePawnsVector[i].setPosition(sf::Vector2f(i * 118.f + 41.f, 6 * 118 + 41.f)); //Ezek a koordinatak kesobb hasznosak lesznek
	}

}

void WhitePawn::DrawWhitePawns(sf::RenderWindow* window)
{
	for (int i = 0; i < whitePawnsVector.size(); i++)
	{
		window->draw(whitePawnsVector[i]);
	}
}
