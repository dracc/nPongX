#ifndef __PLAYER_H
#define __PLAYER_H

#include <SDL.h>

class player {
private:
  SDL_Rect brick;
  double x, y;
  int axis;
  SDL_GameController* input;
public:
  player(int, SDL_GameController*, int);
  ~player();

  SDL_GameController* getController();

  SDL_Rect const& getRect() const;

  void update();
  void updatePosition();
};

#endif
