#pragma once

#include <cmath>
#include <math.h> // include the math library

#define PI 3.14159265358979323846 /* pi */
#define DEG2RAD(x) ((x)*PI / 180.)

double min(double a, double b);

double max(double a, double b);


struct vec3
{
  double x, y, z;

  vec3() : x(0), y(0), z(0) {}
  
  vec3(double x, double y, double z) : x(x), y(y), z(z) {}

  vec3 operator+(const vec3 &other) const
  {
    return vec3(x + other.x, y + other.y, z + other.z);
  }

  vec3 operator-(const vec3 &other) const
  {
    return vec3(x - other.x, y - other.y, z - other.z);
  }

  vec3 operator*(double scalar) const
  {
    return vec3(x * scalar, y * scalar, z * scalar);
  }

  vec3 operator*(const vec3 &other) const
  {
    return vec3(x * other.x, y * other.y, z * other.z);
  }
  
  vec3 operator/(double scalar) const
  {
    return vec3(x / scalar, y / scalar, z / scalar);
  }
  vec3 operator/(vec3 &other) const
  {
    return vec3(x / other.x, y / other.y, z / other.z);
  }

  double dot(const vec3 &other) const
  {
    return x * other.x + y * other.y + z * other.z;
  }

  vec3 cross(const vec3 &other) const
  {
    return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
  }

  vec3 sqrt() const{
    return vec3(std::sqrt(x), std::sqrt(y), std::sqrt(z));
  }

  vec3 pow(double power) const{
    return vec3(std::pow(x, power), std::pow(y, power), std::pow(z, power));
  }
  
  double length() const
  {
    return std::sqrt(x * x + y * y + z * z);
  }

  vec3 normalize() const
  {
    return *this / length();
  }
  vec3 clamp(double low, double high){
    return vec3(min(max(x, low), high), min(max(y, low), high), min(max(z, low), high));
  }
};

struct ray
{
  vec3 origin;
  vec3 direction;
};


/*
template <typename dtype = double>
struct vec3
{
  dtype x, y, z;
 
  vec3(dtype x = 0, dtype y = 0, dtype z = 0) : x(x), y(y), z(z) {}

  vec3<dtype>& operator+(const vec3<dtype> &other) const
  {
    return vec3<dtype>(x + other.x, y + other.y, z + other.z);
  }

  vec3<dtype> operator-(const vec3<dtype> &other) const
  {
    return vec3<dtype>(x - other.x, y - other.y, z - other.z);
  }

  vec3<dtype> operator*(dtype scalar) const
  {
    return vec3<dtype>(x * scalar, y * scalar, z * scalar);
  }

  vec3<dtype> operator*(const vec3<dtype> &other) const
  {
    return vec3<dtype>(x * other.x, y * other.y, z * other.z);
  }
  
  vec3<dtype> operator/(dtype scalar) const
  {
    return vec3<dtype>(x / scalar, y / scalar, z / scalar);
  }
  vec3<dtype> operator/(vec3<dtype> &other) const
  {
    return vec3<dtype>(x / other.x, y / other.y, z / other.z);
  }

  dtype dot(const vec3<dtype> &other) const
  {
    return x * other.x + y * other.y + z * other.z;
  }

  vec3<dtype> cross(const vec3<dtype> &other) const
  {
    return vec3<dtype>(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
  }

  vec3<dtype> sqrt() const{
    return vec3<dtype>(std::sqrt(x), std::sqrt(y), std::sqrt(z));
  }

  vec3<dtype> pow(dtype power) const{
    return vec3<dtype>(std::pow(x, power), std::pow(y, power), std::pow(z, power));
  }
  
  dtype length() const
  {
    return std::sqrt(x * x + y * y + z * z);
  }

  vec3<dtype> normalize() const
  {
    return *this / length();
  }
  vec3<dtype> clamp(dtype low, dtype high){
    return vec3<dtype>(min(max(x, low), high), min(max(y, low), high), min(max(z, low), high));
  }
};

*/