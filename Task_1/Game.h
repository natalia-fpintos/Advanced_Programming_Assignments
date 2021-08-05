#include "thread"
#include "GameComponent.h"

class Game {
private:
  typedef void (*FP)();
  int componentCount;
  GameComponent **components;
  FP initialise;
  FP terminate;
  const int TICKS_1000MS = 1000;
public:
  Game(int maxComponents);
  void Add(GameComponent *gameComponent);
  void Run();
  void SetInitialise(FP init);
  void SetTerminate(FP term);
};
