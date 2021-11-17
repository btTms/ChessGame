#include "BlackPawn.h"

BlackPawn::BlackPawn()
{
	initBlackPawnsVector();
	this->type = 1;
}

int BlackPawn::getType()
{
	return type;
}

void BlackPawn::initBlackPawnsVector()
{
	//A nagysaga:
	initializationBlackPawn.setSize(sf::Vector2f(100.f, 100.f));
	//Milyen texturat kap:
	blackPawnTexture.loadFromFile("textures/black/FeketeGyalog.png");
	//Textura raadasa:
	initializationBlackPawn.setTexture(&blackPawnTexture);

	//A vector megtoltese initizalizationBlackPawn tipusu negyzetekkel, plusz poziciot adunk nekik:
	for (int i = 0; i < 8; i++)
	{
		blackPawnsVector.push_back(initializationBlackPawn);
		blackPawnsVector[i].setPosition(sf::Vector2f(i * 118.f + 41.f, 1 * 118.f + 41.f)); //Ezek a koordinatak kesobb hasznosak lesznek
	}

}

void BlackPawn::DrawBlackPawns(sf::RenderWindow* window)
{
	for (int i = 0; i < blackPawnsVector.size(); i++)
	{
		window->draw(blackPawnsVector[i]);
	}
}
