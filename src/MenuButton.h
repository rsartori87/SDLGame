#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <memory>

#include "SDLGameObject.h"
#include "InputHandler.h"

class MenuButton : public SDLGameObject
{
public:
  MenuButton(const LoaderParams* pParams, std::shared_ptr<InputHandler> pInputHandler, void (*callback)());

  virtual void draw(SDL_Renderer* pRenderer);
  virtual void update();
  virtual void clean();

private:
  enum button_state
    {
     MOUSE_OUT = 0,
     MOUSE_OVER = 1,
     CLICKED = 2
    };

  std::shared_ptr<InputHandler> m_inputHandler;
  void (*m_callback)();
  bool m_bReleased;
};

#endif
