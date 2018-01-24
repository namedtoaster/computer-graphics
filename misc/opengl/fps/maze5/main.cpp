#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stack>
#include <vector>
#include <cstring>

#include "Objects.h"
#include "Room.h"
#include "Constants.h"
//#include "Maze.h"
#include "Surface.h"
//#include "Model.h"
#include "Player.h"
#include "Robot.h"
//#include "Weapon.h"
#include "Bullet.h"

using namespace std;

float eyex;
float eyey;
float eyez;

float transz = 0.0f;
float transx = 0.0f;
float transy = 0.0f;
float adj = 0.0f;
float opp = 3.4f;
float hyp = 3.4f;
float angle = 0.0f;

int width = 600;
int height = 600;

void display();

void init()
{
    // See the random number generator
    srand(time(NULL));

    // Generate the maze
    maze.generate_maze();

    // Place all of the robots into the maze
    place_robots();

    eyex = 0;
    eyey = 0;
    eyez = 0;
    
    lightx = -64.0;
    lighty = 20.5f;
    lightz = -16.0f;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float fovy = 90.0f; 
    float aspect = 1.0f;  
    float zNear = 0.1f; 
    float zFar = 500.0f;  
    gluPerspective(fovy, aspect, zNear, zFar);
    
    glMatrixMode(GL_MODELVIEW);
    /*glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 
              0.0, 0.0, -1.0, 
              0.0, 1.0, 0.0);  */  

    glViewport(0, 0, width, height);
    glClearColor(0.677f, 0.754f, 0.854f, 0.0f);
}

void display()
{    
    // Set up light
    Light main_light(GL_LIGHT0, lightx, lighty, lightz);
    main_light.set_up_light();

    // Set up camera

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, eyey, 0.0,
              0.0, 0.0, -1.0,
              0.0, 1.0, 0.0);

    // Begin drawing
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up surface material

    Surface surface1;
    surface1.set_surface();
    
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
    switch(key)
    {
        case 'a': maze.set_rotatex(maze.get_rotatex() - 2); break;
        case 'd': maze.set_rotatex(maze.get_rotatex() + 2); break;
    }
    display();
}

void specialkeyboard(int key, int x, int y)
{
    switch (key)
    {
		case GLUT_KEY_UP: if ((-player.get_tz() + player.get_depth() / 2) < (maze.get_ty(player.get_row(), player.get_col())) || (!f))
				  {
					  maze.set_ty(-0.1f); bullet.set_tz(bullet.get_tz() - 0.1f); player.set_tz(player.get_tz() - 0.1f);
				  }break;
        case GLUT_KEY_DOWN: if ((-player.get_tz() - player.get_depth() / 2) > (maze.get_ty(player.get_row(), player.get_col()) - (CELL_H) + 1.34 / 2) || (!b))
				  {
					  maze.set_ty(0.1f); bullet.set_tz(bullet.get_tz() + 0.1f); player.set_tz(player.get_tz() + 0.1f);
				  }break;
        case GLUT_KEY_RIGHT: if ((player.get_tx() + player.get_width() / 2) < (maze.get_tx(player.get_row(), player.get_col())) || (!r))
				  {
					  maze.set_tx(-0.1f); bullet.set_tx(bullet.get_tx() - 0.1f); player.set_tx(player.get_tx() + 0.1f);
				  }break;
        case GLUT_KEY_LEFT: if ((player.get_tx() - player.get_width() / 2) > (maze.get_tx(player.get_row(), player.get_col()) - (CELL_W)) || (!l))
				  {
					  maze.set_tx(0.1f); bullet.set_tx(bullet.get_tx() + 0.1f); player.set_tx(player.get_tx() - 0.1f);
				  }break;
    }
    //move_robots();
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
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
                           // (There are 8 light sources.)    
    glShadeModel(GL_SMOOTH); // Third run: GL_FLAT
    glEnable(GL_DEPTH_TEST); // for hidden surface removal
    glEnable(GL_NORMALIZE);  // normalize vectors for proper shading

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialkeyboard);
    glutIdleFunc(move_robots);
	glutMouseFunc(mouse);

    init();
    glutMainLoop();
  
    return 0;
}
