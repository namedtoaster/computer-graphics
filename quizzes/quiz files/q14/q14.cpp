#include <GL/glut.h>
#include <cmath>

float deg = 3.14159/180;

float eyex;
float eyey;
float eyez;

float first[3] = {2.5,3,0};
float second[3] = {-8,3,0};
float third[3] = {2.5,-3,0};

GLUquadricObj * p = gluNewQuadric();

void push(void)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
}

void pop(void)
{
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void init()
{
    eyex = 0.0f;
    eyey = 0.0f;
    eyez = 1.0f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, // -10 <= x <= 10
            -10.0, 10.0, // -10 <= y <= 10
            -10.0, 10.0); // -10 <= z <= 10

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, // eye position x,y,z
              0.0, 0.0, 1.0, // eye direction x,y,z
              0.0, 1.0, 0.0);// eye up direction x,y,z

    glViewport(0, 0, 400, 400);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);

    gluQuadricDrawStyle(p, GLU_LINE);

}

void display()
{

    float base_radius = 1.0f;
    float top_radius = 1.0f;
    float height = 4.0f;
    int slice_per_ring = 20;
    int rings = 20;
    
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, // eye position x,y,z
              0.0, 0.0, 0.0, // eye direction x,y,z
              0.0, 1.0, 0.0);// eye up direction x,y,z

// first cylinder
    glColor3f(255.0f, 0.0f, 0.0f);
    push();
    glTranslatef(first[0], first[1], first[2]);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    glTranslatef(3, 0, 0);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    glTranslatef(3, 0, 0);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    pop();

// second cylinder
    glColor3f(0.0f, 255.0f, 0.0f);
    push();
    glTranslatef(second[0], second[1], second[2]);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    glTranslatef(3, 0, 0);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    glTranslatef(3, 0, 0);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    pop();

// third cylinder
    glColor3f(0.0f, 0.0f, 255.0f);
    push();
    glTranslatef(third[0], third[1], third[2]);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    glTranslatef(3, 0, 0);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    glTranslatef(3, 0, 0);
    gluCylinder(p, base_radius, top_radius, height, slice_per_ring, rings);
    pop();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w': first[0] -= 0.1; break;
        case 'q': first[0] += 0.1; break;
            
        case 'e': second[1] += 0.1; break;
        case 'r': second[1] -= 0.1; break;

        case 'y': third[2] -= 0.1; break;
        case 't': third[2] += 0.1; break;

        case 'a':
            eyex = cos(deg) * eyex + sin(deg) * eyez;
            eyey = eyey;
            eyez = -sin(deg) * eyex + cos(deg) * eyez;
            break;
        case 'd':
            eyex = cos(-deg) * eyex + sin(-deg) * eyez;
            eyey = eyey;
            eyez = -sin(-deg) * eyex + cos(-deg) * eyez;
            break;
            
        case '1':
            eyex = eyex;
            eyey = cos(deg) * eyey - sin(deg) * eyez;
            eyez = sin(deg) * eyey +  cos(deg) * eyez;
            break;
        case '2':
            eyex = eyex;
            eyey = cos(-deg) * eyey - sin(-deg) * eyez;
            eyez = sin(-deg) * eyey +  cos(-deg) * eyez;
            break;

        case 'z':
            eyex = cos(deg) * eyex + -sin(deg) * eyey;
            eyey = sin(deg) * eyex + cos(deg) * eyey;
            eyez = eyez;
            break;
        case 'x':
            eyex = cos(-deg) * eyex + -sin(-deg) * eyey;
            eyey = sin(-deg) * eyex + cos(-deg) * eyey;
            eyez = eyez;
            break;
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

    gluDeleteQuadric(p);

    return 0;
}




