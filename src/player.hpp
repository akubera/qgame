/**
 * \file player.hpp
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
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
  
  /**
   * Named/ID'd constructor
   * Sets name/ID to provided name/ID
   *
   * \param name Name of the player
   * \param id ID of the player
   */
  Player(std::string name, unsigned short id);

  /// Return name of the player
  std::string getName() const;
  
  /// Return id of the player
  unsigned short getID() const;

protected:
  /// name of the player
  std::string _name;
  
  // player ID number
  unsigned short _id;
};

/*Stand-alone Functions*/
// Print player data/information
std::ostream &operator<<(std::ostream&, const Player&);

#endif /* PLAYER_H_ */
