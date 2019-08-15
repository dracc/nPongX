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

  Renderer renderer;
  
  // Do the shit
  SDL_GameController* p1gc = SDL_GameControllerOpen(0);
  if (p1gc == nullptr) {
    return 0;
  }
  SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");

  SDL_Rect playingField{10, 20, 620, 440};
  Player p1(20, p1gc, SDL_CONTROLLER_AXIS_LEFTY);
  Player p2(612, p1gc, SDL_CONTROLLER_AXIS_RIGHTY);

  int p1Score = 3;
  int p2Score = 3;

  Ball b(playingField);
  
  while (1) {
    renderer.clear();
    p1.update(playingField);
    p2.update(playingField);
    b.update(p1, p2, playingField);
    if (p1Score != p1.getScore()) {
      renderer.updatePlayerScore(p1);
      p1Score = p1.getScore();
    }
    if (p2Score != p2.getScore()) {
      renderer.updatePlayerScore(p2);
      p2Score = p2.getScore();
    }
    renderer.drawField(playingField);
    renderer.drawScores(p1, p2);
    renderer.drawPlayer(p1);
    renderer.drawPlayer(p2);
    renderer.drawBall(b);
    renderer.flip();
  }

  SDL_GameControllerClose(p1gc);
  killAll();
  return 0;
}
