#ifndef __PLAYER_H
#define __PLAYER_H

#include <SDL.h>

class Player {
private:
  SDL_Rect brick;
  double x, y;
  int axis;
  SDL_GameController* input;
  int score;
  SDL_Texture* scoreTex;
  double speed;
  
public:
  Player(int xPos, SDL_GameController* i, int axis);
  ~Player();

  SDL_GameController* getController();

  SDL_Rect const& getRect() const;

  void update(SDL_Rect const& playingField);
  void updatePosition();
  double getSpeed() const;

  void givePoint();
  void takePoint();
  void zeroPoints();
  int getScore();
  SDL_Texture* getScoreTex();
  void setScoreTex(SDL_Texture*);
};

#endif
