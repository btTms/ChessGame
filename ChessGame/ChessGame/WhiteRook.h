#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>


class WhiteRook
{
public:

	//Constructor:
	WhiteRook();

	//Getter functions:
	void DrawWhiteRooks(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationWhiteRook;
	vector<sf::RectangleShape> whiteRooksVector;
	sf::Texture whiteRookTexture;
	int type;

	//Functions:
	void initWhiteRooksVector();
};

