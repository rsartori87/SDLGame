#include "Game.h"
#include <iostream>

#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "MenuState.h"
#include "PlayState.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
  m_inputHandler = std::make_shared<InputHandler>();
  int flags = 0;

  if (fullscreen)
    {
      flags = SDL_WINDOW_FULLSCREEN;
    }
  
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
      std::cout << "SDL init succes" << std::endl;
      m_inputHandler->initializeJoysticks();
      m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
      if (m_pWindow != 0)
	{
	  std::cout << "window creation succes" << std::endl;
	  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

	  if (m_pRenderer != 0)
	    {
	      std::cout << "renderer creation success" << std::endl;
	      SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	    }
	  else
	    {
	      std::cout << "renderer init fail" << std::endl;
	      return false;
	    }
	}
      else
	{
	  std::cout << "Window init fail" << std::endl;
	  return false;
	}
    }
  else
    {
      std::cout << "SDL init fail" << std::endl;
      return false;
    }

  std::cout << "init success" << std::endl;
  m_bRunning = true;

  m_pGameStateMachine = new GameStateMachine();
  m_pGameStateMachine->changeState(new MenuState(m_pRenderer, m_inputHandler));

  // if (!TheTextureManager::instance()->load("assets/animate-alpha.png", "animate", m_pRenderer)) {
  //   return false;
  // }

  // m_gameObjects.push_back(std::make_unique<Player>(new LoaderParams(100, 100, 128, 82, "animate"), m_inputHandler));
  
  return true;
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  m_pGameStateMachine->render();
  
  SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
  m_pGameStateMachine->update();
}

void Game::handleEvents()
{
  m_bRunning = m_inputHandler->update();
  
  if (m_inputHandler->isKeyDown(SDL_SCANCODE_RETURN))
    {
      m_pGameStateMachine->changeState(new PlayState());
    }
}


void Game::clean()
{
  std::cout << "cleaning game" << std::endl;
  m_inputHandler->clean();
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}
