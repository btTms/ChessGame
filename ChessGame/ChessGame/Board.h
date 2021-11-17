#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <vector>
#include <string>
using namespace std;


//Elv:
//akarunk egy 8 * 8 - as tablat, amelyet 64 db RectangleShape fog kepezni(feherek es feketek!), ey lesz a tulajdonkeppeni palya, meg meg melleje szamot, betuket is csinalhatunk
//csak azet, hogy atalathatobb legyen.
//Ezutan csinalunk megint egy 8 * 8 - as tombot, amelyeket megtoltunk 1 - esekkel(ha azon a kockan eppen all valaki), vagy 0 - assal(hogyha pedig nem), 2 - essel fogjuk jelolni, azt a mazot,
//ahova az adott tipusu babu lephet

class Board
{

public:

	//Constuctor

	Board();

	// A palya renderelese: (ez kerul a Game osztaly render fuggvenyebe)
	// Getter functions:
	void DrawChessBoard(sf::RenderWindow* window);
	void DrawBorder(sf::RenderWindow *window);
	void RenderGui(sf::RenderWindow* window);
	//PrincipledChessBoard:
	int PrincipledChessBoard[8][8];
	//ChessBoard:
	sf::RectangleShape ChessBoard[8][8];

private:
	
	//Setters:
	sf::RectangleShape segedNegyzet;
	sf::RectangleShape border;

	//Font and texts
	sf::Font font;
	sf::Text boardTexts[32 + 1];
	vector<string> setterString;

	//Setter functions:

	// A Palya letrehozasa (ez kerul a konstruktorba)
	void initPrincipledChessBoard();
	void build(sf::RectangleShape shape);
	void initBorder();
	void initSetterString();
	void intitFont();
	void initGui();

};

