#include "Game.h"
#include <iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  Uint32 frameStart, frameTime;
  std::cout << "game init attempt..." << std::endl;
  Game game;
  if(game.init("Chapter 1", 100, 100, 640, 480, false))
    {
      std::cout << "game init success!" << std::endl;
      while (game.running())
	{
	  frameStart = SDL_GetTicks();
	  
	  game.handleEvents();
	  game.update();
	  game.render();

	  frameTime = SDL_GetTicks() - frameStart;

	  if (frameTime < DELAY_TIME)
	    {
	      SDL_Delay((int) (DELAY_TIME - frameTime));
	    }
	}
    }
  else{
    std::cout << "game init failure - " << SDL_GetError() << std::endl;
    return -1;
  }

  std::cout << "game closing..." << std::endl;
  game.clean();
  
  return 0;
}
