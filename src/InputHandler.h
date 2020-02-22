#ifndef IO_H
#define IO_H

#include <SDL.h>
#include <vector>

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
  bool m_bJoystickInitialized;
  std::vector<SDL_Joystick*> m_joysticks;
};

#endif
