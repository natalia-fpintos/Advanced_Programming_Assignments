#include "GameComponent.h"
#include "string"

class DrawableGameComponent : public GameComponent {
private:
  int x;
  int y;
  void Draw();
  void ChangeDirection();
public:
  enum Direction {
    Left, Right, Up, Down
  };
  Direction direction;
  DrawableGameComponent(int x, int y);
  void Update(const tm *eventTime);
  int const SCREEN_HEIGHT = 20;
  const int SCREEN_WIDTH = 80;
};
