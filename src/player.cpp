/**
 * \file player.cpp
 */

#include "player.hpp"
#include "game.hpp"

#include <cstdio>
#include <iostream>

Player::Player():
  _name("noname")
{

}

Player::Player(std::string name):
  _name(name)
{

}

Player::Player(std::string name, unsigned short id):
  _name(name),
  _id (id)
{

}

std::string
Player::getName() const
{
  return _name;
}

unsigned short
Player::getID() const
{
  return _id;
}

std::ostream &operator<<(std::ostream& out_stream, const Player& player) {
  std::string name (player.getName());
  unsigned short id (player.getID());
  
  char buffer[200];
  sprintf(buffer, "\nPlayer%d: %s",\
    id,
	name.c_str()
  );
  out_stream << buffer;
  return out_stream;
}