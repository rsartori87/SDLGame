#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams, std::shared_ptr<InputHandler> pInputHandler);
  virtual void draw(SDL_Renderer* pRenderer);
  virtual void update();
  virtual void clean();

private:
  void handleInput();

  std::shared_ptr<InputHandler> m_inputHandler;
};

#endif
