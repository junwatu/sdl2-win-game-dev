// main.cpp
#include <sqlite3.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[])
{
  printf("%s\n", sqlite3_libversion());

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow("Kenongo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event input;
  bool quit = false;
  int r = 0;
  int g = 255;
  int b = 100;

  // Game Loop
  while (!quit)
  {
    while (SDL_PollEvent(&input) > 0)
    {
      if (input.type == SDL_QUIT)
      {
        quit = true;
      }
      else if (input.type == SDL_KEYDOWN)
      {
        r = rand() % 255;
        g = rand() % 255;
        b = rand() % 255;
      }

      SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
      SDL_RenderClear(renderer);
      SDL_RenderPresent(renderer);
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
