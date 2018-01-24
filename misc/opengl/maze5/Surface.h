#ifndef SURFACE_H
#define SURFACE_H

#include <GL/glut.h>

class Surface {
public:
    Surface(float a1 = 0.1, float a2 = 0.1, float a3 = 0.1, float a4 = 0.0,
            float d1 = 1.0, float d2 = 1.0, float d3 = 1.0, float d4 = 1.0,
            float s1 = 1.0, float s2 = 1.0, float s3 = 1.0, float s4 = 1.0,
            float sh = 50.0);
    
    void set_surface();
private:
    // Set up surface material
    
    GLfloat mat_ambient[4];
    GLfloat mat_diffuse[4];
    GLfloat mat_specular[4];
    GLfloat mat_shininess[1];
};

#endif
