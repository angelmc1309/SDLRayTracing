#pragma once

#include <SDL.h>

class SDL_manager
{
public:

  SDL_manager();

  ~SDL_manager();

  int init_SDL_video();

  void init_window_and_renderer(int width, int heigth);

  void set_background_color(int r, int g, int b, int a) const;

  void draw_point(int x, int y, int r, int g, int b, int a) const;

  void update_screen() const;

  void wait_on_close();

  void clean();

private:

  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

};

