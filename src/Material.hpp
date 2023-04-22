#pragma once

#include "matematical.hpp"

class Material
{

public:
    Material();

    Material(const vec3 &diffuse, const vec3 &specular, double shiness);

    ~Material();

    void setDiffuse(const vec3 &diffuse);

    void setSpecular(const vec3 &specular);

    vec3 getDiffuse(bool unitaryColor = false) const;

    vec3 getSpecular(bool unitaryColor = false) const;

    double getShiness() const;

private:
    vec3 diffuse;

    vec3 specular;

    double shiness;
};