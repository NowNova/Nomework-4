#include <SFML/Graphics.hpp>
#include "source.hpp"
#include "Game.hpp"

int main()
{
    saa::Game game(1100, 1000, "Game");
    game.Setup(10);
    game.Life();

    return 0;
}