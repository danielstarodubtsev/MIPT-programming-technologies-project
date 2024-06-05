import os
import pygame
from time import sleep

SCREEN_SIZE = 600
BOTTOM_SIZE = 50

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
GREY = (50, 50, 50)

def remove_files():
  files = [
    "../movement.txt",
    "../map_state.txt",
    "../player_health.txt",
    "../fight_action.txt",
    "../score.txt",
  ]

  for file in files:
    try:
      os.remove(file)
    except FileNotFoundError:
      pass

def main():
  if not os.path.exists("../high_score.txt"):
    with open("../high_score.txt", "w") as file:
      file.write(0)

  pygame.init()
  pygame.font.init()

  player_sprite = pygame.image.load("../assets/player.png")
  monster_sprite = pygame.image.load("../assets/monster.png")
  heal_sprite = pygame.image.load("../assets/heal.png")
  sword_sprite = pygame.image.load("../assets/sword.jpg")
  monster_sprite = pygame.transform.scale(monster_sprite, (38, 38))
  player_sprite = pygame.transform.scale(player_sprite, (38, 38))
  heal_sprite = pygame.transform.scale(heal_sprite, (38, 38))
  sword_sprite = pygame.transform.scale(sword_sprite, (26, 26))

  screen = pygame.display.set_mode((SCREEN_SIZE, SCREEN_SIZE + BOTTOM_SIZE))
  sleep(0.5)

  while True:
    for event in pygame.event.get():
      if event.type == pygame.QUIT:
        pygame.quit()
        remove_files()
        return 0

      elif event.type == pygame.KEYDOWN:
        if event.key in {pygame.K_s, pygame.K_DOWN}:
          move = "s"
        elif event.key in {pygame.K_w, pygame.K_UP}:
          move = "w"
        elif event.key in {pygame.K_d, pygame.K_RIGHT}:
          move = "d"
        elif event.key in {pygame.K_a, pygame.K_LEFT}:
          move = "a"
        else:
          continue

        with open("../movement.txt", "w") as file:
          file.write(move)

      elif event.type == pygame.MOUSEBUTTONDOWN and event.button == pygame.BUTTON_LEFT:
        if SCREEN_SIZE * 0.42 <= event.pos[0] <= SCREEN_SIZE * 0.58 and \
           SCREEN_SIZE + BOTTOM_SIZE * 0.15 <= event.pos[1] <= SCREEN_SIZE + BOTTOM_SIZE * 0.85:
          with open("../fight_action.txt", "w") as file:
            file.write("a")

    with open("../map_state.txt") as map_file:
      grid = [line.strip() for line in map_file.readlines() if line.strip()]

    with open("../player_health.txt") as health_file:
      health_str = health_file.readlines()

    if grid:
      MAP_SIZE = len(grid)
      CELL_SIZE = SCREEN_SIZE / MAP_SIZE

      pygame.draw.rect(screen, BLACK, (0, 0, SCREEN_SIZE, SCREEN_SIZE))

      pygame.draw.rect(screen, WHITE, (0, 0, 1, SCREEN_SIZE))
      for i in range(MAP_SIZE + 1):
        pygame.draw.rect(screen, WHITE, (CELL_SIZE * i - 1, 0, 1, SCREEN_SIZE))
        pygame.draw.rect(screen, WHITE, (0, CELL_SIZE * i, SCREEN_SIZE, 1))

      for x in range(MAP_SIZE):
        for y in range(MAP_SIZE):
          if grid[y][x] == "w":
            pygame.draw.rect(screen, WHITE, (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE))
          elif grid[y][x] == "P":
            screen.blit(player_sprite, (x * CELL_SIZE + 1, y * CELL_SIZE + 2))
          elif grid[y][x] == "o":
            screen.blit(heal_sprite, (x * CELL_SIZE + 1, y * CELL_SIZE + 2))
          elif grid[y][x] == "X":
            screen.blit(monster_sprite, (x * CELL_SIZE + 1, y * CELL_SIZE + 2))

    if health_str:
      health, max_health, attack, in_battle = list(map(int, health_str[0].split()))
      if health <= 0:
        sleep(0.01)
        with open("../score.txt") as file:
          score = int(file.read())
        with open("../high_score.txt") as file:
          high_score = int(file.read())
        screen.fill(BLACK)
        font = pygame.font.Font(None, 90)
        text1 = font.render("YOU DIED", True, RED)
        text2 = font.render(f"KILLS: {score}", True, RED)
        text3 = font.render(f"RECORD KILLS: {high_score}", True, RED)
        screen.blit(text1, (SCREEN_SIZE * 0.25, SCREEN_SIZE * 0.4))
        screen.blit(text2, (SCREEN_SIZE * 0.28, SCREEN_SIZE * 0.54))
        screen.blit(text3, (SCREEN_SIZE * 0.06, SCREEN_SIZE * 0.68))
        pygame.display.update()
        remove_files()
        sleep(5)
        pygame.quit()
        return 0

      pygame.draw.rect(screen, BLACK, (0, SCREEN_SIZE, SCREEN_SIZE, BOTTOM_SIZE))
      pygame.draw.rect(screen, RED, (SCREEN_SIZE / 10, SCREEN_SIZE + BOTTOM_SIZE * 0.55, (SCREEN_SIZE / 5) * health / max_health, BOTTOM_SIZE * 0.4))
      pygame.draw.rect(screen, WHITE, (SCREEN_SIZE / 10, SCREEN_SIZE + BOTTOM_SIZE * 0.55, SCREEN_SIZE / 5, BOTTOM_SIZE * 0.4), 2)

      font = pygame.font.Font(None, 30)
      text = font.render(f"{health}/{max_health}", True, WHITE)
      screen.blit(text, (SCREEN_SIZE / 7, SCREEN_SIZE + BOTTOM_SIZE * 0.55 + 1))
      screen.blit(player_sprite, (SCREEN_SIZE / 55, SCREEN_SIZE + BOTTOM_SIZE * 0.1))
      screen.blit(sword_sprite, (SCREEN_SIZE * 0.1, SCREEN_SIZE + 1))
      text = font.render(f"{attack}", True, WHITE)
      screen.blit(text, (SCREEN_SIZE / 7, SCREEN_SIZE + BOTTOM_SIZE * 0.1))

      if in_battle:
        monster_hp, monster_max_hp, monster_attack = list(map(int, health_str[1].split()))

        pygame.draw.rect(screen, GREY, (SCREEN_SIZE * 0.42, SCREEN_SIZE + BOTTOM_SIZE * 0.15, SCREEN_SIZE * 0.16, BOTTOM_SIZE * 0.7))
        pygame.draw.rect(screen, WHITE, (SCREEN_SIZE * 0.42, SCREEN_SIZE + BOTTOM_SIZE * 0.15, SCREEN_SIZE * 0.16, BOTTOM_SIZE * 0.7), 2)
        text = font.render("Attack!", True, WHITE)
        screen.blit(text, (SCREEN_SIZE * 0.44, SCREEN_SIZE + BOTTOM_SIZE * 0.3))

        pygame.draw.rect(screen, RED, (SCREEN_SIZE * 0.7, SCREEN_SIZE + BOTTOM_SIZE * 0.55, (SCREEN_SIZE / 5) * monster_hp / monster_max_hp, BOTTOM_SIZE * 0.4))
        pygame.draw.rect(screen, WHITE, (SCREEN_SIZE * 0.7, SCREEN_SIZE + BOTTOM_SIZE * 0.55, SCREEN_SIZE / 5, BOTTOM_SIZE * 0.4), 2)
        text = font.render(f"{monster_hp}/{monster_max_hp}", True, WHITE)
        screen.blit(text, (SCREEN_SIZE * 0.74, SCREEN_SIZE + BOTTOM_SIZE * 0.55 + 1))
        screen.blit(monster_sprite, (SCREEN_SIZE * 0.92, SCREEN_SIZE + BOTTOM_SIZE * 0.1))
        screen.blit(pygame.transform.flip(sword_sprite, True, False), (SCREEN_SIZE * 0.86, SCREEN_SIZE + 1))
        text = font.render(f"{monster_attack}", True, WHITE)
        screen.blit(text, (SCREEN_SIZE * 0.83, SCREEN_SIZE + BOTTOM_SIZE * 0.1))

    pygame.display.update()
    pygame.time.delay(50)

if __name__ == "__main__":
  main()