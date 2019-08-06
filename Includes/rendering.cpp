#include "rendering.h"

extern "C" {
const extern int SCREEN_WIDTH;
const extern int SCREEN_HEIGHT;
}

render::render() {
  window = SDL_CreateWindow("nPongX",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, 0);
}

render::~render() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

SDL_Renderer* render::getRenderer() {
  return renderer;
}

SDL_Window* render::getWindow() {
  return window;
}

void render::clear() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
  SDL_RenderClear(renderer);
}

void render::drawPlayer(player const& p) {
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &p.getRect());
}

void render::flip() {
  SDL_RenderPresent(renderer);
//  XVideoWaitForVBlank();
}
