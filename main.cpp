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

  SDL_Rect playingField{10, 20, 620, 440};
  player p1(20, p1gc, SDL_CONTROLLER_AXIS_LEFTY);
  player p2(612, p1gc, SDL_CONTROLLER_AXIS_RIGHTY);

  int p1Score = 3;
  int p2Score = 3;

  ball b(playingField);
  
  while (1) {
    Renderer.clear();
    p1.update(playingField);
    p2.update(playingField);
    b.update(p1, p2, playingField);
    if (p1Score != p1.getScore()) {
      Renderer.updatePlayerScore(p1);
      p1Score = p1.getScore();
    }
    if (p2Score != p2.getScore()) {
      Renderer.updatePlayerScore(p2);
      p2Score = p2.getScore();
    }
    Renderer.drawField(playingField);
    Renderer.drawScores(p1, p2);
    Renderer.drawPlayer(p1);
    Renderer.drawPlayer(p2);
    Renderer.drawBall(b);
    Renderer.flip();
  }

  SDL_GameControllerClose(p1gc);
  killAll();
  return 0;
}
