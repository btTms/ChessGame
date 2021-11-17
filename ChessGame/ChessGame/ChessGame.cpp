#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


#include "Game.h"

#include <iostream>

using namespace std;


int main()
{

    Game chessGame;

    while (chessGame.running())
    {

        chessGame.updateGameLogic();

        chessGame.render();

    }



    return 0;
}


