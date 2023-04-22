#include "Scene.hpp"

Scene::Scene()
{
  Shape *sphereGreen = new Sphere(vec3(0., 0., -7.), 1.);

  Material mGreen = Material(vec3(0., 255., 0.), vec3(255., 255., 255.), 5.);

  sphereGreen->setMaterial(mGreen);

  Shape *sphereRed = new Sphere(vec3(-3., 0., -7.), 1.);

  Material mRed = Material(vec3(255., 0., 0.), vec3(255., 255., 255.), 5.);

  sphereRed->setMaterial(mRed);

  Shape *sphereBlue = new Sphere(vec3(3., 0., -7.), 1.);

  Material mBlue = Material(vec3(0., 0., 255.), vec3(255., 255., 255.), 5.);

  sphereBlue->setMaterial(mBlue);

  Shape *sphereFloor = new Sphere(vec3(0., -500., -20.), 498.);

  Material mFloor = Material(vec3(127., 127., 127.), vec3(255., 255., 255.), 5.);

  sphereFloor->setMaterial(mFloor);

  Shape *sphereBackground = new Sphere(vec3(0., 0., -1000.), 800.);

  Material mBackground = Material(vec3(0., 0., 0.), vec3(0., 0., 0.), 5.);

  sphereBackground->setMaterial(mBackground);

  Light *l = new Light(vec3(0., 5., 2.), vec3(255., 255., 255.), vec3(255., 255., 255.));

  this->shapes.push_back(sphereGreen);

  this->shapes.push_back(sphereRed);

  this->shapes.push_back(sphereBlue);

  this->shapes.push_back(sphereFloor);

  this->shapes.push_back(sphereBackground);

  this->lights.push_back(l);
}

Scene::~Scene()
{
  int i;

  for (i = 0; i < shapes.size(); i++)
  {
    free(shapes.at(i));
  }
  for (i = 0; i < lights.size(); i++)
  {
    free(lights.at(i));
  }
}

void Scene::render(const SDL_manager &sdl_manager)
{
  int i, j, k;
  {
    for (i = 0; i < WIDTH; i++)
    {
      for (j = 0; j < HEIGHT; j++)
      {
        vec3 intersection_point;
        ray r;

        // Compute the ray from the camera to the pixel
        camera.computeRay(i, j, r);

        // Check if the ray intersects any of the shapes in the scene
        Shape *closestShape = NULL;
        double closestDistance = 1e8;
        vec3 closestIntersectionPoint;

        for (k = 0; k < shapes.size(); k++)
        {
          // find shape that intersects with the ray first
          if (shapes.at(k)->hit(r, intersection_point))
          {
            double distance = (intersection_point - r.origin).length();
            if (distance < closestDistance)
            {
              closestDistance = distance;
              closestShape = shapes.at(k);
              closestIntersectionPoint = intersection_point;
            }
          }
        }

        if (closestShape)
        {
          vec3 color = vec3(0., 0., 0.);

          this->computeColor(r, closestIntersectionPoint, closestShape, color);

          sdl_manager.draw_point(i, j, (int)color.x, (int)color.y, (int)color.z, 255);
        }
      }
    }
  }
}

void Scene::computeColor(const ray &r, const vec3 &interPoint, Shape *shape, vec3 &color)
{
  color = blingPhong(r, interPoint, shape);
  color = color.clamp(0., 1.);
  color = color * 255.;
  // std::cout << color.x << " " << color.y << " " << color.z << " " << std::endl;
}

vec3 Scene::blingPhong(const ray &r, const vec3 &interPoint, Shape *shape)
{
  int i;

  vec3 iterColor = vec3(0., 0., 0.);

  for (i = 0; i < lights.size(); i++)
  {
    Light *light = lights.at(i);

    vec3 difuse;

    vec3 specular;

    vec3 N = shape->normal(interPoint).normalize();

    vec3 L = (light->getPosition() - interPoint).normalize();

    vec3 V = (r.origin - interPoint).normalize();

    // vec3 H = ((L + V) / (((L + V) * (L + V)).sqrt())).normalize();

    vec3 H = (L + V).normalize();

    double LN = L.dot(N);
    if (LN < 0.)
      LN = 0.;

    double HN = H.dot(N);
    if (HN < 0.)
      HN = 0.;

    // DIFUSE COLOR
    difuse = (shape->getMaterial().getDiffuse(true)) * (light->getDiffuse(true)) * LN;

    // SPECULAR COLOR
    specular = (shape->getMaterial().getSpecular(true)) * (light->getSpecular(true)) * pow(HN, shape->getMaterial().getShiness());

    /*
    // ATENUACIO
    double d = distance(interPoint, light->position);
    difuseAndSpecular *= 1.0f / (light->atenuacio.x * pow(d, 2.0) + light->atenuacio.y * d + light->atenuacio.z);
    iterColor += difuseAndSpecular;

    // AMBIENTAL COLOR(local)
    // float oclusion = 1.0f - ambientalOclusion(info.p, info.normal);
    iterColor += (light->ambiental) * info.mat_ptr->ambiental;
    */
    iterColor = difuse + specular;
  }
  return iterColor;
}

