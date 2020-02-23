#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams, std::shared_ptr<InputHandler> pInputHandler, void (*callback)())
  : SDLGameObject(pParams), m_inputHandler(pInputHandler), m_callback(callback)
{
  m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw(SDL_Renderer* pRenderer)
{
  SDLGameObject::draw(pRenderer);
}

void MenuButton::update()
{
  Vector2D* pMousePos = m_inputHandler->getMousePosition();

  if (pMousePos->getX() < (m_position.getX() + m_width)
      && pMousePos->getX() > m_position.getX()
      && pMousePos->getY() < (m_position.getY() + m_height)
      && pMousePos->getY() > m_position.getY())
    {
      if (m_inputHandler->getMouseButtonState(LEFT) && m_bReleased)
	{
	  m_currentFrame = CLICKED;

	  m_callback();

	  m_bReleased = false;
	}
      else if (!m_inputHandler->getMouseButtonState(LEFT))
	{
	  m_bReleased = true;
	  m_currentFrame = MOUSE_OVER;
	}
    }
  else
  {
    m_currentFrame = MOUSE_OUT;
  }
}

void MenuButton::clean()
{
  SDLGameObject::clean();
}
