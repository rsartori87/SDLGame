#include <iostream>

#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
  // TODO implement method
}

void PlayState::render()
{
  // TODO implement method
}

bool PlayState::onEnter()
{
  std::cout << "entering PlayState" << std::endl;
  return true;
}

bool PlayState::onExit()
{
  std::cout << "exiting PlayState" << std::endl;
  return true;
}
