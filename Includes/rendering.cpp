#include "rendering.h"

#include <stdio.h>

extern "C" {
const extern int SCREEN_WIDTH;
const extern int SCREEN_HEIGHT;
}

render::render() {
  window = SDL_CreateWindow("nPongX",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, 0);

  font = TTF_OpenFont("vegur.ttf", 16);
  p1Score = SDL_Rect{280, 40, 20, 20};
  p2Score = SDL_Rect{320, 40, 20, 20};
  scoreColor = SDL_Color{0xFF, 0xFF, 0xFF, 0xFF};
}

render::~render() {
  TTF_CloseFont(font);
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

void render::updatePlayerScore(player& p) {
  if (p.getScoreTex() != nullptr) {
    SDL_DestroyTexture(p.getScoreTex());
  }
  char sc[2];
  sprintf(sc, "%02d", p.getScore());
  SDL_Surface* surf = TTF_RenderText_Solid(font, sc, scoreColor);
  if (!surf) {
    //
  }
  p.setScoreTex(SDL_CreateTextureFromSurface(renderer, surf));
  SDL_FreeSurface(surf);
}

void render::drawField(SDL_Rect const& playingField) {
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderDrawRect(renderer, &playingField);

  SDL_Rect midline{(playingField.w / 2)-1, playingField.y, 2, 15};
  for (; midline.y + midline.h < playingField.y + playingField.h;
       midline.y += 2 * midline.h) {
    SDL_RenderFillRect(renderer, &midline);
  }
}

void render::drawScores(player& p1, player& p2) {
  SDL_RenderCopy(renderer, p1.getScoreTex(), nullptr, &p1Score);
  SDL_RenderCopy(renderer, p2.getScoreTex(), nullptr, &p2Score);
}

void render::drawPlayer(player const& p) {
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &p.getRect());
}

void render::drawBall(ball const& b) {
  SDL_SetRenderDrawColor(renderer, 0xFF, 0x40, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &b.getRect());
}

void render::flip() {
  SDL_RenderPresent(renderer);
//  XVideoWaitForVBlank();
}
