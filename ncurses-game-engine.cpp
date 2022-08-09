#include "ncurses-game-engine.h"

  ConsoleGameEngine::ConsoleGameEngine()
  {
    m_nScreenWidth  = 80;
    m_nScreenHeight = 30;
  }

  void ConsoleGameEngine::Draw(int x, int y, short c = 0x2588, short col = 0x000F)
  {
    if ( x >= 0 && x <= m_nScreenWidth && y >= 0 && y <= m_nScreenHeight)
    {

    }
  }

