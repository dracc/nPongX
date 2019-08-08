#include "ball.h"

#include "smallMath.h"
#include <math.h>

ball::ball(int newX, int newY) {
  x = static_cast<double>(newX);
  y = static_cast<double>(newY);
  rect.h = 3;
  rect.w = 3;
  rect.x = static_cast<int>(x);
  rect.y = static_cast<int>(y);
  xDir = 1.0;
  yDir = 0.0;
}

ball::ball(SDL_Rect const& playingField) :
  ball((playingField.x + playingField.w / 2),
       (playingField.y + playingField.h / 2)) {}

const SDL_Rect& ball::getRect() const {
  return rect;
}

double ball::getXDir() const {
  return xDir;
}

double ball::getYDir() const {
  return yDir;
}

void ball::reset(SDL_Rect const& playingField) {
  x = playingField.x + playingField.w / 2.0;
  rect.x = static_cast<int>(x);
  y = playingField.y + playingField.h / 2.0;
  rect.y = static_cast<int>(y);
  xDir = -xDir;
}

void ball::setPos(int newX, int newY) {
  x = static_cast<double>(newX);
  y = static_cast<double>(newY);
}

void ball::setXDir(double X) {
  xDir = X;
}

void ball::setYDir(double Y) {
  yDir = Y;
}

void ball::update(player& p1, player& p2, SDL_Rect const& playingField) {
  const SDL_Rect p1r = p1.getRect();
  const SDL_Rect p2r = p2.getRect();
  x += xDir;
  rect.x = static_cast<int>(x);

  if (y <= playingField.y
      && yDir < 0.0) {
    yDir = -yDir;
  } else if (y >= playingField.y + playingField.h
             && yDir > 0.0) {
    yDir = -yDir;
  }
  y += yDir;
  rect.y = static_cast<int>(y);
  
  if (xDir < 0.0) {
    if (x <= playingField.x) {
      p2.givePoint();
      reset(playingField);
    } else if (p1r.y + p1r.h > rect.y
               && p1r.y < rect.y
               && rect.x <= p1r.x + p1r.w
               && rect.x >= p1r.x) {
      // FIXME: Set speed and Y direction depending on where the paddle was hit.
      int yy = (rect.y - p1r.y) - (p1r.h/2);
      yDir = 2.0 * yy / static_cast<double>(p1r.h);
      xDir = -xDir;
    }
  } else {
    if (x >= playingField.x + playingField.w) {
      p1.givePoint();
      reset(playingField);
    } else if (p2r.y + p2r.h > rect.y
               && p2r.y < rect.y
               && rect.x + rect.w >= p2r.x
               && rect.x + rect.w <= p2r.x + p2r.w) {
      // Fixme: Set speed and Y direction depending on where the paddle was hit.
      yDir = (((rect.y - p2r.y) - (p2r.h/2)) * 2) / static_cast<double>(p2r.h);
      xDir = -xDir;
    }
  }
}
