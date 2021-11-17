#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>


class WhiteKing
{
public:

	//Constructor:
	WhiteKing();

	//Getter functions:
	void DrawWhiteKing(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationWhiteKing;
	vector<sf::RectangleShape> whiteKingVector;
	sf::Texture whiteKingTexture;
	int type;

	//Functions:
	void initWhiteKingVector();
};

