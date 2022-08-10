#include "ncurses-game-engine.h"
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <assert.h>
#include <stdexcept>

  ConsoleGameEngine::ConsoleGameEngine(int x, int y, int width, int height, bool border, std::string label)
  {
    m_nProgramStatus = EXIT_SUCCESS;
    WINDOW *console;
    int lnConsoleX = 0;
    int lnConsoleY = 0;
    console = initscr();
    border(0,0,0,0,0,0,0,0);
    getmaxyx(console, lnConsoleY, lnConsoleX);
    if (!console ) {
      endwin();
      std::cout << "Error initializing nCurses \n";
      m_nProgramStatus = EXIT_FAILURE;
      return;
    }
    printw("ConsoleY:%d , ", lnConsoleY);
    printw("ConsoleX:%d", lnConsoleX);
    if ( width > lnConsoleX ) {
      endwin();
      std::cout << "Error Console game is larger in (x,y) than Terminal or y or y are larger than height, width \n";
      // throw std::invalid_argument( "received negative value" );
      m_nProgramStatus = EXIT_FAILURE;
      return;
    }
    m_nScreenWidth  = width;
    m_nScreenHeight = height;
    m_pwindow = subwin(console, m_nScreenHeight, m_nScreenWidth, y, x);
    if (!m_pwindow) {
      endwin();
      std::cout << "Error creating main window \n";
      m_nProgramStatus = EXIT_FAILURE;
      return;
    }
    if (border)
      wborder(m_pwindow,0,0,0,0,0,0,0,0);

    m_bufferScreen = new CHAR_INFO[m_nScreenWidth * m_nScreenHeight];
    memset(m_bufferScreen, 0, sizeof(CHAR_INFO) * m_nScreenWidth * m_nScreenHeight);

    refresh();
    getch();
  }

  void ConsoleGameEngine::Draw(int x, int y, short c = 0x2588, short col = 0x000F)
  {
    if ( x >= 0 && x <= m_nScreenWidth && y >= 0 && y <= m_nScreenHeight)
    {

    }
  }

  void ConsoleGameEngine::DisplayFrame()
  {
    for (int y = 0; y < m_nScreenHeight; y++)
      for (int x = 0; x < m_nScreenWidth; x++)
      {
        mvwaddch(m_pwindow, y, x, m_bufferScreen[y * m_nScreenWidth + x].utf8char);
      }
    /////////////////// quitar de aqui
    wrefresh(m_pwindow);
    getch();
    ///////////////
  }

  void ConsoleGameEngine::print_str(std::string str, int x, int y)
  {
    CHAR_INFO *ptr;

    ptr = m_bufferScreen + ( y * m_nScreenWidth + x);

      for (int i = 0; i < str.length(); i++ ) {
        ptr->utf8char = str[i];
        ptr++;
      }
  }

  ConsoleGameEngine::~ConsoleGameEngine()
  {
    delete [] m_bufferScreen;
    endwin();
  }

