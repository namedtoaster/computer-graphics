#ifndef ROOM_H
#define ROOM_H

#include "Constants.h"

class Room {
public:
    Room(bool v0 = false, int r0 = 0, int c0 = 0) :
        visited(v0), row(r0), col(c0)
    {
        for (int i = 0; i < 4; i++)
            wall[i] = false;

        translate[0] = 0;//(CELL_W * (col + 1)) - (CELL_W / 2);
        translate[1] = 0;//-((CELL_H * (row + 1)) - (CELL_H / 2));
        translate[2] = 0;
    }

    void set_row(int set)
    {
        row = set;
    }
    void set_col(int set)
    {
        col = set;
    }
    void set_visit(bool set)
    {
        visited = set;
    }
    void set_walls(bool N = 1, bool S = 1, bool E = 1, bool W = 1)
    {
        wall[0] = N;
        wall[1] = S;
        wall[2] = E;
        wall[3] = W;
    }

    void setNwall(bool set)
    {
        wall[0] = set;
    }

    void setSwall(bool set)
    {
        wall[1] = set;
    }

    void setEwall(bool set)
    {
        wall[2] = set;
    }

    void setWwall(bool set)
    {
        wall[3] = set;
    }

    bool get_visited()
    {
        return visited;
    }

    int get_row()
    {
        return row;
    }

    int get_col()
    {
        return col;
    }

    bool getNwall()
    {
        return wall[0];
    }

    bool getSwall()
    {
        return wall[1];
    }

    bool getEwall()
    {
        return wall[2];
    }

    bool getWwall()
    {
        return wall[3];
    }

    float get_tx()
    {
        return translate[0];
    }
    float get_ty()
    {
        return translate[1];
    }
    float get_tz()
    {
        return translate[2];
    }

    void set_tx(float set)
    {
        translate[0] = set;
    }
    void set_ty(float set)
    {
        translate[1] = set;
    }
    void set_tz(float set)
    {
        translate[2] = set;
    }
    
private:
    bool visited;

    int row, col;
    
    bool wall[4];

    float translate[3];
};

#endif
