#include <string>
#include <map>
#include <SDL.h>

class TextureManager
{
public:
  ~TextureManager() {}

  static TextureManager* instance() {
    if (s_pInstance == 0)
      {
	s_pInstance = new TextureManager();
	return s_pInstance;
      }

    return s_pInstance;
  }
  
  bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
  void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);
  void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);

private:
  std::map<std::string, SDL_Texture*> m_textureMap;
  TextureManager() {}
  static TextureManager* s_pInstance;
};


typedef TextureManager TheTextureManager;
