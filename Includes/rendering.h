#ifndef __RENDERING_H
#define __RENDERING_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <hal/video.h>
#include "player.h"
#include "ball.h"

class render {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;

  TTF_Font* font;
  SDL_Rect p1Score, p2Score;
  SDL_Color scoreColor;

public:
  render();
  ~render();
  
  SDL_Renderer* getRenderer();
  SDL_Window* getWindow();

  void clear();

  void updatePlayerScore(player& p);

  void drawField(SDL_Rect const& playingField);
  void drawScores(player& p1, player& p2);
  void drawPlayer(player const& p);
  void drawBall(ball const& b);

  void flip();
};

#endif
