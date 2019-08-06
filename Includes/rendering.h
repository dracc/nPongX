#ifndef __RENDERING_H
#define __RENDERING_H

#include <SDL.h>
#include <hal/video.h>
#include "player.h"

class render {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;

public:
  render();
  ~render();
  
  SDL_Renderer* getRenderer();
  SDL_Window* getWindow();

  void clear();

  void drawPlayer(player const& p);

  void flip();
};

#endif
