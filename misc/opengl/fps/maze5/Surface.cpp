#include "Surface.h"

Surface::Surface(float a1, float a2, float a3, float a4,
            float d1, float d2, float d3, float d4,
            float s1, float s2, float s3, float s4,
            float sh)
{
    mat_ambient[0] = a1; mat_ambient[1] = a2; mat_ambient[2] = a3; mat_ambient[3] = a4;
    mat_diffuse[0] = d1; mat_diffuse[1] = d2; mat_diffuse[2] = d3; mat_diffuse[3] = d4;
    mat_specular[0] = s1; mat_specular[1] = s2; mat_specular[2] = s3; mat_specular[3] = s4;
    mat_shininess[0] = sh;
}

void Surface::set_surface()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_shininess);
}
