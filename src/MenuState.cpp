#include <iostream>

#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
  // TODO implement method
}

void MenuState::render()
{
  // TODO implement method
}

bool MenuState::onEnter()
{
  std::cout << "entering MenuState" << std::endl;
  return true;
}

bool MenuState::onExit()
{
  std::cout << "exiting MenuState" << std::endl;
  return true;
}
