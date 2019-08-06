#include "init.h"

void doInit() {
  XVideoSetMode(640, 480, 32, REFRESH_DEFAULT);
  pb_init();
  pb_show_debug_screen();

  SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER);
  TTF_Init();
}

void killAll() {
  TTF_Quit();
  SDL_Quit();
  pb_kill();
}
