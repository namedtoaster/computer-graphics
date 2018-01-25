#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>

/*float lightx = -37.0;
float lighty = 13.5;
float lightz = -7.0;*/

class Light {
public:
    Light(GLfloat l_src = GL_LIGHT0,
          float lx = 0.0, float ly = 0.0, float lz = 3.0, float lp4 = 1.0,
          GLfloat d1 = 1.0, GLfloat d2 = 0, GLfloat d3 = 1.0,
          float cangle = 90.0, float spexp = 5.0,
          GLfloat la1 = 0.7, GLfloat la2 = 0.7, GLfloat la3 = 0.7, GLfloat la4 = 1.0,
          GLfloat ld1 = 1.0, GLfloat ld2 = 1.0, GLfloat ld3 = 1.0, GLfloat ld4 = 1.0,
          GLfloat ls1 = 1.0, GLfloat ls2 = 1.0, GLfloat ls3 = 1.0, GLfloat ls4 = 1.0,
          float sc1 = 1.0, float sc2 = 1.0, float sc3 = 0.0,
          float sc_r = 0.5, float sc_rgs = 30);
    void set_up_light();
    void draw_source(bool = true);
    float & set_sc_r(const float value);
    float & set_sc_rgs(const float value);
private:
    GLfloat light_source;
    
    float lightx, lighty, lightz;

    // Spotlight
    // Note that that the last value of light_position is 1.0. This means
    // that the light is a "local" light source. The other 3 values
    // specifies the position of the light source.
    // (Recall: If the last value is 0.0, then the light source is at
    // infinity - i.e.infintely far away and the first 3 numbers represent
    // the direction of all ligth rays from infinitely far away.
    
    GLfloat light_position[4];
    GLfloat dir[3];

    float cutoff_angle;

    // The local light source is at (lightx, lighty, lightz) and the
    // light rays are restricted so that the angle made by the light rays
    // to the direction vector <1.0, 0, 1.0> is at most the cutoff_angle.
    //
    // Second run: change the cutoff_angle to 45, 180, etc.
    // Third run: change the direction of the spot light from {1.0, 0, 1.0}
    //            to {1.0, 0, 0}, {-1.0, 0, 0}, etc.
    
    float spot_exp;

    GLfloat light_ambient[4];
    GLfloat light_diffuse[4];
    GLfloat light_specular[4];

    float source_color[3];

    float sc_radius;
    float sc_rings;
};

#endif
