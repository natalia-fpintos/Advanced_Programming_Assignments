#pragma once

#include <ctime>
#include <iostream>

using namespace std;


class GameComponent {
private:
    int id;
    static int instances;
public:
    GameComponent();
    void Update(const tm *timeData);
};
