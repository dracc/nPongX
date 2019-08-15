#ifndef __BALL_H
#define __BALL_H

#include <SDL.h>
#include "player.h"

class Ball {
private:
  double x, y;
  SDL_Rect rect;
  double direction;
  double spin;

  double hitAngle(SDL_Rect const& p);
public:
  Ball(int newX, int newY);
  Ball(SDL_Rect const& playingField);
//  ~Ball() = default;

  const SDL_Rect& getRect() const;
  
  double getXDir() const;
  double getYDir() const;

  void reset(SDL_Rect const& playingField);
  void setPos(int newX, int newY);
  void setDirection(double X);

  void update(Player& p1, Player& p2, SDL_Rect const& playingField);
};

#endif
