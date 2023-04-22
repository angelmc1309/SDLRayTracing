#pragma once

#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>

#include "SDL_manager.hpp"
#include "Camera.hpp"
#include "matematical.hpp"
#include "Shape.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"

#include "constants.hpp"

using namespace std;

class Driver
{
public:

  Driver();

  ~Driver();

  void go();
};

#endif // DRIVER_H