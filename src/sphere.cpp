#include "sphere.hpp"

Sphere::Sphere(){}

Sphere::Sphere(Vec3 center, double radius, Material *material) : Primitive(){
    this->center = center;
    this->radius = radius;
    this->material = material;
} 

Intersection Sphere::intersect(const Ray& ray){
    Vec3 p = ray.origin;
    Vec3 v = ray.direction;
    
    Vec3 d = p-center; // p-c
    double a = v*v;
    double b = (v*d); // v*(p-c)
    double c = d*d - radius*radius; // (p-c)*(p-c) - r^2

    double det = b*b - a*c;

    // If there is no solution ray does not interesect sphere
    if(det < 0){
        return Intersection(this, DBL_MAX, d.normalize(), Vec3(), 0);
    }

    double t1 = (-b-sqrt(det))/a;
    double t2 = (-b+sqrt(det))/a;

    if(t2 > 0){
        if(t1 < 0){
            Vec3 pos = p+t2*v;
            Vec3 normal = (pos - center).normalize();
            return Intersection(this, t2, normal, pos, -1);
        }else{
            Vec3 pos = p+t1*v;
            Vec3 normal = (pos - center).normalize();
            return Intersection(this, t1, normal, pos, 1);
        }
    }else{
        return Intersection(this, t1, d.normalize(), p+t1*v, 0);
    }
}