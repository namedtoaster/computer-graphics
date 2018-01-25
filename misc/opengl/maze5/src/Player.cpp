#include <GL/glut.h>
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player() :
    width(0.5), height(1), depth(1), row(0), col(0)
{
    toplfront[0] = -(width / 2); toplfront[1] = height / 2; toplfront[2] = -(depth / 2);
    toprfront[0] = width / 2; toprfront[1] = height / 2; toprfront[2] = -(depth / 2);
    toplback[0] = -(width / 2); toplback[1] = height / 2; toplback[2] = depth / 2;
    toprback[0] = width / 2; toprback[1] = height / 2; toprback[2] = depth / 2;

    bottomlfront[0] = -(width / 2); bottomlfront[1] = -(height / 2); bottomlfront[2] = -(depth / 2);
    bottomrfront[0] = width / 2; bottomrfront[1] = -(height / 2); bottomrfront[2] = -(depth / 2);
    bottomlback[0] = -(width / 2); bottomlback[1] = -(height / 2); bottomlback[2] = depth / 2;
    bottomrback[0] = width / 2; bottomrback[1] = -(height / 2); bottomrback[2] = depth / 2;

    translatex = 0; translatey = 0; translatez = 0 - 1.34 / 2;
}
Player::Player(float w0 = 1, float h0 = 1, float d0 = 1) :
    width(w0), height(h0), depth(d0), row(0), col(0)
{
}

void Player::draw()
{
    float cube_color[] = {1.0, 0.0, 0.0};

    //cout << toplfront[0] << endl;

    glPushMatrix();
    //glTranslatef(translatex, translatey, translatez);
    glScalef(width, height, depth);    
    //glutSolidCube(1);
    glPopMatrix();
}

float Player::get_depth()
{
    return depth;
}
float Player::get_width()
{
	return width;
}

void Player::set_depth(float set)
{
	depth = set;
}

void Player::set_tx(float set)
{
	translatex = set;
}
void Player::set_ty(float set)
{
	translatey = set;
}
void Player::set_tz(float set)
{
	translatez = set;
}

float Player::get_tx()
{
	return translatex;
}
float Player::get_ty()
{
	return translatey;
}
float Player::get_tz()
{
	return translatez;
}

void Player::set_row(int set)
{
	row = set;
}
void Player::set_col(int set)
{
	col = set;
}

int Player::get_row()
{
	return row;
}
int Player::get_col()
{
	return col;
}