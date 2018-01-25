#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

#include "Maze.h"
#include "Constants.h"
#include "Model.h"
#include "Surface.h"
#include "Light.h"

//float mazex = -((NUM_COLS * CELL_W) / 2);

Maze::Maze(const int rows = 0, const int cols = 0, float tx = 0, float ty = 0, float tz = 0) :
    ROWS(rows), COLS(cols), translatex(tx), translatey(ty), translatez(tz)
{
    sidemovement = 0;
    
    rooms = new Room*[ROWS];
    for (int i = 0; i < ROWS; i++)
        rooms[i] = new Room[COLS];
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            rooms[i][j].set_row(i);
            rooms[i][j].set_col(j);
            rooms[i][j].set_visit(false);
            rooms[i][j].set_walls();

            rooms[i][j].set_tx(CELL_W * (j + 1) - (CELL_W / 2));
            rooms[i][j].set_ty(CELL_H * (i + 1) - (CELL_H / 2));
        }
    }
}

Maze::~Maze() // Take care of this destructor
{/*
   for (int i = 0; i < ROWS; i++)
   {
   delete [] *rooms;
   }
   delete [] **rooms;*/
}

void Maze::generate_maze()
{
    Stack.push(rooms[0][0]);
    
    remove_walls(0, 0);
}

void Maze::remove_walls(int row, int col)
{
    //cout << "row: " << row << endl;
    //cout << "col: " << col << endl;

    rooms[row][col].set_visit(true);
    
    //srand(time(NULL));
    
    bool north = false;
    bool south = false;
    bool east = false;
    bool west = false;

    if (!Stack.empty())
    {
        if (row > 0 && !rooms[row - 1][col].get_visited())
            north = true;
        if (row < NUM_ROWS - 1 && !rooms[row + 1][col].get_visited())
            south = true;
        if (col > 0 && !rooms[row][col - 1].get_visited())
            west = true;
        if (col < NUM_COLS - 1 && !rooms[row][col + 1].get_visited())
            east = true;

        if (north || south || east || west)
        {
            bool dirFound = false;

            while (!dirFound)
            {
                int direction = rand() % 4;
                //cout << "direction: " << direction << endl;
                if (direction == 0 && north)
                {
                    Stack.push(rooms[row - 1][col]);
                    rooms[row][col].setNwall(0);
                    rooms[row - 1][col].setSwall(0);
                    
                    dirFound = true;
                    remove_walls(row - 1, col);
                }
                else if (direction == 1 && south)
                {
                    Stack.push(rooms[row + 1][col]);
                    rooms[row][col].setSwall(0);
                    rooms[row + 1][col].setNwall(0);
                    
                    dirFound = true;
                    remove_walls(row + 1, col);
                }
                else if (direction == 2 && east)
                {
                    Stack.push(rooms[row][col + 1]);
                    rooms[row][col].setEwall(0);
                    rooms[row][col + 1].setWwall(0);
                    
                    dirFound = true;
                    remove_walls(row, col + 1);
                }
                else if (direction == 3 && west)
                {
                    Stack.push(rooms[row][col - 1]);
                    rooms[row][col].setWwall(0);
                    rooms[row][col - 1].setEwall(0);
                    
                    dirFound = true;
                    remove_walls(row, col - 1);
                }
            }
        }
        else
        {
            Room next = Stack.top();
            Stack.pop();
            remove_walls(next.get_row(), next.get_col());
        }
    }
        
    return;
}

