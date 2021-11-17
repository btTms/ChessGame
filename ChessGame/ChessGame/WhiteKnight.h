#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>


class WhiteKnight
{

public:

	//Constructor:
	WhiteKnight();

	//Getter functions:
	void DrawWhiteKnights(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationWhiteKnight;
	vector<sf::RectangleShape> whiteKnightsVector;
	sf::Texture whiteKnightTexture;
	int type;

	//Functions:
	void initWhiteKnightsVector();
};

