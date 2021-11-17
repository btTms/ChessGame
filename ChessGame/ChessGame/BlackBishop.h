#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>


class BlackBishop
{
public:

	//Constructor:
	BlackBishop();

	//Getter functions:
	void DrawBlackBishops(sf::RenderWindow* window);
	int getType();

private:

	//Variables:
	sf::RectangleShape initializationBlackBishop;
	vector<sf::RectangleShape> blackBishopsVector;
	sf::Texture blackBishopTexture;
	int type;

	//Functions:
	void initBlackBishopsVector();
};

