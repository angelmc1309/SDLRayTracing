#include "Driver.hpp"

Driver::Driver()
{
}

Driver::~Driver()
{
}

void Driver::go()
{


  {
    SDL_manager sdl_manager;
    Scene scene;

    // Initialize SDL
    sdl_manager.init_SDL_video();

    sdl_manager.init_window_and_renderer(WIDTH, HEIGHT);

    sdl_manager.set_background_color(0, 0, 0, 255);

    sdl_manager.update_screen();

    scene.render(sdl_manager);

    sdl_manager.update_screen();

    std::cout << "Render Finished" << std::endl;
    
    sdl_manager.wait_on_close();

  }
}
