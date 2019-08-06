#include "player.h"

double min(double lhs, double rhs) {
  if (rhs < lhs) {
    return rhs;
  }
  return lhs;
}

double max(double lhs, double rhs) {
  if (lhs < rhs) {
    return rhs;
  }
  return lhs;
}

player::player(int xPos, SDL_GameController* i) {
  x = xPos;
  brick.x = x;
  y = 240.0;

  brick.h = 64;
  brick.w = 8;
  
  input = i;
}

player::~player() {
  if (input != nullptr) {
    SDL_GameControllerClose(input);
  }
}

SDL_GameController* player::getController() {
  return input;
}

SDL_Rect const& player::getRect() const {
  return brick;
}

void player::update() {
  SDL_GameControllerUpdate();
  int q = SDL_GameControllerGetAxis(input, SDL_CONTROLLER_AXIS_LEFTY);
  if ((q < 0) && (y < (480.0 - brick.h))) {
    y = min((480.0 - brick.h), y + ((q/-32768.0) * 2.0));
  } else if ((q > 0) && (y > 0.0)) {
    y = max(0, y - ((q/32767.0) * 2.0));
  }
  brick.y = static_cast<int>(y);
}

void player::updatePosition() {
//  brick.y = y;
}
