#ifndef ROBOT_H
#define ROBOT_H

#include "Model.h"

class Robot{
public:
    Robot(int, int);
    Robot();
    void draw();

    void set_tx(float);
    void set_tz(float);

    float get_tx();
    float get_ty();
    float get_tz();

    float get_height();
    float get_width();
    float get_depth();

    int get_row();
    int get_col();

    void set_row(int);
    void set_col(int);

    void set_next(bool);

    bool get_next();

    void set_dir(int);
    int get_dir();

	void set_alive(bool);
	bool get_alive();
private:
    int row, col;
    float height, width, depth;
    int direction;
	bool alive;
    bool next;
    float translatex, translatey, translatez;
};

#endif
