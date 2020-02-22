#ifndef GAME_O_H
#define GAME_O_H

#include "LoaderParams.h"
#include <SDL.h>

class GameObject
{
public:
  virtual void draw(SDL_Renderer* pRenderer)=0;
  virtual void update()=0;
  virtual void clean()=0;
  virtual ~GameObject() {}
  
protected:
  GameObject(const LoaderParams* pParams) {}
};

#endif
