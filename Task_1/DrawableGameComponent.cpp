#include "DrawableGameComponent.h"


DrawableGameComponent::DrawableGameComponent(int x, int y) : GameComponent(), x(x), y(y) {
  // Why do we receive the x and y if we have to set them to 0?
  // What to we initialise the constants to?
  x = 0;
  y = 0;
  direction = Right;
  srandom(time(nullptr));
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
    newDirection = (Direction) ((random() % 4));
  } while (newDirection == direction);
  direction = newDirection;
}

void DrawableGameComponent::Update(const tm *eventTime) {
  GameComponent::Update(eventTime);

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