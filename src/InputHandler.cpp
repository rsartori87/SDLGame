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
  SDL_Event event;
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	{
	  return false;
	}
    }
  return true;
}
