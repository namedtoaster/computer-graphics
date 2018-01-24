#include <GL/glut.h>
#include <fstream>
#include <iostream>

#include "Model.h"

Model::Model(const char* filename)
{
    // initialize member variables *******************************
    
    translatex = 0.0; translatey = 0.0; translatez = 0.0;
    rotatex = 0.0; rotatey = 0.0; rotatez = 0.0;
    scalex = 1.0; scaley = 1.0; scalez = 1.0;
    
    float _color[3] = {1.0, 1.0, 1.0};
    for (int i = 0; i < 3; i++)
        color[i] = _color[i];
    
    lines = get_lines(filename);
    //file.close();
    
    //************************************************************
          
          // make the vertices array large enough to hold all of the vertices
          for (int x = 0; x < 3; x++)
      {
          for (int y = 0; y < 4; y++)
          {
              vertices[x][y] = new float[lines];
          }
      }
    
    ifstream file;
    file.open(filename);        
    char tmp[255];
    
    for (int z = 0; z < lines; z++)
    {
        file.getline(tmp, 255);
        ofstream out;
        out.open("tmp.txt");
        out << tmp;
        out.close();
        ifstream in;
        in.open("tmp.txt");
        
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (poly(tmp) == 12)
                    in >> vertices[x][y][z];
                else if (poly(tmp) == 9)
                {
                    if (y < 3)
                        in >> vertices[x][y][z];
                    else
                        vertices[x][y][z] = 0;
                }
            }
        }
        in.close();
    }
    file.close();
}

Model::~Model()
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            delete [] vertices[x][y];
        }
    }
}

int Model::poly(char tmp[])
{
    int counter = 0;
    int spaces = 0;

    while (tmp[counter] > 0)
    {
        if (tmp[counter] == ' ')
            spaces++;
        counter++;
    }

    return spaces;
}

int Model::get_lines(const char* filename)
{
    ifstream file;
    file.open(filename);

    char tmp[255];
    int lines = 0;

    while (file.getline(tmp, 255))
    {
        lines++;
    }

    return lines;
}

void Model::draw()
{    
    // draw object
    glPushMatrix();

    // color the object

    glColor3fv(color);

    // translate object
    glTranslatef(translatex, translatey, translatez);

    
    // rotate around x axis
    glRotatef(rotatex, 1.0, 0.0, 0.0);

    // rotate around y axis
    glRotatef(rotatey, 0.0, 1.0, 0.0);

    // rotate around z axis
    glRotatef(rotatez, 0.0, 0.0, 1.0);

    // scale object
    glScalef(scalex, scaley, scalez);
    
    for (int z = 0; z < lines; z++)
    {
        if (vertices[0][3][z] == 0)
        {
            glBegin(GL_TRIANGLES);
            
            // color object
            glColor3fv(color);
            
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    glVertex3f(vertices[0][y][z], vertices[1][y][z], vertices[2][y][z]);
                }
            }
            glEnd();
        }
        else
        {
            glBegin(GL_POLYGON);

            // color object
            glColor3fv(color);
            
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    glVertex3f(vertices[0][y][z], vertices[1][y][z], vertices[2][y][z]);
                }
            }
            glEnd();
        }
    }
    glPopMatrix();
}

float & Model::settx(const float set)
{
    translatex = set;

    return translatex;
}

float & Model::setty(const float set)
{
    translatey = set;

    return translatey;
}

float & Model::settz(const float set)
{
    translatez = set;

    return translatez;
}


float & Model::setrx(const float set)
{
    rotatex = set;

    return rotatex;
}

float & Model::setry(const float set)
{
    rotatey = set;

    return rotatey;
}

float & Model::setrz(const float set)
{
    rotatez = set;

    return rotatez;
}


float & Model::setsx(const float set)
{
    scalex = set;

    return scalex;
}

float & Model::setsy(const float set)
{
    scaley = set;

    return scaley;
}

float & Model::setsz(const float set)
{
    scalez = set;

    return scalez;
}


void Model::setcolor(const float set[])
{
    for (int i = 0; i < 3; i++)
        color[i] = set[i];
}

float *Model::get_color()
{
    return color;
}
