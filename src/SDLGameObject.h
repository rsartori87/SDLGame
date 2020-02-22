#ifndef SDL_GO_H
#define SDL_GO_H

#include "GameObject.h"
#include "Vector2D.h"
#include <SDL.h>

class SDLGameObject : public GameObject
{
public:

  SDLGameObject(const LoaderParams* pParamas);

  virtual void draw(SDL_Renderer* pRenderer);
  virtual void update();
  virtual void clean() {};

protected:
  int m_width, m_height, m_currentRow, m_currentFrame;

  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;

  std::string m_textureID;
};

#endif
