/**
 * \file app.hpp
 *
 */

#pragma once

#ifndef APP_HPP_
#define APP_HPP_

#include <string>
#include <vector>
#include <memory>

/**
 * \class App
 * \brief The main application
 *
 */
class App {
public:

  /// Special utility class for constructing an App
  class Configuration;

  /// Default Constructor
  App();

  /// Construct from program arguments
  App(const std::vector<std::string> args);

  /// Construct from configuration object
  App(const Configuration&);

  std::string Name() const;

protected:
  /// pointer to configuration
  const std::unique_ptr<Configuration> _cfg;
};


class App::Configuration {

std::string name;

public:
    static Configuration FromArgs(const std::vector<std::string> args);
    static Configuration Defaults();

    std::string Name() const { return name; };
};

inline
App::Configuration
App::Configuration::FromArgs(const std::vector<std::string> args)
{
  App::Configuration cfg = App::Configuration::Defaults();
  return cfg;
}

inline
App::Configuration
App::Configuration::Defaults()
{
  App::Configuration cfg;
  cfg.name = "DEFAULT-NAME";
  return cfg;
}

inline
std::string
App::Name() const 
{
  return _cfg->Name();
}


#endif
