#ifndef MAZE_H
#define MAZE_H

#include <stack>

using namespace std;

#include "Room.h"
#include "Constants.h"

class Maze{
public:
    Maze(int, int, float, float, float);
    ~Maze();

    void generate_maze();
    void draw();

    void set_tx(float, int, int);
    void set_ty(float, int, int);
    void set_tz(float, int, int);

    void set_tx(float);
    void set_ty(float);
    void set_tz(float);

    float get_tx();
    float get_ty();
    float get_tz();

    void set_rotatex(float);
    float get_rotatex();

    void set_rotatey(float);
    float get_rotatey();

    void set_forwardt(float);
    float get_forwardt();

    void set_sidet(float);
    float get_sidet();

    float get_row();
    float get_col();

    bool get_visited(int, int);

    float get_tx(int, int);
    float get_ty(int, int);
    float get_tz(int, int);

    bool getNwall(int, int);
    bool getSwall(int, int);
    bool getEwall(int, int);
    bool getWwall(int, int);
private:
    int ROWS;
    int COLS;
    float translatex;
    float translatey;
    float translatez;
    float rotatex;
    float rotatey;
    float forwardmovement;
    float sidemovement;
    Room ** rooms;
    stack <Room>Stack;
    void remove_walls(int, int);
};

#endif
