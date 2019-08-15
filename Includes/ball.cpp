#include "ball.h"

#include "smallMath.h"

#define _USE_MATH_DEFINES 1
#include <math.h>

const static double tau = M_PI * 2.0;
const static int ballSize = 4;
const static double ballSpeed = 4.0;
const static double rad = M_PI / 180.0;

Ball::Ball(int newX, int newY) {
  x = static_cast<double>(newX);
  y = static_cast<double>(newY);
  rect.h = ballSize;
  rect.w = ballSize;
  rect.x = static_cast<int>(x);
  rect.y = static_cast<int>(y);
  direction = 45.0 * rad;
  spin = 0.0;
}

Ball::Ball(SDL_Rect const& playingField) :
  Ball((playingField.x + playingField.w / 2),
       (playingField.y + playingField.h / 2)) {}

const SDL_Rect& Ball::getRect() const {
  return rect;
}

double Ball::getXDir() const {
  return cos(direction) * ballSpeed;
}

double Ball::getYDir() const {
  return sin(direction) * ballSpeed;
}

void Ball::reset(SDL_Rect const& playingField) {
  x = playingField.x + playingField.w / 2.0;
  rect.x = static_cast<int>(x);
  y = playingField.y + playingField.h / 2.0;
  rect.y = static_cast<int>(y);
  double tmpDir = direction + M_PI;
  direction = tmpDir > tau ? tmpDir - tau : tmpDir;
}

void Ball::setPos(int newX, int newY) {
  x = static_cast<double>(newX);
  y = static_cast<double>(newY);
}

void Ball::setDirection(double X) {
  direction = X;
}

double Ball::hitAngle(SDL_Rect const& p) {
  return M_PI * ((rect.y - p.y) - (p.h >> 1)) / static_cast<double>(p.h);
}

void Ball::update(Player& p1, Player& p2, SDL_Rect const& playingField) {
  const SDL_Rect p1r = p1.getRect();
  const SDL_Rect p2r = p2.getRect();
  x += getXDir();
  rect.x = static_cast<int>(x);
  direction += spin;
  if (y <= playingField.y && direction > M_PI) {
    direction = tau - direction;
  } else if (y >= playingField.y + playingField.h && direction < M_PI) {
    direction = tau - direction;
  }
  y += getYDir();
  rect.y = static_cast<int>(y);
  
  if (direction <= (M_PI + M_PI_2) && direction > M_PI_2) {
    if (x <= playingField.x) {
      p2.givePoint();
      reset(playingField);
    } else if (p1r.y + p1r.h > rect.y
               && p1r.y < rect.y
               && rect.x <= p1r.x + p1r.w
               && rect.x >= p1r.x) {
      double tmpDir = tau + hitAngle(p1r);
      direction = tmpDir > tau ? tmpDir - tau : tmpDir;
      double pSpeed = p1.getSpeed();
      if (pSpeed > 4.0 || pSpeed < -4.0) {
        spin = ((p1.getSpeed() / 16.0) * M_PI_4) * rad;
      } else {
        spin = 0.0;
      }
    }
  } else {
    if (x >= playingField.x + playingField.w) {
      p1.givePoint();
      reset(playingField);
    } else if (p2r.y + p2r.h > rect.y
               && p2r.y < rect.y
               && rect.x + rect.w >= p2r.x
               && rect.x + rect.w <= p2r.x + p2r.w) {
      direction = M_PI - hitAngle(p2r);
      double pSpeed = p2.getSpeed();
      if (pSpeed > 4.0 || pSpeed < -4.0) {
        spin = ((p2.getSpeed() / 16.0) * M_PI_4) * rad;
      } else {
        spin = 0.0;
      }
    }
  }
}
