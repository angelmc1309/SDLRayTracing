#include "Sphere.hpp"

Sphere::Sphere()
{
  center.x = 0.;
  center.y = 0.;
  center.z = 0.;
  
  radius = 1.;
}

Sphere::Sphere(const vec3& center, double radius)
{
  this->center.x = center.x;
  this->center.y = center.y;
  this->center.z = center.z;

  this->radius = radius;
}

Sphere::~Sphere()
{
}

bool Sphere::hit(const ray & r, vec3 & point) const
{
  vec3 v;

  v.x = center.x - r.origin.x;
  v.y = center.y - r.origin.y;
  v.z = center.z - r.origin.z;


  double t = (v.x * r.direction.x + v.y * r.direction.y + v.z * r.direction.z) /
    (r.direction.x * r.direction.x + r.direction.y * r.direction.y + r.direction.z * r.direction.z);

  if (t < 0) {
    return false; // The sphere is behind the ray's starting point
  }

  double d = sqrt(v.x * v.x + v.y * v.y + v.z * v.z - t * t);
  if (d > this->radius) {
    return false; // The ray misses the sphere
  }

  double a = sqrt(this->radius * this->radius - d * d);

  point.x = r.origin.x + t * r.direction.x - a * r.direction.x;
  point.y = r.origin.y + t * r.direction.y - a * r.direction.y;
  point.z = r.origin.z + t * r.direction.z - a * r.direction.z;

  return true;
}

vec3 Sphere::normal(const vec3 &point)
{
  vec3 normal;

  normal.x = point.x - center.x;
  normal.y = point.y - center.y;
  normal.z = point.z - center.z;

  return normal.normalize();
}
