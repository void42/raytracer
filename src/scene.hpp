#ifndef KP_SCENE_H
#define KP_SCENE_H

#include <vector>
#include <cfloat>
#include "sphere.hpp"
#include "plane.hpp"
#include "rectangle.hpp"
#include "luminaire.hpp"
#include "color.hpp"
#include "vec3.hpp"

using std::vector;

class Scene{
    friend class Camera;

  private:
    vector<Primitive*> primitives;
    vector<Primitive*> luminaires;
    double scale;

  public:
    Scene();
    Scene(double scale);
    ~Scene();
    Sphere *create_sphere(Vec3 position, double radius, Material *material);
    Plane *create_plane(Vec3 n, Vec3 r0, Material *material);
    Primitive *create_luminaire(Primitive* primitive, Color intensity);
    Primitive *create_rectangle(Vec3 n, Vec3 c, double w, double h, Material *material);
};

#endif
