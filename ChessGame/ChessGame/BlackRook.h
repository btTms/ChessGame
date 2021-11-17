#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>

class BlackRook
{
public:

	//Constructor:
	BlackRook();

	//Getter functions:
	void DrawBlackRooks(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationBlackRook;
	vector<sf::RectangleShape> blackRooksVector;
	sf::Texture blackRookTexture;
	int type;

	//Functions:
	void initBlackRooksVector();
};

