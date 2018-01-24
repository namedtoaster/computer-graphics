#ifndef OBJECTS_H
#define OBJECTS_H

#include "Model.h"
#include "Prototypes.h"

// Window variables
int width = 640;
int height = 680;
float fovy = 90.0; 
float aspect = 1.0;  
float zNear = 1.0; 
float zFar = 500.0; 

// Eye variables
float eyex;
float eyey;
float eyez;
const float eye_color[] = {1.0, 1.0, 1.0};

// Sun variables
float sunx;
float suny;
float sunz;

// Light variables
float lightx;
float lighty;
float lightz;

// Desert variables
Model desert("desert.raw");
const float floor_color[] = {0.0, 0.4, 0.0};
void draw_desert()
{
    //desert.setsz(3.0);
    //desert.setsx(3.0);

    //desert.settx(-20.0);
    //desert.setty(-16.0);
    //desert.settz(-15.0);
    
    desert.setcolor(floor_color);

    desert.draw();
}

// Table variables
Model table("table.raw");
const float table_color[] = {0.3f, 0.2f, 0.0f};
const float table_w = 26.0f;
const float table_h = 20.0f;
const float table_d = 20.0f;
void draw_table()
{
    table.settx(-0.2);
    table.setsx(table_w);
    table.setsy(table_h);
    table.setsz(table_d);

    table.setcolor(table_color);
        table.draw();
}

// Block variables
const float block_color[] = {1.0, 0.0, 1.0};
const float block_tx = 0.0f;
const float block_ty = 10.7f;
const float block_tz = 0.0;
const float block_w = 14.0f;
const float block_h = 0.01f;
const float block_d = 4.0f;
void draw_blocks()
{
    glPushMatrix();
    
    // Color blocks

    glColor3fv(block_color);
    
    glTranslatef(block_tx, block_ty, block_tz);
    glScalef(block_w, block_h, block_d);
    glutSolidCube(1);

    glPopMatrix();
}

// Paddle variables
float paddlex = 0.0f;
float paddley = 10.7f;
float paddlez = 13.5f - 0.5f;
const float paddle_color[] = {1.0, 0.0, 0.0};
const float paddle_w = 4.0f;
const float paddle_h = 0.5f;
const float paddle_d = 0.5f;
void draw_paddle()
{
    glPushMatrix();
    
    // Color the paddle

    glColor3fv(paddle_color);

    glTranslatef(paddlex, paddley, paddlez);
    glScalef(paddle_w, paddle_h, paddle_d);
    glutSolidCube(1);

    glPopMatrix();
}

// Board variables
const float side_color[] = {0.0, 0.0, 1.0};
const float board_w = 14.0f;
const float board_h = 10.7f;
void draw_sides()
{
    glPushMatrix();

    // Color the sides	
    glColor3fv(side_color);
    
    glPushMatrix();
    glTranslatef(-7.0, 10.7, 0.0);
    glScalef(0.01, 0.01, 2.7);
    glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.0, 10.7, 0.0);
    glScalef(0.01, 0.01, 2.7);
    glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 10.7, 13.5);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.01, 0.01, 1.4);
    glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 10.7, -13.5);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.01, 0.01, 1.4);
    glutSolidCube(10);
    glPopMatrix();

    draw_blocks();

    draw_paddle();
    
    glPopMatrix();
}

// Draw
void draw()
{
    draw_sides();
    draw_table();
    //draw_desert();
}

// Ball variables
float x = 10.0f, y = 20.0f, dx0 = -0.1f, dy0 = 0.1f;

void mod(float & a, float & da)
{
	a += da;
	if (a < 0)
	{
		a = 0; da = -da;
	}
	else if (a > 40)
	{
		a = 40; da = -da;
	}
}

void idle()
{
	mod(x, dx0);
	mod(y, dy0);

	display();
}

#endif
