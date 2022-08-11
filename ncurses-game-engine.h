#include <ncurses.h>
#include <string>

typedef struct _CHAR_INFO {
  uint8_t  utf8char;
  int  Attributes;
} CHAR_INFO;

class ConsoleGameEngine
{
public:
  ConsoleGameEngine();

  int ConstructConsole(int x, int y, int width, int height, bool border, std::string label);

  virtual ~ConsoleGameEngine();

  virtual void Draw(int x, int y, short c , short col );

  void print_str(std::string, int x, int y);

  void DisplayFrame();

  int m_nProgramStatus;


  protected:
    std::string   m_sAppName;
    WINDOW *m_pWindow = nullptr;
    bool m_bBorder = true;
    CHAR_INFO *m_pBufferScreen = nullptr;
    int m_nScreenWidth;
    int m_nScreenHeight;
};
