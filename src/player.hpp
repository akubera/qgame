/**
 * \file player.hpp
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

/**
 * \class Player
 * \brief Player class which plays the game
 */
class Player {
public:
  /**
   * Default constructor, sets name to 'noname'
   */
  Player();

  /**
   * Named constructor
   * Sets name to provided name
   *
   * \param name Name of the player
   */
  Player(std::string name);

  /// Return name of the player
  std::string getName() const;

protected:
  /// name of the player
  std::string _name;
};

#endif /* PLAYER_H_ */
