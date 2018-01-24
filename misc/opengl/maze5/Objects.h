#include "Prototypes.h"
#include "Light.h"
#include "Model.h"
#include "Maze.h"
#include "Constants.h"
#include "Robot.h"
#include "Player.h"
#include "Bullet.h"

#ifndef OBJECTS_H
#define OBJECTS_H

// Rotate variables
bool rotating = true;

// Light variables
float lightx;
float lighty;
float lightz;

// Weapon Variables
Model gunbarrel("gunbarrel.raw");
Model sight("sight.raw");
Model piece1("piece1.raw");
Model piece2("piece2.raw");
Model piece3("piece3.raw");
Model piece4("piece4.raw");
Model piece5("piece5.raw");
Model hand1("hand1.raw");
Model hand2("hand2.raw");
Model magazine("magazine.raw");

float transguny = 0.8f;
float transgunz = -1.6f;
float transgunx = 0.1f;

void draw_pieces()
{
    float piece3_color[] = {0.504f, 0.535f, 0.504f};
    piece3.setcolor(piece3_color);
    
    piece1.draw();
    piece2.draw();
    piece3.draw();
    piece4.draw();
    piece5.draw();
}

void draw_hands()
{
    float hand_color[] = {0.53f, 0.27f, 0.07f};
    hand1.setcolor(hand_color);
    hand2.setcolor(hand_color);
    
    hand1.draw();
    hand2.draw();
}

void draw_magazine()
{
    float magazine_color[] = {0.53f, 0.27f, 0.07f};
    magazine.setcolor(magazine_color);
    
    magazine.draw();
}

void draw_gunbarrel()
{
    float gunbarrel_color[] = {0.504f, 0.535f, 0.504f};
    gunbarrel.setcolor(gunbarrel_color);
    
    gunbarrel.draw();
}

void draw_sight()
{
    float sight_color[] = {0.0, 0.0, 0.0};
    sight.setcolor(sight_color);
    
    sight.draw();
}

void draw_gun()
{
    glPushMatrix();

    // Scale the weapon to make it small enough
    glScalef(0.2f, 0.2f, 0.2f);

    // Move the gun to the bottom right of the screen
    glTranslatef(0.8f, -1.6f, 0.1f);
	
    // Draw each piece of the weapon
    draw_gunbarrel();
    draw_sight();
    draw_pieces();
    draw_hands();
    draw_magazine();
	
    glPopMatrix(); 
}

// Maze variables
stack<Room> Stack;
Maze maze(NUM_ROWS, NUM_COLS,0,0,0);

// Robot variables
Robot * robots;
Bullet bullet;

void place_robots()
{
    robots = new Robot[NUM_ROBS];

    vector<int>used_rows;
    vector<int>used_cols;

    for (int i = 0; i < NUM_ROWS; i++)
    {
        int row;
        int col;
        bool found = false;

		if (i == 0)
		{
			row = 1;
			col = 1;
			found = true;
		}
        while (!found)
        {
            row = rand() % NUM_ROWS;
            col = rand() % NUM_COLS;

            found = true;
            
            for (int i = 0; i < used_rows.size(); i++)
            {
                if (row == used_rows[i])
                    found = false;
            }
            for (int i = 0; i < used_cols.size(); i++)
            {
                if (col == used_cols[i])
                    found = false;
            }
        }

        used_rows.push_back(row);
        used_cols.push_back(col);
        
        robots[i].set_row(row);
        robots[i].set_col(col);
        robots[i].set_tx((((col + 1) * CELL_W) - (CELL_W / 2)));
        robots[i].set_tz(-((row + 1) * CELL_H - (CELL_H / 2)));
    }
}

