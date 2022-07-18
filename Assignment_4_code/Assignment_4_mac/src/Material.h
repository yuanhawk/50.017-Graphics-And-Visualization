#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include "vecmath.h"

#include "Ray.h"
#include "Hit.h"
#include "texture.hpp"


class Material
{
public:
	
    Material( const vec3& d_color ,const vec3& s_color=vec3(0,0,0), float s=0):
    diffuseColor( d_color),specularColor(s_color), shininess(s)
    {

    }

    virtual ~Material()
      {

      }

    virtual vec3 getDiffuseColor() const 
    { 
      return  diffuseColor;
    }
      
    /// TODO: Implement this function to compute diffuse and specular components of Phong lighting 
    vec3 Shade( const Ray& ray, const Hit& hit, const vec3& dirToLight, const vec3& lightColor ) 
    {
        vec3 n, diff, r, spec;
        float nl, rv;
        n = normalize(hit.getNormal());
        nl = dot(n, dirToLight);
        if (nl < 0) {
            nl = 0;
        }

        // check for texture validity
        if (t.valid()) {
            vec3 kd = t(hit.texCoord[0], hit.texCoord[1]);
            diff = nl * lightColor * kd;
            diffuseColor = kd;
        } else {
            diff = nl * diffuseColor * lightColor;
        }

        // r = 2(nl)n - l
        r = normalize((2 * nl * n) - dirToLight);
        rv = dot(r, normalize(-ray.getDirection()));

        if (rv < 0) {
            rv = 0;
        }

        spec = pow(rv, shininess) * lightColor * specularColor;
        return diff + spec;
    }

    void loadTexture(const char * filename)
    {
      t.load(filename);
    }

    Texture t;

 protected:
    vec3 diffuseColor;
    vec3 specularColor;
    float shininess;
};



#endif // MATERIAL_H
