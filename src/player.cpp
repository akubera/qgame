/**
 * \file player.cpp
 */

#include "player.hpp"
#include "game.hpp"

Player::Player():
  _name("noname")
{

}

Player::Player(std::string name):
  _name(name)
{

}

std::string
Player::getName() const
{
  return _name;
}
