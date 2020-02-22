#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams);
  virtual void draw(SDL_Renderer* pRenderer);
  virtual void update();
  virtual void clean();
};
