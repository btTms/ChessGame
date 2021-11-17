#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>

class WhiteBishop
{

public:

	//Constructor:
	WhiteBishop();

	//Getter functions:
	void DrawWhiteBishops(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationWhiteBishop;
	vector<sf::RectangleShape> whiteBishopsVector;
	sf::Texture whiteBishopTexture;
	int type;

	//Functions:
	void initWhiteBishopsVector();
};

