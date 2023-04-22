#include "Camera.hpp"

Camera::Camera()
{
  this->origin.x = 0.;
  this->origin.y = 0.;
  this->origin.z = 0.;

  this->lookAt.x = 0.;
  this->lookAt.y = 0.;
  this->lookAt.z = -1.;

  this->pixelWidth = WIDTH;
  this->pixelHeight = HEIGHT;
  this->fov = 90;
}

Camera::Camera(vec3& origin, vec3& lookAt, int pixelWidth, int pixelHeight, double fov)
{
  this->origin = origin;
  this->lookAt = lookAt;
  this->pixelWidth = pixelWidth;
  this->pixelHeight = pixelHeight;
  this->fov = fov;
}

void Camera::computeRay(int x, int y, ray& r) const
{
  r.origin.x = this->origin.x;
  r.origin.y = this->origin.y;
  r.origin.z = this->origin.z;

  double aspect_ratio = pixelWidth / (float)pixelHeight;

  double norm_pixel_x = (x + 0.5) / pixelWidth;
  double norm_pixel_y = (y + 0.5) / pixelHeight;
  
  double pixel_screen_x = ((2. * norm_pixel_x) - 1.) * aspect_ratio * tan(DEG2RAD(fov) / 2.);
  double pixel_screen_y = (1. - (2. * norm_pixel_y)) * tan(DEG2RAD(fov) / 2.);

  r.direction.x = pixel_screen_x;
  r.direction.y = pixel_screen_y;
  r.direction.z = -1.;

  r.direction.x -= r.origin.x;
  r.direction.y -= r.origin.y;
  r.direction.z -= r.origin.z;

  double length = sqrt(r.direction.x * r.direction.x + r.direction.y * r.direction.y + r.direction.z * r.direction.z); // calculate the length of the vector
  r.direction.x /= length; // divide each component by the length
  r.direction.y /= length;
  r.direction.z /= length;

}
