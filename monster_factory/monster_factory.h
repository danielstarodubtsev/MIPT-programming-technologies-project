#pragma once

#include "monster.h"

struct BaseFactory {
  virtual Monster* create(const Player* = nullptr) const = 0;
};

struct ScaryFactory : BaseFactory {
  Monster* create(const Player* player) const override {
    Scary* monster = new Scary(*player);
    return (Monster*)monster;
  }
};

struct HealFactory : BaseFactory {
  Monster* create(const Player* = nullptr) const override {
    Heal* monster = new Heal();
    return (Monster*)monster;
  }
};

struct EmptyFactory : BaseFactory {
  Monster* create(const Player* = nullptr) const override {
    Empty* monster = new Empty();
    return (Monster*)monster;
  }
};

struct WallFactory : BaseFactory {
  Monster* create(const Player* = nullptr) const override {
    Wall* monster = new Wall();
    return (Monster*)monster;
  }
};