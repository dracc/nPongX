#ifndef __PLAYER_H
#define __PLAYER_H

#include <SDL.h>

class player {
private:
  SDL_Rect brick;
  double x, y;
  int axis;
  SDL_GameController* input;
  int score;
  SDL_Texture* scoreTex;
  
public:
  player(int, SDL_GameController*, int);
  ~player();

  SDL_GameController* getController();

  SDL_Rect const& getRect() const;

  void update(SDL_Rect const& playingField);
  void updatePosition();

  void givePoint();
  void takePoint();
  void zeroPoints();
  int getScore();
  SDL_Texture* getScoreTex();
  void setScoreTex(SDL_Texture*);
};

#endif
