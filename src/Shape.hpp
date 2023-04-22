#pragma once

#include "matematical.hpp"
#include "Material.hpp"

class Shape
{
public:
  Shape();
  
  virtual bool hit(const ray& r, vec3& point) const = 0;

  virtual vec3 normal (const vec3& point) = 0;

  Material getMaterial() const;

  void setMaterial(const Material& material);
  
private:

  Material material;

};

