#include <iostream>
#include <unistd.h>
#include "DrawableGameComponent.h"

using namespace std;

int main() {
  DrawableGameComponent drawableGameComponent(0, 0);
  time_t timeSeconds;
  struct tm timeinfo;
  time(&timeSeconds);
  localtime_r(&timeSeconds, &timeinfo);
  drawableGameComponent.Update(&timeinfo);

  sleep(3);
  DrawableGameComponent drawableGameComponent2(0, 0);
  time_t timeSeconds2;
  struct tm timeinfo2;
  time(&timeSeconds2);
  localtime_r(&timeSeconds2, &timeinfo2);
  drawableGameComponent2.Update(&timeinfo2);

  return 0;
}
