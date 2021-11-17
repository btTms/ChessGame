#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>

class BlackPawn
{

public:

	//Constructor:
	BlackPawn();

	//Getter functions:
	void DrawBlackPawns(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationBlackPawn;
	vector<sf::RectangleShape> blackPawnsVector;
	sf::Texture blackPawnTexture;
	int type;

	//Functions:
	void initBlackPawnsVector();
};

