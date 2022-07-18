#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vecmath.h"
#include "Object3D.h"

class Transform: public Object3D
{
public: 
    Transform(){}

    Transform( const mat4& m, Object3D* obj ):o(obj)
    {
      this->m = m;
      // this->o = obj;
    }

    ~Transform()
    {

    }
    /// TODO: implement this function so that the intersect function first transforms the ray into the object's local coordindate frame
    virtual bool intersect( const Ray& r , Hit& h , float tmin)
    {
        vec4 ori, d;
        vec3 oT, dT;

        ori = vec4 (r.getOrigin(), 1);
        d = vec4 (r.getDirection(), 0); // original
        oT = inverse(m) * ori;
        dT = inverse(m) * d; // transformation

        Ray ray (oT, dT);
        if (o->intersect(ray, h, tmin)) {
            vec4 n = vec4 (h.getNormal(), 0);
            vec3 nT = normalize(transpose(inverse(m)) * n);
            h.set(h.getT(), h.getMaterial(), nT);
            return true;
        }
        return false;   // remove this sentence in your implementation
    }

 protected:
    Object3D* o; //un-transformed object
    mat4 m;
};

#endif //TRANSFORM_H
