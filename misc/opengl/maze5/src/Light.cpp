#include <iostream>

#include "Light.h"

using namespace std;

Light::Light(GLfloat l_src, float lx, float ly, float lz, float lp4,
             GLfloat d1, GLfloat d2, GLfloat d3,
             float cangle, float spexp,
             GLfloat la1, GLfloat la2, GLfloat la3, GLfloat la4,
             GLfloat ld1, GLfloat ld2, GLfloat ld3, GLfloat ld4,
             GLfloat ls1, GLfloat ls2, GLfloat ls3, GLfloat ls4,
             float sc1, float sc2, float sc3,
             float sc_r, float sc_rgs) : light_source(l_src),
                                         lightx(lx), lighty(ly), lightz(lz),
                                         cutoff_angle(cangle), spot_exp(spexp),
                                         sc_radius(sc_r), sc_rings(sc_rgs)
    {
        light_position[0] = lx; light_position[1] = ly; light_position[2] = lz; light_position[3] = lp4;

        dir[0] = d1; dir[1] = d2; dir[2] = d3;

        light_ambient[0] = la1; light_ambient[1] = la2; light_ambient[2] = la3; light_ambient[3] = la4;

        light_diffuse[0] = ld1; light_diffuse[1] = ld2; light_diffuse[2] = ld3; light_diffuse[3] = ld4;

        light_specular[0] = ls1; light_specular[1] = ls2; light_specular[2] = ls3; light_specular[3] = ls4;

        source_color[0] = sc1; source_color[1] = sc2; source_color[2] = sc3;
    }

void Light::set_up_light()
{
    glPushMatrix();

    // Enable current light source
    glEnable(light_source);
    
    glLightf(light_source, GL_SPOT_CUTOFF, cutoff_angle);
    glLightf(light_source, GL_SPOT_EXPONENT, spot_exp);
    glLightfv(light_source, GL_SPOT_DIRECTION, dir);

    glLightfv(light_source, GL_POSITION, light_position);
    glLightfv(light_source, GL_AMBIENT, light_ambient);
    glLightfv(light_source, GL_DIFFUSE, light_diffuse);
    glLightfv(light_source, GL_SPECULAR, light_specular);
    glPopMatrix();
}

void Light::draw_source(bool truth)
{
    if (truth)
    {
        glColor3fv(source_color);
        glPushMatrix();
        glTranslatef(lightx, lighty, lightz);
        glutSolidSphere(sc_radius, sc_rings, sc_rings);
        glPopMatrix();
    }
}

float & Light::set_sc_r(const float value)
{
    sc_radius = value;

    return sc_radius;
}

float & Light::set_sc_rgs(const float value)
{
    sc_rings = value;

    return sc_rings;
}
