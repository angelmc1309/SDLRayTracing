#include "Light.hpp"

Light::Light(vec3 &position)
{
    this->position = position;
    this->diffuse = vec3(255., 255., 255.);
    this->specular = vec3(255., 255., 255.);
}

Light::Light(vec3 &position, vec3 &diffuse, vec3 &specular)
{
    this->position = position;
    this->diffuse = diffuse;
    this->specular = specular;
}

Light::~Light()
{
}

vec3 Light::getPosition() const
{
    return this->position;
}

vec3 Light::getDiffuse(bool unitaryColor) const
{
    if(unitaryColor){
        return this->diffuse / 255.;
    }
    return this->diffuse;
}

vec3 Light::getSpecular(bool unitaryColor) const
{
    if(unitaryColor){
        return this->specular / 255.;
    }
    return this->specular;
}
