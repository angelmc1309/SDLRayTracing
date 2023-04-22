#include "SDL_manager.hpp"

SDL_manager::SDL_manager()
{
}

SDL_manager::~SDL_manager()
{
}

int SDL_manager::init_SDL_video()
{
  return SDL_Init(SDL_INIT_VIDEO);
}

void SDL_manager::init_window_and_renderer(int width, int heigth)
{
  // Create a window
  this->window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, heigth, SDL_WINDOW_SHOWN);

  // Create a renderer
  this->renderer = SDL_CreateRenderer(this->window, -1, 0);

}

void SDL_manager::set_background_color(int r, int g, int b, int a) const
{
  // Set the background color to black
  SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
  SDL_RenderClear(this->renderer);
}

void SDL_manager::draw_point(int x, int y, int r, int g, int b, int a) const
{
  // Set the color to white
  SDL_SetRenderDrawColor(renderer, r, g, b, a);

  // Draw a white dot in the center
  SDL_RenderDrawPoint(renderer, x, y);
}

void SDL_manager::update_screen() const
{
  // Update the screen
  SDL_RenderPresent(renderer);
}

void SDL_manager::wait_on_close()
{
  // Wait for user to close window
  bool quit = false;
  SDL_Event event;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }

  // Clean up and exit
  this->clean();
}

void SDL_manager::clean()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}


