#include "player.h"

#include "smallMath.h"

const static int DEADZONE = 4096;

Player::Player(int xPos, SDL_GameController* i, int axis)
  : x(xPos), axis(axis), input(i)
{
  brick.x = x;
  y = 240.0;

  brick.h = 64;
  brick.w = 8;
  
  score = 0;
  scoreTex = nullptr;
  speed = 0.0;
}

Player::~Player() {
  if (input != nullptr) {
    SDL_GameControllerClose(input);
  }
}

SDL_GameController* Player::getController() {
  return input;
}

SDL_Rect const& Player::getRect() const {
  return brick;
}

void Player::update(SDL_Rect const& playingField) {
  SDL_GameControllerUpdate();
  double pfyMin = playingField.y;
  double pfyMax = playingField.y + playingField.h;
  int q = SDL_GameControllerGetAxis(input, static_cast<SDL_GameControllerAxis>(axis));
  if ((q < -DEADZONE) && (y < (pfyMax - brick.h))) {
    speed = q / 4096.0;
    y = min((pfyMax - brick.h), y - speed);
  } else if ((q > DEADZONE) && (y > pfyMin)) {
    speed = q / 4096.0;
    y = max(pfyMin, y - speed);
  } else {
    speed = 0.0;
  }
  brick.y = static_cast<int>(y);
}

void Player::updatePosition() {
//  brick.y = y;
}

double Player::getSpeed() const {
  return speed;
}

void Player::givePoint() {
  ++score;
}

void Player::takePoint() {
  --score;
}

void Player::zeroPoints() {
  score = 0;
}

int Player::getScore() {
  return score;
}

SDL_Texture* Player::getScoreTex() {
  return scoreTex;
}

void Player::setScoreTex(SDL_Texture* tex) {
  scoreTex = tex;
}
