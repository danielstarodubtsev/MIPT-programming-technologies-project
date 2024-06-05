#include <algorithm>

#pragma once

class Player {
  int x_coord_ = 1;
  int y_coord_ = 1;
  int max_health_ = 100;
  int health_ = max_health_;
  int damage_ = 25;
  int attack_chance = 50;
public:
  void ToCoords(int xc, int yc) {
    x_coord_ = xc;
    y_coord_ = yc;
  }
  void MoveUp() {
    --x_coord_;
  }

  void MoveDown() {
    ++x_coord_;
  }

  void MoveLeft() {
    --y_coord_;
  }

  void MoveRight() {
    ++y_coord_;
  }

  int GetDamage() const {
    return damage_;
  }

  int GetHealth() const {
    return health_;
  }

  int GetMaxHealth() const {
    return max_health_;
  }

  std::pair<int, int> GetCoords() const {
    return { x_coord_, y_coord_ };
  }

  int GetX() const {
    return x_coord_;
  }

  int GetY() const {
    return y_coord_;
  }

  void Heal(int amount) {
    health_ = std::min(health_ + amount, max_health_);
  }

  void HealFull() {
    health_ = max_health_;
  }

  void GetHit(int damage) {
    health_ -= damage;
  }

  bool IsDead() const {
    return health_ <= 0;
  }

  void SetMaxHealth(int new_max_health) {
    max_health_ = new_max_health;
  }

  void SetDamage(int new_damage) {
    damage_ = new_damage;
  }

  Player() = default;
}; 