#ifndef PLAYER_H
#define PLAYER_H

#include "Maze.h"

class Player{
public:
    Player();
    Player(float, float, float);
    void draw();

    float get_depth();
	float get_width();

	void set_depth(float);

	void set_tx(float);
	void set_ty(float);
	void set_tz(float);

	float get_tx();
	float get_ty();
	float get_tz();

	void set_row(int);
	void set_col(int);

	int get_row();
	int get_col();
private:
    float width, height, depth;
    float toplfront[3], toprfront[3], toplback[3], toprback[3],
        bottomlfront[3], bottomrfront[3], bottomlback[3], bottomrback[3];
    float translatex, translatey, translatez;
	int row, col;
    //float rotatex
};

#endif
