#pragma once

#include "matematical.hpp"

class Light{
public:
    Light(vec3& position);

    Light(vec3& position, vec3& diffuse, vec3& specular);

    ~Light();

    vec3 getPosition() const;

    vec3 getDiffuse(bool unitaryColor = false) const;

    vec3 getSpecular(bool unitaryColor = false) const;
private:
    vec3 position;
    vec3 diffuse;
    vec3 specular;
};