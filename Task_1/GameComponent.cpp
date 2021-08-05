#include "GameComponent.h"


int GameComponent::instances = 0;

GameComponent::GameComponent() {
    GameComponent::instances++;
    id = instances;
}

void GameComponent::Update(const tm *timeData) {
    cout << "Game Object id: " << id << " - ";
    cout << "Updated: " << timeData->tm_hour << ":" << timeData->tm_min << ":" << timeData->tm_sec << endl;
}