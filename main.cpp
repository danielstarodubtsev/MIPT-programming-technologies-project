#include "game.h"

Game* Game ::singl = nullptr;

int main() {
  Game* game = Game ::GetInstance();
  game->start();
}
