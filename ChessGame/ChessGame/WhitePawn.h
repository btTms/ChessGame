#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>




class WhitePawn
{

public:

	//Constructor:
	WhitePawn();

	//Getter functions:
	void DrawWhitePawns(sf::RenderWindow* window);
	int getType();

	//Merre es mennyit kell megtegyen az adott negyzet ahhoz, hogy elerje vegso celjat!
	double distanceX;
	double distanceY;
	double directionX;
	double directionY;


private:

	//Variables:
	sf::RectangleShape initializationWhitePawn;
	vector<sf::RectangleShape> whitePawnsVector;
	sf::Texture whitePawnTexture;


	int type; // int-kent taroljuk el azt, hogy a feherek kozul miyen babu


	//Functions:
	void initWhitePawnsVector();




};

