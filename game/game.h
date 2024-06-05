#include <fstream>

#pragma once

#include "map.h"
#include "player.h"

struct Game {
  Player player;
  static Game* singl;
  const int kHeightMin = 15;
  const int kHeightMax = 15;
  const int kWeightMin = 15;
  const int kWeightMax = 15;
  static Game* GetInstance() {
    if (singl == nullptr) {
      singl = new Game();
      return singl;
    } else {
      return singl;
    }
  }
private:
  Game() = default;
public:
  Game(const Game&) = delete;
  int random_from(int a, int b) {
    return std::abs(static_cast<int>(rnd())) % (b - a + 1) + a;
  }
  void start() {
    int height = random_from(kHeightMin, kHeightMax);
    int weight = random_from(kWeightMin, kWeightMax);
    Map map(player, height, weight);

    std::string player_action;

    int kills = 0;

    while (!player.IsDead()) {
      if (map.IsClear()) {
        player.ToCoords(1, 1);
        player.SetMaxHealth(player.GetMaxHealth() * 1.2);
        player.HealFull();
        player.SetDamage(player.GetDamage() * 1.2);
        int height = random_from(kHeightMin, kHeightMax);
        int weight = random_from(kWeightMin, kWeightMax);
        Map other(player, height, weight);
        map = other;
      }
      if (map.IsMonster(player.GetX(), player.GetY())) {
        bool is_scary = map.IsScaryMonster(player.GetX(), player.GetY());
        int result = map.Fight(player.GetX(), player.GetY(), player);
        if (result == 0) {
          break;
        } else if (result == 1 && is_scary) {
          ++kills;
        }
      }

      map.Print(player.GetX(), player.GetY());

      // save player health
      std::ofstream health_file;
      health_file.open("../player_health.txt", std::ofstream::out | std::ofstream::trunc);
      health_file << player.GetHealth() << " " <<  player.GetMaxHealth() << " " << player.GetDamage() << " 0";
      health_file.close();

      player_action = "";

      std::ifstream move_file;
      move_file.open("../movement.txt");
      move_file >> player_action;
      move_file.close();
  
      if (player_action == "") {
        continue;
      }

      std::ofstream move_file_deleter;
      move_file_deleter.open("../movement.txt", std::ofstream::out | std::ofstream::trunc);
      move_file_deleter.close();

      if (player_action == "w" || player_action == "W") {
        if (map.IsFree(player.GetX() - 1, player.GetY())) {
          player.MoveUp();
          map.MoveMonsters(player);
          continue;
        }
      }
      else if (player_action == "s" || player_action == "S") {
        if (map.IsFree(player.GetX() + 1, player.GetY())) {
          player.MoveDown();
          map.MoveMonsters(player);
          continue;
        }
      }
      else if (player_action == "a" || player_action == "A") {
        if (map.IsFree(player.GetX(), player.GetY() - 1)) {
          player.MoveLeft();
          map.MoveMonsters(player);
          continue;
        }
      }
      else if (player_action == "d" || player_action == "D") {
        if (map.IsFree(player.GetX(), player.GetY() + 1)) {
          player.MoveRight();
          map.MoveMonsters(player);
          continue;
        }
      }
    }

    std::ofstream health_file;
    health_file.open("../player_health.txt", std::ofstream::out | std::ofstream::trunc);
    health_file << player.GetHealth() << " " <<  player.GetMaxHealth() << " " << player.GetDamage() << " 0";
    health_file.close();

    std::ofstream score_file;
    score_file.open("../score.txt", std::ofstream::out | std::ofstream::trunc);
    score_file << kills;
    score_file.close();

    int high_score;
    std::ifstream high_score_file;
    high_score_file.open("../high_score.txt");
    high_score_file >> high_score;
    high_score_file.close();

    if (kills > high_score) {
      std::ofstream high_score_file_out;
      high_score_file_out.open("../high_score.txt", std::ofstream::out | std::ofstream::trunc);
      high_score_file_out << kills;
      high_score_file_out.close();
    }
  }
};