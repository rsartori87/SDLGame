#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <vector>
#include <memory>

#include "GameState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "InputHandler.h"

class MenuState : public GameState
{
public:
  MenuState(SDL_Renderer* pRenderer, std::shared_ptr<InputHandler> pInputHandler);
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateID() const { return s_menuID; }

private:
  static const std::string s_menuID;
  std::vector<std::unique_ptr<GameObject>> m_gameObjects;
  SDL_Renderer* m_renderer;
  std::shared_ptr<InputHandler> m_inputHandler;

  static void s_menuToPlay();
  static void s_exitFromMenu();
};

#endif
