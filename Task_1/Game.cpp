#include "Game.h"

Game::Game(int maxComponents) {
  components = new GameComponent*[maxComponents];
  componentCount = 0;
  srandom(time(nullptr));
}

void Game::Add(GameComponent *gameComponent) {
  components[componentCount] = gameComponent;
  componentCount++;
}

void Game::SetInitialise(FP init) {
  initialise = init;
}

void Game::SetTerminate(FP term) {
  terminate = term;
}

void Game::Run() {
  initialise();

  int numCalls = 5;
  for(int i = 0; i < numCalls; i++) {
    for(int j = 0; j < componentCount; j++) {
      // Get current time
      time_t timeInSeconds;
      time(&timeInSeconds);
      const struct tm *timeData = localtime(&timeInSeconds);

      // Update component
      components[j]->Update(timeData);
    }
    cout << "------------------------------------" << endl;
    // Sleep for 1s
    this_thread::sleep_for(chrono::milliseconds(TICKS_1000MS));
  }

  terminate();
}