#ifndef __BALL_H
#define __BALL_H

#include <SDL.h>
#include "player.h"

class ball {
private:
  double x, y;
  SDL_Rect rect;
  double xDir, yDir;
public:
  ball(int newX, int newY);
  ball(SDL_Rect const& playingField);
//  ~ball() = default;

  const SDL_Rect& getRect() const;
  
  double getXDir() const;
  double getYDir() const;

  void reset(SDL_Rect const& playingField);
  void setPos(int newX, int newY);
  void setXDir(double X);
  void setYDir(double Y);

  void update(player& p1, player& p2, SDL_Rect const& playingField);
};

#endif
