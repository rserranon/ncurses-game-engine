#include <iostream>
#include "ncurses-game-engine.h"

class GameDemo: public ConsoleGameEngine
{
  public:

    GameDemo()
    {
      m_sAppName = "Game Demo";
    }
};


int main()
{
  std::cout << "Example game using ncurses-game-engine\n";

  int status = 0;
  ConsoleGameEngine game;

  status = game.ConstructConsole(1,1,20,14, true, "Nada");

  if (status != 0)
  {
    game.print_str("hello world", 1, 1);

    game.DisplayFrame();

    std::cout << "End of game";
  }

  return status;
}
