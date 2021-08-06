#include "DrawableGameComponent.h"


DrawableGameComponent::DrawableGameComponent(int x, int y) : GameComponent(), x(x), y(y) {
  direction = Right;
}

void DrawableGameComponent::Draw () {
  string directionName;
  switch (direction) {
    case Left:
      directionName = "Left";
      break;
    case Right:
      directionName = "Right";
      break;
    case Up:
      directionName = "Up";
      break;
    case Down:
      directionName = "Down";
      break;
  }
  cout << "Direction: " << directionName << ".\t" << "x: " << x << ", y: " << y << endl;
}

void DrawableGameComponent::ChangeDirection() {
  Direction newDirection;
  do {
    // Pick new random direction different to current
    newDirection = (Direction) ((random() % 4));
  } while (newDirection == direction);
  direction = newDirection;
}

void DrawableGameComponent::Update(const tm *eventTime) {
  GameComponent::Update(eventTime);

  // Update x/y values for current direction
  switch (direction) {
    case Left:
      if (x > 0) {
        x -= 1;
      }
      break;
    case Right:
      if (x < SCREEN_WIDTH) {
        x += 1;
      }
      break;
    case Up:
      if (y > 0) {
        y -= 1;
      }
      break;
    case Down:
      if (y < SCREEN_HEIGHT) {
        y += 1;
      }
      break;
  }

  this->Draw();
  this->ChangeDirection();
}