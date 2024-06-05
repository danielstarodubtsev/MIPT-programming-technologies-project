#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include "monster.h"
#include "player.h"
#include "monster_factory.h"

#pragma once

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

class Map {
  EmptyFactory empty_factory;
  HealFactory heal_factory;
  WallFactory wall_factory;
  ScaryFactory scary_factory;

  struct Field {
    int xcoord = 0;
    int ycoord = 0;
    Monster* monster = nullptr;
    Field() = default;
    Field(int x, int y, Monster* ptr = nullptr) : xcoord(x), ycoord(y), monster(ptr) {}
    int Fight(Player& player) {
      return monster->Fight(player);
    }
  };
  int height_ = 5;
  int width_ = 5;
  std::vector<std::vector<Field>> mp;

  const double alpha = 0.25;
  const double needs = 0.4;
  const double spawn_monst = 0.08;
  const double spawn_heal = 0.05;
  const int MAXN = 1000;

  bool Correct(int x_coord, int y_coord) {
    if (0 >= x_coord || x_coord >= height_ - 1 || y_coord >= width_ - 1 || y_coord <= 0) {
      return false;
    }
    return true;
  }

  void DFS(int x_coord, int y_coord, std::vector<std::pair<int, int>>& hod, std::vector<std::vector<bool>>& used, int xst, int yst) {
    used[x_coord][y_coord] = 1;
    int block = std::abs(static_cast<int>(rnd())) % MAXN;

    if (block < MAXN * alpha && !(x_coord == xst && y_coord == yst)) {
      return;
    }
    mp[x_coord][y_coord].monster = (Monster*)empty_factory.create();

    for (auto it : hod) {
      int nx = it.first + x_coord;
      int ny = it.second + y_coord;

      if (Correct(nx, ny) && !used[nx][ny]) {
        DFS(nx, ny, hod, used, xst, yst);
      }
    }
  }

  void Build(int xst, int yst) {
    std::vector<std::pair<int, int>> step = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
    std::vector<std::vector<bool>> used(height_, std::vector<bool>(width_));
    DFS(1, 1, step, used, 1, 1);
  }

  double Free() {
    int sum = 0;

    for (int i = 0; i < height_; ++i) {
      for (int j = 0; j < width_; ++j) {
        if (mp[i][j].monster->type() == "Empty") {
          sum++;
        }
      }
    }

    return static_cast<double>(sum);
  }
  void Generate() {
    for (int i = 0; i < height_; i++) {
      for (int j = 0; j < width_; ++j) {
        mp[i][j].xcoord = i;
        mp[i][j].ycoord = j;
        mp[i][j].monster = wall_factory.create();
      }
    }
  }
public:
  Map(const Map& other) = default;
  Map(const Player& player, int height_ = 7, int width_ = 7) : height_(height_), width_(width_) {
    mp.resize(height_, std::vector<Field>(width_));
    Generate();
    while (Free() < static_cast<double>(height_ * width_) * needs) {
      Generate();
      Build(player.GetX(), player.GetY());
    }
    int S = Free();
    for (int i = 0; i < static_cast<int>(S * spawn_monst); i++) {
      int x = std::abs(static_cast<int>(rnd())) % height_;
      int y = std::abs(static_cast<int>(rnd())) % width_;
      while ((x == player.GetX() && y == player.GetY()) || mp[x][y].monster->type() != "Empty") {
        x = std::abs(static_cast<int>(rnd())) % height_;
        y = std::abs(static_cast<int>(rnd())) % width_;
      }
      mp[x][y].monster = scary_factory.create(&player);
    }
    S = Free();
    for (int i = 0; i < static_cast<int>(S * spawn_heal); i++) {
      int x = std::abs(static_cast<int>(rnd())) % height_;
      int y = std::abs(static_cast<int>(rnd())) % width_;
      while ((x == player.GetX() && y == player.GetY()) || mp[x][y].monster->type() != "Empty") {
        x = std::abs(static_cast<int>(rnd())) % height_;
        y = std::abs(static_cast<int>(rnd())) % width_;
      }
      mp[x][y].monster = heal_factory.create();
    }
  }
  Map& operator=(const Map& other) {
    height_ = other.height_;
    width_ = other.width_;
    mp = other.mp;
    return *this;
  }
  void Print(int player_x, int player_y) {
    std::ofstream map_file;
    map_file.open("../map_state.txt", std::ofstream::out | std::ofstream::trunc);

    for (int i = 0; i < height_; ++i) {
      for (int j = 0; j < width_; ++j) {
        if (i == player_x && j == player_y) {
          map_file << "P";
        }
        else {
          mp[i][j].monster->Print(map_file);
        }
      }

      map_file << "\n";
    }
    map_file.close();
  }

  int Fight(int x_coord, int y_coord, Player& player) {
    int result = mp[x_coord][y_coord].Fight(player);
    if (result == 1) {
      mp[x_coord][y_coord].monster = empty_factory.create();
    }
    return result;
  }

  bool IsFree(int x_coord, int y_coord) const {
    return mp[x_coord][y_coord].monster->type() != "Wall";
  }

  bool IsFree(std::pair<int, int> coords) const {
    return IsFree(coords.first, coords.second);
  }

  bool IsMonster(int x_coord, int y_coord) {
    return mp[x_coord][y_coord].monster->type() == "Scary" || mp[x_coord][y_coord].monster->type() == "Heal";
  }

  bool IsScaryMonster(int x_coord, int y_coord) {
    return mp[x_coord][y_coord].monster->type() == "Scary";
  }

  bool IsClear() {
    for (int i = 0; i < height_; ++i) {
      for (int j = 0; j < width_; ++j) {
        if (mp[i][j].monster->type() == "Scary") {
          return false;
        }
      }
    }
    return true;
  }

  int width() const {
    return width_;
  }

  int height() const {
    return height_;
  }

  int width() {
    return width_;
  }

  int heights() {
    return height_;
  }

  void MoveMonsters(const Player& player) {
    for (int x = 0; x < width_; ++x) {
      for (int y = 0; y < height_; ++y) {
        if (mp[y][x].monster->type() == "Scary" && std::abs(static_cast<int>(rnd())) % 4 == 0) {
          int direction = std::abs(static_cast<int>(rnd())) % 4;
          if (direction == 0 && Correct(x, y - 1) && mp[y - 1][x].monster->type() == "Empty" && player.GetCoords() != std::make_pair(x, y - 1)) {
            std::swap(mp[y][x], mp[y - 1][x]);
          } else if (direction == 1 && Correct(x, y + 1) && mp[y + 1][x].monster->type() == "Empty" && player.GetCoords() != std::make_pair(x, y + 1)) {
            std::swap(mp[y][x], mp[y + 1][x]);
          } else if (direction == 2 && Correct(x - 1, y) && mp[y][x - 1].monster->type() == "Empty" && player.GetCoords() != std::make_pair(x - 1, y)) {
            std::swap(mp[y][x], mp[y][x - 1]);
          } else if (direction == 3 && Correct(x + 1, y) && mp[y][x + 1].monster->type() == "Empty" && player.GetCoords() != std::make_pair(x + 1, y)) {
            std::swap(mp[y][x], mp[y][x + 1]);
          }
        }
      }
    }
  }
};