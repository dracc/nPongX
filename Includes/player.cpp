#include "player.h"

#include "smallMath.h"

player::player(int xPos, SDL_GameController* i, int a) {
  x = xPos;
  brick.x = x;
  y = 240.0;

  brick.h = 64;
  brick.w = 8;
  
  input = i;
  axis = a;

  score = 0;
  scoreTex = nullptr;
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

void player::update(SDL_Rect const& playingField) {
  SDL_GameControllerUpdate();
  double pfyMin = playingField.y;
  double pfyMax = playingField.y + playingField.h;
  int q = SDL_GameControllerGetAxis(input, static_cast<SDL_GameControllerAxis>(axis));
  if ((q < 0) && (y < (pfyMax - brick.h))) {
    y = min((pfyMax - brick.h), y + ((q/-32768.0) * 2.0));
  } else if ((q > 0) && (y > pfyMin)) {
    y = max(pfyMin, y - ((q/32767.0) * 2.0));
  }
  brick.y = static_cast<int>(y);
}

void player::updatePosition() {
//  brick.y = y;
}

void player::givePoint() {
  ++score;
}

void player::takePoint() {
  --score;
}

void player::zeroPoints() {
  score = 0;
}

int player::getScore() {
  return score;
}

SDL_Texture* player::getScoreTex() {
  return scoreTex;
}

void player::setScoreTex(SDL_Texture* tex) {
  scoreTex = tex;
}
