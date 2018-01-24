// Name: David Campbell
// File: Model.h
//
// Description: Loads 3d models for use in OpenGL. Handles .raw files
//
// .raw file contains coordinates of 3d model in sets of 4 (with x,y,z coordinates)
//
// Every 3d object imported via .raw file is comprised of quads and/or triangles
//
// The .raw file will be parsed for these coordinates and will store in 3d array (3 x 4 x # of faces)
// If current face is a quad, each coordinate will be stored approriately as normal. If current
// face is triangle, first three sets of coordinates will be stored and the third set will be
// stored with zeroes.
//
// When the model is being drawn, if the current face is a triangle, a call to
// glBegin(GL_TRIANGLES) will be made and only the first three sets of coordinates will be parsed.
// Otherwise glBegin(GL_QUADS) will be called and all four sets of coordinates will be parsed

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <fstream>

using namespace std;

class FileError
{
public:
    void nofile()
    {
        cout << "Error: File not found" << endl;
    }
};

class Model
{
public:
    Model(const char* filename);
    ~Model();

    void draw();

    float & settx(const float);
    float & setty(const float);
    float & settz(const float);

    float & setrx(const float);
    float & setry(const float);
    float & setrz(const float);

    float & setsx(const float);
    float & setsy(const float);
    float & setsz(const float);

    void setcolor(const float[]);
    float *get_color();

    void set_file(const char*);
private:
    int poly(char []);
    int get_lines(const char*);

    int lines;
    float * vertices[3][4];

    float translatex;
    float translatey;
    float translatez;

    float rotatex;
    float rotatey;
    float rotatez;

    float scalex;
    float scaley;
    float scalez;

    float color[3];
};

#endif
