/**
 * \file app.cpp
 *
 */


#include "app.hpp"


App::App():
  App(App::Configuration::Defaults())
{
}

App::App(const std::vector<std::string> args):
  App(App::Configuration::FromArgs(args))
{
}

App::App(const App::Configuration &cfg):
  _cfg(std::make_unique<App::Configuration>(cfg))
{
}

