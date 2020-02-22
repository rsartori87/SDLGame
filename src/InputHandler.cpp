#include "InputHandler.h"

#include "SDL.h"
#include <iostream>

void InputHandler::initializeJoysticks()
{
  // if (SDL_GameControllerAddMapping("03000000c6240000025b000002020000,Thrustmaster GPX Gamepad,a:b0,b:b1,back:b6,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b8,leftshoulder:b4,leftstick:b9,lefttrigger:a2,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b10,righttrigger:a5,rightx:a3,righty:a4,start:b7,x:b2,y:b3,platform:Linux")) {
  //   std::cout << "Added mapping for my controller" << std::endl;
  // }
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
	    }
	  else
	    {
	      std::cout << SDL_GetError();
	    }
	}
      SDL_JoystickEventState(SDL_ENABLE);
      m_bJoystickInitialized = true;

      std::cout << "Initialised " << m_joysticks.size() << " joystick(s)";
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
