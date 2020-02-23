#include <iostream>

#include "MenuState.h"
#include "MenuButton.h"

const std::string MenuState::s_menuID = "MENU";

MenuState::MenuState(SDL_Renderer* pRenderer, std::shared_ptr<InputHandler> pInputHandler)
{
  m_renderer = pRenderer;
  m_inputHandler = pInputHandler;
}

void MenuState::update()
{
  for (auto& i :  m_gameObjects)
    {
      i->update();
    }
}

void MenuState::render()
{
  for (auto& i : m_gameObjects)
    {
      i->draw(m_renderer);
    }
}

bool MenuState::onEnter()
{
  if (!TheTextureManager::instance()->load("assets/button.png", "playbutton", m_renderer))
    {
      return false;
    }

  if (!TheTextureManager::instance()->load("assets/exit.png", "exitbutton", m_renderer))
    {
      return false;
    }

  m_gameObjects.push_back(std::make_unique<MenuButton>(new LoaderParams(100, 100, 400, 100, "playbutton"), m_inputHandler, s_menuToPlay));
  m_gameObjects.push_back(std::make_unique<MenuButton>(new LoaderParams(100, 300, 400, 100, "exitbutton"), m_inputHandler, s_exitFromMenu));
  
  std::cout << "entering MenuState" << std::endl;
  return true;
}

bool MenuState::onExit()
{
  for (auto& i : m_gameObjects)
    {
      i->clean();
    }
  m_gameObjects.clear();
  TheTextureManager::instance()->clearFromTextureMap("playbutton");
  TheTextureManager::instance()->clearFromTextureMap("exitbutton");
  std::cout << "exiting MenuState" << std::endl;
  return true;
}

void MenuState::s_menuToPlay()
{
  std::cout << "Play button clicked" << std::endl;
}

void MenuState::s_exitFromMenu()
{
  std::cout << "Exit button clicked" << std::endl;
}
