#include <iostream>
#include <string>
#include "ncurses-game-engine.h"

class GameDemo: public ConsoleGameEngine
{
  public:

    GameDemo()
    {
      m_sAppName = "Game Demo";
    }

  protected:

    bool OnUserUpdate()
    {
      print_str(std::to_string(m_nKeyPressed), 6, 6);
      switch (m_nKeyPressed)
      {
        case KEY_DOWN:
          print_str("KEY_DOWN ", 5, 5);
          break;
        case KEY_UP:
          print_str("KEY_UP   ", 5, 5);
          break;
        case KEY_LEFT:
          print_str("KEY_LEFT ", 5, 5);
          break;
        case KEY_RIGHT:
          print_str("KEY_RIGHT", 5, 5);
          break;
      }
      return true;
    }
};


int main()
{
  std::cout << "Example game using ncurses-game-engine\n";

  int status = 0;
  GameDemo game;

  status = game.ConstructConsole(1,1,20,14, true, "Titulo");

  if (status == 0)
  {
    game.print_str("hello world", 1, 1, PAIR_YELLOW_BLACK);
    game.Draw(6, 2);

    game.Draw( 7, 2, 0x2665,   PAIR_BLUE_BLACK );
    game.Draw( 8, 2, 0x2588,   PAIR_GREEN_BLACK );
    game.Draw( 9, 2, L'\u2665', PAIR_RED_BLACK );
    game.Start();

    std::cout << "End of game";
  }

  return status;
}
