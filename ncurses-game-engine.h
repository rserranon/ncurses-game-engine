
class ConsoleGameEngine
{
public:
  ConsoleGameEngine();

  virtual void Draw(int x, int y, short c , short col );

  protected:
  int m_nScreenWidth;
  int m_nScreenHeight;
};
