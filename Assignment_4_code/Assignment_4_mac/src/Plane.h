#ifndef PLANE_H
#define PLANE_H

#include "Object3D.h"
#include "vecmath.h"
#include <cmath>
using namespace std;


class Plane: public Object3D
{
public:
	Plane(){}

	Plane( const vec3& normal , float d , Material* m):Object3D(m)
    {
        this->normal = normalize(normal);
        this->d = -d;
	}

	~Plane(){}

    /// TODO: implement this function for ray-plane intersection test.
    // With reference to: https://www.cs.princeton.edu/courses/archive/fall00/cs426/lectures/raycast/sld017.htm
	virtual bool intersect( const Ray& r , Hit& h , float tmin)
    {
        float normO, normD, t;

        normO = dot(normal, r.getOrigin());
        normD = dot(normal, normalize(r.getDirection()));

        if (normD == 0) return false; // orthogonal rays

        t = -(normO + d) / normD;
        if (t > tmin && t < h.getT()) {
            h.set(t, material, normal);
            return true;
        }
        return false;   // remove this sentence in your implementation
	}

protected:
    vec3 normal;
    float d;

    
};
#endif //PLANE_H
		

