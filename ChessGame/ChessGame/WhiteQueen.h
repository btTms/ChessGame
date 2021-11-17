#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>


class WhiteQueen
{

public:

	//Constructor:
	WhiteQueen();

	//Getter functions:
	void DrawWhiteQueen(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationWhiteQueen;
	vector<sf::RectangleShape> whiteQueenVector;
	sf::Texture whiteQueenTexture;
	int type;

	//Functions:
	void initWhiteQueenVector();
};