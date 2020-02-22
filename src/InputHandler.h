#ifndef IO_H
#define IO_H

#include <SDL.h>
#include <vector>
#include "Vector2D.h"

class InputHandler
{
public:
  InputHandler() {};
  ~InputHandler() {};
  
  void initializeJoysticks();

  bool joystickInitialised() {
    return m_bJoystickInitialized;
  }

  bool update();
  void clean();
private:
  int xvalue(int joy, int stick);
  int yvalue(int joy, int stick);
  
  bool m_bJoystickInitialized;
  std::vector<SDL_Joystick*> m_joysticks;
  std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
  const int m_joystickDeadZone = 10000;
};

#endif
