#include <iostream>
#include "ncurses-game-engine.h"

int main()
{
  std::cout << "Example game using ncurses-game-engine\n";

  ConsoleGameEngine game(1,1,20,14, true, "Nada");

  game.print_str("hello world", 1, 1);

  game.DisplayFrame();

  std::cout << "End of game";

  return game.m_nProgramStatus;
}
