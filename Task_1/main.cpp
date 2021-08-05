#include <iostream>
#include "DrawableGameComponent.h"
#include "Game.h"

using namespace std;

void Initialisation() {
  cout << "===================" << endl;
  cout << " Initialising game" << endl;
  cout << "===================" << endl;
}

void Termination() {
  cout << "==================" << endl;
  cout << " Terminating game" << endl;
  cout << "==================" << endl;
}

int main() {
  // Init and setup
  Game *game = new Game(2);
  game->SetInitialise(Initialisation);
  game->SetTerminate(Termination);

  // Add game components
  game->Add(new GameComponent());
  game->Add(new DrawableGameComponent(0, 0));

  // Run game
  game->Run();

  return 0;
}
