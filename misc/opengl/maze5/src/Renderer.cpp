#include <iostream>
#include <GL/glut.h>

#include "Renderer.h"

// TODO - this will eventually be removed when the eye coordinate
// variable is added to the main player object
float eyey;

// TODO - again, will probably also be removed. Or not, we'll
// see. Either way, if it becomes a member of the Renderer object,
// I'll just pull the values from that instead of just arbitrarilly
// setting the values up here
float transx = 0.0f;
float transy = 0.0f;
float transz = 0.0f;


void display()
{
  // TODO
  // Set up light
  /*Light main_light(GL_LIGHT0, lightx, lighty, lightz);
    main_light.set_up_light();*/

  // Set up camera

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // TODO
  // Eye coordinates will be a part of the player object. For now,
  // just put in some dummy value
  gluLookAt(0.0, 0.0, 0.0,
	    0.0, 0.0, -1.0,
	    0.0, 1.0, 0.0);

  // Begin drawing
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Set up surface material
  // TODO
  // I'll probably end up just moving this to main or some init data
  // function. This obviously doesn't belong in a render file
  //Surface surface1;
  //surface1.set_surface();
    
  glPushMatrix();
  glTranslatef(transx, 0.0, transz);
  // Draw bullet
  draw_bullet();

  // Draw the weapon
  draw_gun();

  // Draw the player
  // change the depth of the cube
  draw_player();
  //glPopMatrix();

  glPushMatrix();
  glRotatef(maze.get_rotatex(), 0.0, 1.0, 0.0);

  // Draw the maze
  maze.draw();

  // Draw the enemy robots
  draw_robots();//robot.draw();
  glPopMatrix();

  // Draw text
  draw_text(); 

  glPopMatrix();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
  // TODO
  /*switch(key)
    {
    case 'a': maze.set_rotatex(maze.get_rotatex() - 2); break;
    case 'd': maze.set_rotatex(maze.get_rotatex() + 2); break;
    case 'w': eyey += 0.1; break;
    case 's': eyey -= 0.1; break;
    }*/
  display();
}


Renderer::Renderer() {
}

void Renderer::setupDisplay(int* argc, char** argv, int width, int height)
{
  glutInit(argc, argv);    
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(width, height);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutCreateWindow("test");

  // glEnable(GL_LIGHTING); // Enable lighting in general
  // ^Creates shadows and whatnot
  //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  //glEnable(GL_COLOR_MATERIAL);
  // (There are 8 light sources.)    
  //glShadeModel(GL_SMOOTH); // Third run: GL_FLAT
  glEnable(GL_DEPTH_TEST); // for hidden surface removal
  //glEnable(GL_NORMALIZE);  // normalize vectors for proper shading

  //glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(specialkeyboard);
  glutIdleFunc(move_robots);
  glutMouseFunc(mouse);
}
