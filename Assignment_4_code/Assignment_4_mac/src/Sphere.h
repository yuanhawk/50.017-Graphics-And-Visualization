#ifndef SPHERE_H
#define SPHERE_H

#include "Object3D.h"
#include "vecmath.h"
#include <cmath>

#include <iostream>
using namespace std;

class Sphere: public Object3D
{
public:
	Sphere()
    {
		//unit ball at the center
        this->center = vec3(0,0,0);
        this->radius = 1.0;
	}

	Sphere( vec3 center , float radius , Material* material ):Object3D(material)
    {
        this->center = center;
        this->radius = radius;
	}
	

	~Sphere(){}

    /// TODO: implement this function for ray-sphere intersection test.
	virtual bool intersect( const Ray& r , Hit& h , float tmin)
    {
        rayOrigin = r.getOrigin();
        o = rayOrigin - center;
        d = normalize(r.getDirection());

        float a, b, c, discriminant, t;

        a = abs(dot(d, d));
        b = 2 * dot(d, o);
        c = abs(dot(o, o)) - radius * radius;

        // D = b^2 - 4ac
        discriminant = b * b - 4 * a * c;

        if (discriminant >= 0) {
            // y = at^2 + bt + c, t = (-b +/- sqrt(b^2 - 4ac)) / (2a)
            t = (-b - sqrt(discriminant)) / 2 / a;
            if (t >= tmin && t < h.getT()) {
                return checkIntersect(t, h);
            }
            t = (-b + sqrt(discriminant)) / 2 / a;
            if (t >= tmin && t < h.getT()) {
                return checkIntersect(t, h);
            }
        }
        return false;   // remove this sentence in your implementation
	}

    bool checkIntersect(float t, Hit& h) {
        // o + td - c
        normal = normalize(rayOrigin + t * d - center);
        h.set(t, material, normal);
        return true;
    }

protected:
    vec3 center;
    float radius;

private:
    vec3 rayOrigin, o, d, normal;
};


#endif
