#ifndef __PLAYER_H
#define __PLAYER_H

#include <SDL.h>

class player {
private:
  SDL_Rect brick;
  double x, y;
  SDL_GameController* input;
public:
  player(int, SDL_GameController*);
  ~player();

  SDL_GameController* getController();

  const SDL_Rect& getRect();

  void update();
  void updatePosition();
};

#endif
