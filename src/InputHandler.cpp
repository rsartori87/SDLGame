#include "InputHandler.h"

#include "SDL.h"
#include <iostream>

InputHandler::InputHandler()
{
  for (int i = 0; i < 3; i++)
    {
      m_mouseButtonStates.push_back(false);
    }
}

void InputHandler::initializeJoysticks()
{
  if (SDL_WasInit(SDL_INIT_JOYSTICK))
    {
      std::cout << "Initializing joystick subsystem" << std::endl;
      SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

  if (SDL_NumJoysticks() > 0)
    {
      for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
	  SDL_Joystick* joy = SDL_JoystickOpen(i);
	  if (joy)
	    {
	      m_joysticks.push_back(joy);
	      m_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

	      std::vector<bool> tempButtons;

	      for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
		{
		  tempButtons.push_back(false);
		}

	      m_buttonStates.push_back(tempButtons);
	    }
	  else
	    {
	      std::cout << SDL_GetError();
	    }
	}
      SDL_JoystickEventState(SDL_ENABLE);
      m_bJoystickInitialized = true;

      std::cout << "Initialised " << m_joysticks.size() << " joystick(s)" << std::endl;
    }
  else
    {
      std::cout << "No joysticks found" << std::endl;
      m_bJoystickInitialized = false;
    }
}

void InputHandler::clean()
{
  if (m_bJoystickInitialized)
    {
      for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
	{
	  SDL_JoystickClose(m_joysticks[i]);
	}
    }
}

bool InputHandler::update()
{
  bool run = true;
  SDL_Event event;
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	{
	  run = false;
	}
      if (event.type == SDL_JOYAXISMOTION)
	{
	  int whichOne = event.jaxis.which;
	  if (event.jaxis.axis == 0)
	    {
	      if (event.jaxis.value > m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].first->setX(1);
		}
	      else if (event.jaxis.value < -m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].first->setX(-1);
		}
	      else
		{
		  m_joystickValues[whichOne].first->setX(0);
		}
	    }

	  if (event.jaxis.axis == 1)
	    {
	      if (event.jaxis.value > m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].first->setY(1);
		}
	      else if (event.jaxis.value < -m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].first->setY(-1);
		}
	      else
		{
		  m_joystickValues[whichOne].first->setY(0);
		}
	    }

	  if (event.jaxis.axis == 3)
	    {
	      if (event.jaxis.value > m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].second->setX(1);
		}
	      else if (event.jaxis.value < -m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].second->setX(-1);
		}
	      else
		{
		  m_joystickValues[whichOne].second->setX(0);
		}
	    }
	   if (event.jaxis.axis == 4)
	    {
	      if (event.jaxis.value > m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].second->setY(1);
		}
	      else if (event.jaxis.value < -m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].second->setY(-1);
		}
	      else
		{
		  m_joystickValues[whichOne].second->setY(0);
		}
	    }
	}

      if (event.type == SDL_JOYBUTTONDOWN)
	{
	  int whichOne = event.jaxis.which;

	  m_buttonStates[whichOne][event.jbutton.button] = true;
	}

      if (event.type == SDL_JOYBUTTONUP)
	{
	  int whichOne = event.jaxis.which;

	  m_buttonStates[whichOne][event.jbutton.button] = false;
	}

      if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (event.button.button == SDL_BUTTON_LEFT)
	    {
	      m_mouseButtonStates[LEFT] = true;
	    }

	  if (event.button.button == SDL_BUTTON_MIDDLE)
	    {
	      m_mouseButtonStates[MIDDLE] = true;
	    }

	  if (event.button.button == SDL_BUTTON_RIGHT)
	    {
	      m_mouseButtonStates[RIGHT] = true;
	    }
	}

      if (event.type == SDL_MOUSEBUTTONUP)
	{
	  if (event.button.button == SDL_BUTTON_LEFT)
	    {
	      m_mouseButtonStates[LEFT] = false;
	    }

	  if (event.button.button == SDL_BUTTON_MIDDLE)
	    {
	      m_mouseButtonStates[MIDDLE] = false;
	    }

	  if (event.button.button == SDL_BUTTON_RIGHT)
	    {
	      m_mouseButtonStates[RIGHT] = false;
	    }
	}
    }
  
  return run;
}

int InputHandler::xvalue(int joy, int stick)
{
  if (m_joystickValues.size() > 0)
    {
      if (stick == 1)
	{
	  return m_joystickValues[joy].first->getX();
	}
      else if (stick == 2)
	{
	  return m_joystickValues[joy].second->getX();
	}
    }
  return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
  if (m_joystickValues.size() > 0)
    {
      if (stick == 1)
	{
	  return m_joystickValues[joy].first->getY();
	}
      else if (stick == 2)
	{
	  return m_joystickValues[joy].second->getY();
	}
    }
  return 0;
}