void move_robots()
{    
	//cout << "x: " << ::x << endl;
	//cout << "y: " << ::y << endl;
	bullet_hits_robots();
	trig_functions(maze.get_rotatex());
	bullet.shoot(1);

    bool dir_found = false;

    // Find a direction to go if neccessary (if *.get_next() is false)
    for (int i = 0; i < NUM_ROWS; i++)
    {
        if (!robots[i].get_next())
        {
            while (!dir_found)
            {
                int direction = rand() % 4;
                
                if (direction == 0 && !maze.getNwall(robots[i].get_row(), robots[i].get_col()))
                {
                    //robot.set_ty(robot.get_ty() - 0.1);
                    robots[i].set_dir(0);
                    robots[i].set_next(true);
                    dir_found = true;
                }
                else if (direction == 1 && !maze.getSwall(robots[i].get_row(), robots[i].get_col()))
                {
                    //robot.set_ty(robot.get_ty() + 0.1);
                    robots[i].set_dir(1);
                    robots[i].set_next(true);
                    dir_found = true;
                }
                else if (direction == 2 && !maze.getEwall(robots[i].get_row(), robots[i].get_col()))
                {
                    //robot.set_tx(robot.get_tx() + 0.1);
                    robots[i].set_dir(2);
                    robots[i].set_next(true);
                    dir_found = true;
                }
                else if (direction == 3 && !maze.getWwall(robots[i].get_row(), robots[i].get_col()))
                {
                    //robot.set_tx(robot.get_tx() - 0.1);
                    robots[i].set_dir(3);
                    robots[i].set_next(true);
                    dir_found = true;
                }
            }
        }
        
        // Find out if the robot is past its current cell. If it is, advance to the next cell and signal to look for another direction
        if ((robots[i].get_dir() == 0) && (((-robots[i].get_tz() + (robots[i].get_depth() / 2)) < (maze.get_ty(robots[i].get_row() , robots[i].get_col()) - (CELL_H / 2)))))
        {
            robots[i].set_row(robots[i].get_row() - 1);
            robots[i].set_next(false);
        }
        if ((robots[i].get_dir() == 1) && (((-robots[i].get_tz() - (robots[i].get_depth() / 2)) > (maze.get_ty(robots[i].get_row(), robots[i].get_col()) + (CELL_H / 2)))))
        {
            robots[i].set_row(robots[i].get_row() + 1);
            robots[i].set_next(false);
        }
        if ((robots[i].get_dir() == 2) && (((robots[i].get_tx() - (robots[i].get_width() / 2)) > (maze.get_tx(robots[i].get_row(), robots[i].get_col()) + (CELL_W / 2)))))
        {
            robots[i].set_col(robots[i].get_col() + 1);
            robots[i].set_next(false);
        }
        if ((robots[i].get_dir() == 3) && (((robots[i].get_tx() + (robots[i].get_width() / 2)) < (maze.get_tx(robots[i].get_row(), robots[i].get_col()) - (CELL_W / 2)))))
        {
            robots[i].set_col(robots[i].get_col() - 1);
            robots[i].set_next(false);
        }
        
        // Move the robot
		if (robots[i].get_dir() == 0)
		{
			robots[i].set_tz(robots[i].get_tz() + 0.01f);
		}
		else if (robots[i].get_dir() == 1)
		{
			robots[i].set_tz(robots[i].get_tz() - 0.01f);
		}
		else if (robots[i].get_dir() == 2)
		{
			robots[i].set_tx(robots[i].get_tx() + 0.01f);
		}
		else if (robots[i].get_dir() == 3)
		{
			robots[i].set_tx(robots[i].get_tx() - 0.01f);
		}
    }
    
    display();
}

void draw_robots()
{
	glPushMatrix();

	glTranslatef(maze.get_tx(), 0.0, -maze.get_ty());

	glTranslatef(-(CELL_W / 2), 0.0, (CELL_H / 2));
    for (int i = 0; i < NUM_ROWS; i++)
		robots[i].draw();

	glPopMatrix();
}

// Player variables
Player player;
float posxplayer = 0.0f;
float posyplayer = 0.0f;
float poszplayer = 0.0f;

bool l = false;
bool r = false;
bool f = false;
bool b = false;

void reset_sides()
{
	l = false;
	r = false;
	f = false;
	b = false;
}

void check_rc()
{
	/*
	cout << "made it this far" << endl;*/
}

