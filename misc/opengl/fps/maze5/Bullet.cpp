#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

#include "Bullet.h"
#include "Constants.h"
#include "Prototypes.h"

Bullet::Bullet() :
    translatex(0 - (CELL_W / 2)), translatey(0), translatez(0 - (CELL_H / 2)),
    width(0.1f), depth(0.3f), height(0.1f)
{
    hypotenuse = 1.03f;
}

Bullet::Bullet(float tx=0, float ty=0, float tz=0) :
    translatex(tx - (CELL_W / 2)), translatey(ty), translatez(tz - (CELL_H / 2)),
    width(0.1f), depth(0.3f), height(0.1f)
{
	hypotenuse = 1.03f;
}

void Bullet::shoot(float inc)
{
	if (can_shoot)
	{
		hypotenuse += 0.5f;
		if (hypotenuse > 10)
		{
			can_shoot = false;
			hypotenuse = 1.03f;
		}
	}
	bullet_hits_robots();
}

void Bullet::set_tx(float set)
{
    translatex = set;
}
void Bullet::set_ty(float set)
{
    translatey = set;
}
void Bullet::set_tz(float set)
{
    translatez = set;
}

float Bullet::get_tx()
{
    return translatex;
}
float Bullet::get_ty()
{
    return translatey;
}
float Bullet::get_tz()
{
    return translatez;
}

void Bullet::draw()
{
    glPushMatrix();

    glColor3fv(color);
    glScalef(width, height, depth);
    glTranslatef(GLfloat(1.75), GLfloat(-1.9), GLfloat(-3.4));
    glTranslatef(GLfloat(0), translatey, GLfloat(-hypotenuse + 1.03));

    GLUquadricObj * p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL);
    gluCylinder(p, width / 2, width / 2, height, 20, 20);
    gluDeleteQuadric(p);

    glPopMatrix();
}

void Bullet::setcolor(float set[])
{
    color[0] = set[0];
    color[1] = set[1];
    color[2] = set[2];
}

void Bullet::set_hyp(float set)
{
    float pi = 3.1415926535897932384626433832795f;
    float rad = set * pi / 180;
}
void Bullet::set_adj(float set)
{
    float pi = 3.1415926535897932384626433832795f;
    float rad = set * pi / 180;

	adjacent = cos(rad) * hypotenuse + 0.16f;
}
void Bullet::set_opp(float set)
{
    float pi = 3.1415926535897932384626433832795f;
    float rad = set * pi / 180;

	opposite = sin(rad) * hypotenuse;
}

float Bullet::get_hyp()
{
    return hypotenuse;
}
float Bullet::get_adj()
{
    return adjacent;
}
float Bullet::get_opp()
{
    return opposite;
}

void Bullet::set_can_shoot(bool set)
{
	can_shoot = set;
}
bool Bullet::get_can_shoot()
{
	return can_shoot;
}