void Maze::draw()
{
    
    glPushMatrix();

    //glTranslatef(0.0, 0.0, forwardmovement);
    //glTranslatef(sidemovement, 0.0, 0.0);

    //translatex = -(CELL_W / 2);
    //translatez = -(WALL_H / 3);

    glTranslatef(-(CELL_W / 2), -1.5, (CELL_H / 2));
    glRotatef(-90.0, 1.0, 0.0, 0.0);

    glTranslatef(translatex, translatey, translatez);

    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            glPushMatrix();

            glTranslatef(rooms[i][j].get_tx(), rooms[i][j].get_ty(), rooms[i][j].get_tz());

            float color2[] = {0.785, 0.588, 0.196};
            glColor3fv(color2);
            
            // Draw left wall
            
            if (rooms[i][j].getEwall())
            {
                glPushMatrix();

                glTranslatef((CELL_W / 2), 0.0, 0.0);
                glScalef(0.01, CELL_H, WALL_H);
                glutSolidCube(1.0);
                
                glPopMatrix();
            }

            // Draw right wall

            if (rooms[i][j].getWwall())
            {
                glPushMatrix();

                glTranslatef(-(CELL_W / 2), 0.0, 0.0);
                glScalef(0.01, CELL_H, WALL_H);
                glutSolidCube(1);
                
                glPopMatrix();
            }
                     
            // Draw top wall

            if (rooms[i][j].getSwall())
            {
                glPushMatrix();

                glTranslatef(0.0, (CELL_H / 2), 0.0);
                glScalef(CELL_W, 0.01, WALL_H);
                glutSolidCube(1);
                
                glPopMatrix();
            }
            
            // Draw bottom wall

            if (rooms[i][j].getNwall())
            {
                glPushMatrix();

                glTranslatef(0.0, -(CELL_H / 2), 0.0);
                glScalef(CELL_W, 0.01, WALL_H);
                glutSolidCube(1);
                
                glPopMatrix();
            }

            float color[] = {0.0, 0.196, 0.196};
            glColor3fv(color);
            
            glScalef(CELL_W, CELL_H, 0.01);
            glutSolidCube(1.0);

			glPushMatrix();
			glTranslatef(0.0f, 1.0f, 0.0f);
			glScalef(CELL_W, CELL_H, 0.01);
            glutSolidCube(1.0);
			glPopMatrix();

            glPopMatrix();
        }
    }
    glPopMatrix();
}

void Maze::set_tx(float set, int row, int col)
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
            rooms[i][j].set_tx(rooms[i][j].get_tx() + set);
    }
}
void Maze::set_ty(float set, int row, int col)
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
            rooms[i][j].set_ty(rooms[i][j].get_ty() + set);
    }
}
void Maze::set_tz(float set, int row, int col)
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
            rooms[i][j].set_tz(rooms[i][j].get_tz() + set);
    }
}

void Maze::set_tx(float set)
{
    translatex += set;
}
void Maze::set_ty(float set)
{
    translatey += set;
}
void Maze::set_tz(float set)
{
    translatez += set;
}

float Maze::get_tx()
{
    return translatex;
}
float Maze::get_ty()
{
    return translatey;
}
float Maze::get_tz()
{
    return translatez;
}

void Maze::set_rotatex(float set)
{
    rotatex = set;
}

float Maze::get_rotatex()
{
    return rotatex;
}

void Maze::set_rotatey(float set)
{
    rotatey = set;
}

float Maze::get_rotatey()
{
    return rotatey;
}

void Maze::set_forwardt(float set)
{
    forwardmovement = set;
}
float Maze::get_forwardt()
{
    return forwardmovement;
}

void Maze::set_sidet(float set)
{
    sidemovement = set;
}
float Maze::get_sidet()
{
    return sidemovement;
}

float Maze::get_row()
{
    return ROWS;
}
float Maze::get_col()
{
    return COLS;
}

bool Maze::get_visited(int row, int col)
{
    return rooms[row][col].get_visited();
}

float Maze::get_tx(int row, int col)
{
    return rooms[row][col].get_tx();
}
float Maze::get_ty(int row, int col)
{
    return rooms[row][col].get_ty();
}
float Maze::get_tz(int row, int col)
{
    return rooms[row][col].get_tz();
}

bool Maze::getNwall(int row, int col)
{
    return rooms[row][col].getNwall();
}
bool Maze::getSwall(int row, int col)
{
    return rooms[row][col].getSwall();
}
bool Maze::getEwall(int row, int col)
{
    return rooms[row][col].getEwall();
}
bool Maze::getWwall(int row, int col)
{
    return rooms[row][col].getWwall();
}
