#include <GL/glut.h>
#include <cmath>
#include <iostream>

float eyex;
float eyey;
float eyez;
float deg2rad = 3.14159/180;
float angle = 1 * deg2rad;
void init()
{
    eyex = 0.0f;
    eyey = 0.0f;
    eyez = 1.0f;
    // Set view volume for orthographic (parallel) projection
    // (Note: lengths of line segment stays the same, i.e.,
    // lines further away do not appear shorted, i.e., no
    // sense of perspective. This is the case for architectural
    // drawing, engineering CAD drawing, 2D games, isometric
    // games, etc.
    //
    // The 6 values passed to glOrtho() is the clipping volumn,
    // i.e., only objects in this volume are seen.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, // -4 <= x <= 4
            -4.0, 4.0, // -4 <= y <= 4
            -4.0, 4.0); // -4 <= z <= 4
    // set camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, // eye position x,y,z
              0.0, 0.0, 3.0, // eye direction x,y,z
              0.0, 1.0, 0.0);// eye up direction x,y,z

    glViewport(0, 0, 400, 400);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, // eye position x,y,z
              0.0, 0.0, 0.0, // eye direction x,y,z
              0.0, 1.0, 0.0);// eye up direction x,y,z
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    glutWireTeapot(1.0f);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a':
            eyex = cos(1*deg2rad) * eyex + sin(1*deg2rad) * eyez;
            eyey = eyey;
            eyez = -sin(1*deg2rad) * eyex + cos(1*deg2rad) * eyez;
            break; // left
        case 'd': // not working right
            eyex = cos(-1*deg2rad) * eyex + sin(-1*deg2rad) * eyez;
            eyey = eyey;
            eyez = -sin(-1*deg2rad) * eyex + cos(-1*deg2rad) * eyez;
            break; // right
            
        case 'w':
            eyex = eyex;
            eyey = cos(1*deg2rad) * eyey - sin(1*deg2rad) * eyez;
            eyez = sin(1*deg2rad) * eyey +  cos(1*deg2rad) * eyez;
            break; // up
        case 's': // not working right
            eyex = eyex;
            eyey = cos(-1*deg2rad) * eyey - sin(-1*deg2rad) * eyez;
            eyez = sin(-1*deg2rad) * eyey +  cos(-1*deg2rad) * eyez;
            break; // down

        case 'q':
            eyex = cos(1*deg2rad) * eyex + -sin(1*deg2rad) * eyey;
            eyey = sin(1*deg2rad) * eyex + cos(1*deg2rad) * eyey;
            eyez = eyez;
            break; // z
        case 'e':
            eyex = cos(-1*deg2rad) * eyex + -sin(-1*deg2rad) * eyey;
            eyey = sin(-1*deg2rad) * eyex + cos(-1*deg2rad) * eyey;
            eyez = eyez;
            break; // z
    }
    display();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("test");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
