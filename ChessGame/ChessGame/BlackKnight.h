#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>

class BlackKnight
{
public:

	//Constructor:
	BlackKnight();

	//Getter functions:
	void DrawBlackKnights(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationBlackKnight;
	vector<sf::RectangleShape> blackKnightsVector;
	sf::Texture blackKnightTexture;
	int type;

	//Functions:
	void initBlackKnightsVector();
};

