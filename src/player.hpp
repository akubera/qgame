/**
 * \file player.hpp
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player {
public:
  Player();
  Player(std::string name);

  std::string getName() const;

protected:
  std::string _name;
};

#endif /* PLAYER_H_ */
