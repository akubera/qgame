/**
 * \file main.cc
 *
 * Main executable file for qgame
 */

#include "app.hpp"
#include "game.hpp"
#include "player.hpp"


#include <iostream>
#include <vector>
#include <cstddef>
#include <string>

int
main(int argc, char **argv)
{
  // build vector of strings from unix argv
  const std::vector<std::string> args(argv, argv + argc);

  // Create application from arguments
  App app(args);

  std::cout << "Playing Game: " << app.Name() << "\n";

  std::vector<Player> players;
  std::string buffer;

  for (;;) {
    if (players.empty()) {
      std::cout << "\nEnter player name and press enter; leave blank and press enter to continue.\n";
    }

    // prompt for player names
    std::cout << "\nPlayer: " << players.size() + 1 << ": ";
    std::getline(std::cin, buffer);

    // strip away any whitespace at beginning and end of string
    const size_t start = buffer.find_first_not_of(" \n"),
                  stop = buffer.find_last_not_of(" \n"),
                   len = stop - start + 1;

    // 'start' has no position - no characters other than whitespace are real
    // empty line - break out of this loop.
    if (start == std::string::npos || buffer.empty()) {
      break;
    }

    // get the name without spaces
    std::string name = buffer.substr(start, len);

    if (name == "esc") {
      std::cout << "Quitting the game!\n";
      return 0;
    }

    // create new Player and add to players
    players.push_back(Player(name, players.size()+1));

    // print a little string to let us know what happened
    std::cout << "Player" << players.back().getID() << "'s name is '" << players.back().getName() << "'\n";
  }

  std::cout << "\nList of entered players: ";
  for (auto const& player : players) {
      std::cout << player;
  }

  std::cout << "\n\nqgame exited.\n";

  return 0;
}
