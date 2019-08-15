#ifndef __RENDERING_H
#define __RENDERING_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <hal/video.h>
#include "player.h"
#include "ball.h"

class Renderer {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;

  TTF_Font* font;
  SDL_Rect p1Score, p2Score;
  SDL_Color scoreColor;

public:
  Renderer();
  ~Renderer();
  
  SDL_Renderer* getRenderer();
  SDL_Window* getWindow();

  void clear();

  void updatePlayerScore(Player& p);

  void drawField(SDL_Rect const& playingField);
  void drawScores(Player& p1, Player& p2);
  void drawPlayer(Player const& p);
  void drawBall(Ball const& b);

  void flip();
};

#endif
