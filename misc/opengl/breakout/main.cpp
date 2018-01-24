#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <cstring>

#include "Model.h"
#include "Surface.h"
#include "Light.h"
#include "Objects.h"
#include "Constants.h"
#include "Prototypes.h"

using namespace std;

const float text_color[] = {0.0, 0.0, 1.0};

void init()
{    
    eyex = 1.49012e-09f;
    eyey = 19.0f;
    eyez = 18.0f;
    
    lightx = -64.0;
    lighty = 20.5f;
    lightz = -16.0f;

    sunx = -506;
    suny = -36.5;
    sunz = -116;
    
    glMatrixMode(GL_PROJECTION);
	glPointSize(8.0f);
    glLoadIdentity(); 
    gluPerspective(fovy, aspect, zNear, zFar);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 
              0.0, 0.0, -1.0, 
              0.0, 1.0, 0.0);    

    glViewport(0, 0, width, height);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void display()
{
    // Set up light

    Light house_light(GL_LIGHT0, lightx, lighty, lightz);
    house_light.set_up_light();

    // Set up camera
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez,
              0.0, 0.25, 0.0,
              0.0, 1.0, 0.0);    

    // Begin drawing
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up surface material

    Surface surface1;
    surface1.set_surface();

    // Set light source radius
    house_light.set_sc_r(10);
    // Draw light source
    //house_light.draw_source(true);

	glBegin(GL_POINTS);

	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x, 0, y);
	glEnd();
	glPopMatrix();
    draw();
   
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a': eyex -= 0.1; break;
        case 'd': eyex += 0.1; break;
        case 'w': eyey += 0.1; break;
        case 's': eyey -= 0.1; break;
        case '1': eyez += 0.1; break;
        case '2': eyez -= 0.1; break;

        // Controls the position of light source
        case 'o': lightx -= 1.0; break;
        case 'p': lightx += 1.0; break;
        case 'k': lighty -= 1.0; break;
        case 'l': lighty += 1.0; break;
        case 'n': lightz -= 1.0; break;
        case 'm': lightz += 1.0; break;
    }
    display();
}

void specialkeyboard(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT: paddlex -= 0.5; break;
        case GLUT_KEY_RIGHT: paddlex += 0.5; break;
	}

	display();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);    
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("test");

    glEnable(GL_LIGHTING); // Enable lighting in general
    //glEnable(GL_LIGHT0);   // Enable light source GL_LIGHT0
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
                           // (There are 8 light sources.)    
    glShadeModel(GL_SMOOTH); // Third run: GL_FLAT
    glEnable(GL_DEPTH_TEST); // for hidden surface removal
    glEnable(GL_NORMALIZE);  // normalize vectors for proper shading
	glEnable(GL_POINT_SMOOTH);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeyboard);
	glutIdleFunc(idle);

    init();
    glutMainLoop();
  
    return 0;
}
