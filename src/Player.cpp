#include "Player.h"

#include <SDL.h>

Player::Player(const LoaderParams* pParams, std::shared_ptr<InputHandler> pInputHandler) : SDLGameObject(pParams)
{
  m_inputHandler = pInputHandler;
}

void Player::draw(SDL_Renderer* pRenderer)
{
  SDLGameObject::draw(pRenderer);
}

void Player::update()
{
  m_velocity.setX(0);
  m_velocity.setY(0);

  handleInput();
  
  m_currentFrame = int (((SDL_GetTicks() / 100) % 6));

  SDLGameObject::update();
}

void Player::clean()
{}

void Player::handleInput()
{
  if (m_inputHandler->joystickInitialised())
    {
      if (m_inputHandler->xvalue(0, 1) > 0 ||
	  m_inputHandler->xvalue(0, 1) < 0)
	{
	  m_velocity.setX(1 * m_inputHandler->xvalue(0, 1));
	}
      
      if (m_inputHandler->yvalue(0, 1) > 0 ||
	  m_inputHandler->yvalue(0, 1) < 0)
	{
	  m_velocity.setY(1 * m_inputHandler->yvalue(0, 1));
	}

      if (m_inputHandler->xvalue(0, 2) > 0 ||
	  m_inputHandler->xvalue(0, 2) < 0)
	{
	  m_velocity.setX(1 * m_inputHandler->xvalue(0, 2));
	}
      
      if (m_inputHandler->yvalue(0, 2) > 0 ||
	  m_inputHandler->yvalue(0, 2) < 0)
	{
	  m_velocity.setY(1 * m_inputHandler->yvalue(0, 2));
	}
    }
}
