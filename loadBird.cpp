
#include "loadbird.h"
#include <string>
#include <iostream>

using namespace std;

SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *fileName)
{
  SDL_Surface *surface = SDL_LoadBMP(fileName);
  if (!surface) return false;
  SDL_Texture *res = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return res;
}
