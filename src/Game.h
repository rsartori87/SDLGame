#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <vector>
#include <memory>

#include "GameObject.h"
#include "InputHandler.h"

class Game
{
public:
  Game() {}
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

  void render();
  void update();
  void handleEvents();
  void clean();
  void quit() { m_bRunning = false; }

  bool running() { return m_bRunning; }
  SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  
  bool m_bRunning;

  int m_currentFrame;

  GameObject* m_go;
  GameObject* m_player;
  GameObject* m_enemy;

  std::vector<std::unique_ptr<GameObject>> m_gameObjects;

  std::shared_ptr<InputHandler> m_inputHandler;
};

#endif
