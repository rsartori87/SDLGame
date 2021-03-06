#ifndef IO_H
#define IO_H

#include <SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
  {
   LEFT = 0,
   MIDDLE = 1,
   RIGHT = 2
  };

class InputHandler
{
public:
  InputHandler();
  ~InputHandler() {};
  
  void initializeJoysticks();

  bool joystickInitialised() {
    return m_bJoystickInitialized;
  }

  bool update();
  void clean();
  int xvalue(int joy, int stick);
  int yvalue(int joy, int stick);

  bool getButtonState(int joy, int buttonNumber)
  {
    return m_buttonStates[joy][buttonNumber];
  }

  bool getMouseButtonState(int buttonNumber)
  {
    return m_mouseButtonStates[buttonNumber];
  }

  Vector2D* getMousePosition()
  {
    return m_mousePosition;
  }

  bool isKeyDown(SDL_Scancode key);
  
private:

  void onKeyDown();
  void onKeyUp();

  void onMouseMove(SDL_Event& event);
  void onMouseButtonDown(SDL_Event& event);
  void onMouseButtonUp(SDL_Event& event);

  void onJoystickAxisMove(SDL_Event& event);
  void onJoystickButtonDown(SDL_Event& event);
  void onJoystickButtonUp(SDL_Event& event);

  bool m_bJoystickInitialized;
  std::vector<SDL_Joystick*> m_joysticks;
  std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
  const int m_joystickDeadZone = 10000;
  std::vector<std::vector<bool>> m_buttonStates;
  std::vector<bool> m_mouseButtonStates;
  Vector2D* m_mousePosition;
  const Uint8* m_keystates;
};

#endif
