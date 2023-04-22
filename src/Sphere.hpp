#pragma once

#include "Shape.hpp"
#include "matematical.hpp"

class Sphere : public Shape
{
public:
  Sphere();

  Sphere(const vec3& center, double radius);
  //Sphere(const Sphere& other);

  //Sphere& operator=(const Sphere& other);

  ~Sphere();

  bool hit(const ray& r, vec3& point) const;

  vec3 normal (const vec3& point);

private:
  vec3 center;
  double radius;
};

