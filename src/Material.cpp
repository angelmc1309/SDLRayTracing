#include "Material.hpp"

Material::Material()
{
    this->diffuse = vec3(145., 181., 0.);
    this->specular = vec3(255., 255., 255.);

    this->shiness = 1.;
}

Material::Material(const vec3 &diffuse, const vec3 &specular, double shiness)
{
    this->diffuse = diffuse;
    this->specular = specular;
    this->shiness = shiness;
}

Material::~Material()
{
}

void Material::setDiffuse(const vec3 &diffuse)
{
    this->diffuse = diffuse;
}

void Material::setSpecular(const vec3 &specular)
{
    this->specular = specular;
}

vec3 Material::getDiffuse(bool unitaryColor) const
{
    if(unitaryColor){
        return this->diffuse / 255.;
    }
    return this->diffuse;
}

vec3 Material::getSpecular(bool unitaryColor) const
{
    if(unitaryColor){
        return this->specular / 255.;
    }
    return this->specular;
}

double Material::getShiness() const
{
    return this->shiness;
}
