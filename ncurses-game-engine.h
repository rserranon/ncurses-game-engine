#include <mutex>
#include <ncurses.h>
#include <string>
#include <thread>
#include <atomic>
#include <condition_variable>

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

  void Start();

  int m_nProgramStatus;


protected:
    std::string   m_sAppName;
    WINDOW *m_pWindow = nullptr;
    bool m_bBorder = true;
    CHAR_INFO *m_pBufferScreen = nullptr;
    int   m_nScreenWidth;
    int   m_nScreenHeight;
    int   m_nKeyPressed;

    static std::atomic<bool> m_bAtomicActive;
    static std::condition_variable m_cvGameFinished;
	  static std::mutex m_muxGame;

    virtual bool OnUserUpdate() = 0;

private:
    void GameThread();
};

