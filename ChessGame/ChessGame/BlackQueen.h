#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>

class BlackQueen
{
public:

	//Constructor:
	BlackQueen();

	//Getter functions:
	void DrawBlackQueen(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationBlackQueen;
	vector<sf::RectangleShape> blackQueenVector;
	sf::Texture blackQueenTexture;
	int type;

	//Functions:
	void initBlackQueenVector();
};

