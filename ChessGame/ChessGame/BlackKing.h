#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>

class BlackKing
{
public:

	//Constructor:
	BlackKing();

	//Getter functions:
	void DrawBlackKing(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationBlackKing;
	vector<sf::RectangleShape> blackKingVector;
	sf::Texture blackKingTexture;
	int type;

	//Functions:
	void initBlackKingVector();
};

