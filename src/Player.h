#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  virtual void draw(SDL_Renderer* pRenderer);
  virtual void update();
  virtual void clean();
};
