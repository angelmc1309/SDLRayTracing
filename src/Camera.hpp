#pragma once
#include "matematical.hpp"
#include "constants.hpp"
// This class contains basic funcitonalities to compute the rays needed in our rasterization
class Camera
{
public:
  Camera();

  Camera(vec3& origin, vec3& lookAt, int pixelWidth, int pixelHeight, double fov);

  void computeRay(int x, int y, ray& r) const;

private:

  vec3 origin;
  vec3 lookAt;
  int pixelWidth;
  int pixelHeight;
  double fov;

};

