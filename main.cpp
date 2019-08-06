#include <SDL.h>
#include <SDL_ttf.h>
#include <pbkit/pbkit.h>
#include <hal/input.h>
#include <hal/video.h>
#include <hal/xbox.h>

#include "init.h"
#include "player.h"
#include "rendering.h"

int main() {
  doInit();

  render Renderer;
  
  // Do the shit
  SDL_GameController* p1gc = SDL_GameControllerOpen(0);
  if (p1gc == nullptr) {
    return 0;
  }
  SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");

  player p1(20, p1gc);
  
  while (1) {
    Renderer.clear();
    p1.update();
    Renderer.drawPlayer(p1);
    Renderer.flip();
  }

  SDL_GameControllerClose(p1gc);
  killAll();
  return 0;
}
