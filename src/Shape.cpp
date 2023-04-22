#include "Shape.hpp"

Shape::Shape()
{
}

Material Shape::getMaterial() const
{
    return this->material;
}

void Shape::setMaterial(const Material &material)
{
    this->material = material;
}