void draw_player()
{
	//check_rc();
	if ((-player.get_tz() - (player.get_depth() / 2)) > (maze.get_ty(player.get_row(), player.get_col())))
	{
		player.set_row(player.get_row() + 1);
		reset_sides();
	}
	if ((-player.get_tz() + (player.get_depth() / 2)) < (maze.get_ty(player.get_row(), player.get_col()) - (CELL_H)))
	{
		player.set_row(player.get_row() - 1);
		reset_sides();
	}
	if ((player.get_tx() - (player.get_width() / 2)) > (maze.get_tx(player.get_row(), player.get_col())))
	{
		player.set_col(player.get_col() + 1);
		reset_sides();
	}
	if ((player.get_tx() + (player.get_width() / 2)) < (maze.get_tx(player.get_row(), player.get_col()) - (CELL_W)))
	{
		player.set_col(player.get_col() - 1);
		reset_sides();
	}

	if (maze.getSwall(player.get_row(), player.get_col()))
		f = true;
	if (maze.getNwall(player.get_row(), player.get_col()))
		b = true;
	if (maze.getWwall(player.get_row(), player.get_col()))
		l = true;
	if (maze.getEwall(player.get_row(), player.get_col()))
		r = true;

	player.set_depth(0.5);
    player.draw();
}

// Bullet variables
//Bullet bullet(0.8, -1.6, 0.1);
//Bullet bullet;

float shoottransx = 0.0;
float shoottransz = 0.0;
float bullet_color[] = {0.457f, 0.327f, 0.0f};

void draw_bullet()
{
    bullet.setcolor(bullet_color);

    bullet.draw();
}

void trig_functions(float angle)
{
	angle = 90 - angle;
    //bullet.set_hyp(angle);
    bullet.set_adj(angle);
    bullet.set_opp(angle);
}

void bullet_hits_robots()
{
	for (int i = 0; i < NUM_ROBS; i++)
	{
		if (-bullet.get_tx() + bullet.get_adj() > (robots[i].get_tx() - (robots[0].get_width() / 2)) && -bullet.get_tx() + bullet.get_adj() < (robots[i].get_tx() + (robots[i].get_width() / 2))
			&& -bullet.get_tz() + bullet.get_opp() > ((-robots[i].get_tz() - (robots[i].get_height() / 2))) && -bullet.get_tz() + bullet.get_opp() < ((-robots[i].get_tz() + (robots[i].get_height() / 2)))
			&& robots[i].get_alive())
		{
				robots[i].set_alive(false);
		}
	}
}

// Text variables
float text_color[] = {1.0f, 0.0f, 1.0f};
float cross_hair_color[] = {1.0f, 1.0f, 1.0f};
char s[] = "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | |           |";
char t[] = "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | x 30 |";
char u[] = "--------------------";
char ch1[] = "|";
char ch2[] = "-- --";

float xpos = -0.18f;
float ypos = -0.17f;
float zpos = -0.2f;

float xposch = 0.017f;
float yposch = -0.015f;
float zposch = -0.2f;

void draw_text()
{
	glPushMatrix();
    
	// Draw the number of rounds
	glColor3fv(text_color);
    glRasterPos3f(xpos, ypos, zpos);    
    for (int i = 0; i < strlen(s); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, s[i]);
    }
    glRasterPos3f(xpos, ypos - GLfloat(0.006), zpos);
    for (int i = 0; i < strlen(t); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, t[i]);
    }
    glRasterPos3f(xpos, ypos - GLfloat(0.012), zpos);
    for (int i = 0; i < strlen(u); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, u[i]);
    }
	glPopMatrix();

	glPushMatrix();
	// Draw the crosshair
	glColor3fv(cross_hair_color);
	glRasterPos3f(xposch, yposch, zposch);
    for (int i = 0; i < strlen(ch1); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, ch1[i]);
    }
	glRasterPos3f(xposch - 0.0095, yposch - 0.005, zposch);
    for (int i = 0; i < strlen(ch2); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, ch2[i]);
    }
	glRasterPos3f(xposch, yposch - 0.01, zposch);
    for (int i = 0; i < strlen(ch1); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, ch1[i]);
    }
	glPopMatrix();
	
}

// Mouse variables
int x = 0;
int y = 0;
bool mouse_down = false;

void mouse(int button, int state, int x, int y)
{
	// Set global x to the local x
	::x = x;
	// Note that the local variable y (the y position of the mouse
	// pointer) is measured from the top to bottom whereas the global
	// y (used by opengl for drawing) is measured from bottom to top.
	::y = 200 - y;
	mouse_down = (state == GLUT_DOWN);
	if (mouse_down)
		bullet.set_can_shoot(true);
	
	display();
}

#endif
