#ifndef KP_PRIMITIVE_H
#define KP_PRIMITIVE_H

#include "material.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include "color.hpp"
#include <cstdlib>
#include <vector>
using std::vector;

struct Intersection{
    Primitive *primitive;
    int result;
    double t;
    Vec3 normal;
    Vec3 position;
    Intersection() : primitive(NULL), result(0){}
    Intersection(Primitive *e, double t_, Vec3 n, Vec3 p, int r){
        primitive = e;
        result = r;
        t = t_;
        normal = n;
        position = p;
    }
};

class Primitive{
    static int counter;
    int key;

  protected:
    const Material *material;
    Color m_exitance;
    Vec3 velocity;

  public:
    Primitive();
    Primitive(Material *m);
    virtual Intersection intersect(const Ray& ray) = 0;
    virtual const Material *get_material() const;
    virtual Vec3 get_position() const = 0;
    int get_key() const;
    void set_luminaire(bool v);
    void set_exitance(Color e);
    bool is_luminaire() const;
    Color get_exitance() const;
    virtual vector<Vec3> *get_samples() = 0;
    virtual void tick(double time_step);
    void set_velocity(Vec3 v);
};

#endif