/*
vec3 Scene::BlinnPhong(HitInfo &info, const Ray &raig) {

    vec3 interPoint = info.p;
    vec3 L, N, H;
    vec3 color(0.0,0.0,0.0);
    float epsilon = 0.01f;
    shared_ptr<Light> light;

    if (info.mat_ptr->hasTexture()) {
        info.textureCoords = this->projectionFunction(info.p);
    }

    for (uint i = 0; i < this->listLights.size(); i++) {
        vec3 iterColor(0,0,0);
        vec3 factorAtenuacio(0,0,0);
        light = this->listLights.at(i);

        L = normalize(light->position - interPoint);

        //SHADOW CHECK
        Ray rayToLight(info.p,L);
        HitInfo infoShadowRay;
        while (hit(rayToLight,epsilon,distance(rayToLight.origin,light->position),infoShadowRay)) {
            factorAtenuacio.x = (1.0f - infoShadowRay.mat_ptr->transparent.x)
                    + infoShadowRay.mat_ptr->transparent.x*factorAtenuacio.x;
            factorAtenuacio.y = (1.0f - infoShadowRay.mat_ptr->transparent.y)
                    + infoShadowRay.mat_ptr->transparent.y*factorAtenuacio.y;
            factorAtenuacio.z = (1.0f - infoShadowRay.mat_ptr->transparent.z)
                    + infoShadowRay.mat_ptr->transparent.z*factorAtenuacio.z;
            rayToLight.origin = infoShadowRay.p;
            if(factorAtenuacio.x >= 1.0f && factorAtenuacio.y >= 1.0f
                    && factorAtenuacio.x >= 1.0f){
                break;
            }
        }
        factorAtenuacio= glm::clamp(factorAtenuacio,0.0,1.0);
        if(factorAtenuacio.x >= 1.0f && factorAtenuacio.y >= 1.0f
                && factorAtenuacio.x >= 1.0f){
            continue;;
        }

        //DIFUSE COLOR
        vec3 difuseAndSpecular(0.0,0.0,0.0);
        N = normalize(info.normal);
        float LN = glm::max(dot(L,N),0.0f);
        difuseAndSpecular += LN * info.mat_ptr->getDiffuse(info.textureCoords) * light->difusa;

        //SPECULAR COLOR
        vec3 V = normalize(raig.origin-info.p);
        H = normalize((L + V) / (sqrt((L.x + V.x)*(L.x + V.x)) +
                                 sqrt((L.y + V.y)*(L.y + V.y)) +
                                 sqrt((L.z + V.z)*(L.z + V.z))));
        difuseAndSpecular += pow(glm::max(dot(N, H), 0.0f), info.mat_ptr->shiness) * info.mat_ptr->specular * light->specular;

        //ATENUACIO
        double d = distance(interPoint, light->position);
        difuseAndSpecular *= 1.0f / (light->atenuacio.x * pow(d, 2.0) + light->atenuacio.y * d + light->atenuacio.z);
        iterColor += difuseAndSpecular;

        //AMBIENTAL COLOR(local)
        //float oclusion = 1.0f - ambientalOclusion(info.p, info.normal);
        iterColor += (light->ambiental) * info.mat_ptr->ambiental;
        color += iterColor * (vec3(1,1,1)-factorAtenuacio);
    }

    // ADD GLOBAL LIGHT
    //float factorAmbientalOclusion = ambientalOclusion(info.p, info.normal);
    color += *(this->global) * info.mat_ptr->ambiental;

    return color;
}

*/
