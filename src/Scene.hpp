#pragma once

#include "Shape.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "SDL_manager.hpp"
#include "Light.hpp"
#include "constants.hpp"

#include <vector>
#include <iostream>

using namespace std;

class Scene
{
public:
  
  Scene();
  
  ~Scene();
     
  void render(const SDL_manager & sdl_manager);

  void computeColor(const ray &r, const vec3 &interPoint, Shape *shape, vec3 &color);

  vec3 blingPhong(const ray &r, const vec3 &interPoint, Shape *shape);
private:

  std::vector<Shape*> shapes;
  
  std::vector<Light*> lights;

  Camera camera;

  vec3 background_color = vec3(0., 0., 0.);

};

