#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object3D.h"
#include "vecmath.h"
#include <cmath>
#include <iostream>

using namespace std;

class Triangle: public Object3D
{
public:
	Triangle();
    ///@param a b c are three vertex positions of the triangle
	Triangle( const vec3& a, const vec3& b, const vec3& c, Material* m):Object3D(m)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        hasTex = false;
	}

    /// TODO: implement this function for ray-triangle intersection test.
	virtual bool intersect( const Ray& ray,  Hit& hit , float tmin)
    {
        // o + td = alpha * A = beta * B + gamma * C
        vec3 o, d;
        o = ray.getOrigin();
        d = ray.getDirection();

        mat3x3 M_1, M_2, M_3, M_4;

        // M_1 = (a - b, a - c, d)
        M_1 = mat3x3 (a.x - b.x, a.x - c.x, d.x,
                  a.y - b.y, a.y - c.y, d.y,
                  a.z - b.z, a.z - c.z, d.z);

        // M_2 = (a - o, a - c, d)
        M_2 = mat3x3 (a.x - o.x, a.x - c.x, d.x,
                    a.y - o.y, a.y - c.y, d.y,
                    a.z - o.z, a.z - c.z, d.z);

        // M_3 = (a - b, a - o, d)
        M_3 = mat3x3 (a.x - b.x, a.x - o.x, d.x,
                    a.y - b.y, a.y - o.y, d.y,
                    a.z - b.z, a.z - o.z, d.z);

        // M_4 = (a - b, a - c, a - o)
        M_4 = mat3x3 (a.x - b.x, a.x - c.x, a.x - o.x,
                      a.y - b.y, a.y - c.y, a.y - o.y,
                      a.z - b.z, a.z - c.z, a.z - o.z);

        float detA, beta, gamma, t, alpha;
        detA = determinant(M_1);
        beta = determinant(M_2) / detA;
        gamma = determinant(M_3) / detA;
        t = determinant(M_4) / detA;
        alpha = 1 - beta - gamma;

        if (beta < 0 || gamma < 0 || alpha < 0) return false;

        if (t >= tmin && t < hit.getT()) {
            // Barycentric coordinates
            // x = alpha * A = beta * B + gamma * C
            // alpha + beta + gamma = 1; alpha, beta, gamma >= 0
            vec3 n = normalize(alpha * normals[0] + beta * normals[1] + gamma * normals[2]);
            hit.set(t, material, n);
            vec2 texture = alpha * texCoords[0] + beta * texCoords[1] + gamma * texCoords[2];
            hit.setTexCoord(texture);
            return true;
        }
        return false;   // remove this sentence in your implementation
    }
    
	bool hasTex;
	vec3 normals[3];
	vec2 texCoords[3];
    
protected:
    vec3 a;
    vec3 b;
    vec3 c;

};

#endif //TRIANGLE_H
