#include <iostream>
#include <fstream>
#include <string>
#include "player.h"

#pragma once

class Monster {
public:
  virtual void Print(std::ofstream&) = 0;
  virtual std::string type() = 0;
  virtual int Fight(Player& player) = 0;
};

class Wall : Monster {
public:
  Wall() = default;
  Wall(const Player&) {}
  std::string type() override {
    return "Wall";
  }
  void Print(std::ofstream& of) override {
    of << "w";
  }
  int Fight(Player& player) {
    return 0;
  }
};

class Empty : Monster {
public:
  Empty() = default;
  Empty(const Player&) {}
  std::string type() override {
    return "Empty";
  }
  void Print(std::ofstream& of) override {
    of << ".";
  }
  int Fight(Player& play) {
    return 0;
  }
};

class Scary : Monster {
  int health;
  int max_health;
  int attack;
  const double alpha = 2.5;
  const double beta = 1.5;
public:
  Scary() = default;
  Scary(int h, int at) : health(h), attack(at) {}
  Scary(const Player& play) {
    max_health = health = beta * play.GetMaxHealth();
    attack = static_cast<int>(play.GetDamage() / alpha / beta);
  }
  std::string type() {
    return "Scary";
  }
  void Print(std::ofstream& of) {
    of << "X";
  }
  bool IsDead() const {
    return health <= 0;
  }
  void GetHit(int dmg) {
    health -= dmg;
  }
  int Fight(Player& player) {
    // 0 - player dead
    // 1 - monster dead
    // 2 - player fleed

    while (!IsDead() && !player.IsDead()) {
      player.GetHit(attack);
      if (player.IsDead()) {
        break;
      }

      // save player health
      std::ofstream health_file;
      health_file.open("../player_health.txt", std::ofstream::out | std::ofstream::trunc);
      health_file << player.GetHealth() << " " <<  player.GetMaxHealth() << " " << player.GetDamage() << " 1\n" << health << " " << max_health << " " << attack;
      health_file.close();

      std::string player_action = "";

      while (player_action.empty()) {
        std::ifstream fight_action_file;
        fight_action_file.open("../fight_action.txt");
        fight_action_file >> player_action;
        fight_action_file.close();
      }

      std::ofstream file_deleter;
      file_deleter.open("../fight_action.txt", std::ostream::out | std::ofstream::trunc);
      file_deleter.close();

      if (player_action == "a") {
        GetHit(player.GetDamage());
      }
      else if (player_action == "f") {
        return 2;
      }
    }

    if (player.IsDead()) {
      return 0;
    }
    return 1;
  }
};

class Heal : Monster {
 public:
  Heal() = default;
  Heal(const Player&) {}
  void Print(std::ofstream& of) override {
    of << "o";
  }
  std::string type() override {
    return "Heal";
  }
  int Fight(Player& player) override {
    player.HealFull();
    return 1;
  }
};