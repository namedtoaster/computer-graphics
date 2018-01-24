#include <GL/glut.h>
#include <iostream>

#include "Robot.h"
#include "Constants.h"
#include "Model.h"

float base_radius = 1.0f;
float top_radius = 1.0f;
float height_r = 3.0f;
int slice_per_ring = 20;
int rings = 20;

float elbowrotate = 0.0f;
float armrotate = 0.0f;

float bicep_radius = base_radius - 0.8;
float height_bicep = height_r / 2;
float hand_size = 0.3f;

float translate_armx = -base_radius - (base_radius - 0.8);
float translate_army = height_bicep;

using namespace std;

void forearmleft()
{
    // create objects to draw cylinder
    GLUquadricObj * p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL); // GLU_FILL will make it a solid cylinder
    
    glRotatef(elbowrotate, 1.0, 0.0, 0.0);
    // forearm
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.18); // move it up a little
    glRotatef(-270, 1.0, 0.0, 0.0);
    gluCylinder(p, bicep_radius, bicep_radius, height_bicep, slice_per_ring, rings);

    // hand
    glPushMatrix();

    glTranslatef(0.0, 0.0, height_bicep);
    glutSolidSphere(hand_size, 20, 20);

    // claws

    // claw no. 1
    glPushMatrix();
    glTranslatef(-(hand_size / 2), 0.0, hand_size);
    glRotatef(45.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 1.0, 0.5);
    glutSolidCube(hand_size * 1.5);
    glPopMatrix();

    // claw no. 2
    glPushMatrix();
    glTranslatef((hand_size / 2), 0.0, hand_size);
    glRotatef(-45.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 1.0, 0.5);
    glutSolidCube(hand_size * 1.5);
    glPopMatrix();
    // end of claws
    
    glPopMatrix(); // end of hand
    
    glPopMatrix(); // end of forearm
}

void forearmright()
{
    // create objects to draw cylinder
    GLUquadricObj * p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL); // GLU_FILL will make it a solid cylinder
    
    // forearm
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.18); // move it up a little
    glRotatef(-270, 1.0, 0.0, 0.0);
    gluCylinder(p, bicep_radius, bicep_radius, height_bicep, slice_per_ring, rings);

    // hand
    glPushMatrix();
    glTranslatef(0.0, 0.0, height_bicep);
    glutSolidSphere(hand_size, 20, 20);

    // claw no. 1
    glPushMatrix();
    glTranslatef(-(hand_size / 2), 0.0, hand_size);
    glRotatef(45.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 1.0, 0.5);
    glutSolidCube(hand_size * 1.5);
    glPopMatrix();

    // claw no. 1
    glPushMatrix();
    glTranslatef((hand_size / 2), 0.0, hand_size);
    glRotatef(-45.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 1.0, 0.5);
    glutSolidCube(hand_size * 1.5);
    glPopMatrix();
    // end of claws
    
    glPopMatrix(); // end of hand
    
    glPopMatrix(); // end of forearm
}

void bicepleft()
{
    // create objects to draw cylinder
    GLUquadricObj * p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL); // GLU_FILL will make it a solid cylinder
    
    // first bicep

    
    glPushMatrix();
    
    glTranslatef(translate_armx, 0.0, translate_army);
    gluCylinder(p, bicep_radius, bicep_radius, height_bicep, slice_per_ring, rings);

    // shoulder
    glPushMatrix();
    glTranslatef(0.0, 0.0, height_bicep - 0.1);
    //gluDisk(p, 0.0, bicep_radius, slice_p_r, rs);
    glRotatef(armrotate, 1.0, 0.0, 0.0);
    glutSolidSphere(bicep_radius + 0.1, 20, 20);
    glPopMatrix(); // end of disk on top of arm

    forearmleft();
    
    glPopMatrix(); // end of first bicep
}

void bicepright()
{
    // create objects to draw cylinder
    GLUquadricObj * p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL); // GLU_FILL will make it a solid cylinder
    
    // second bicep
    glPushMatrix();
    glTranslatef(-translate_armx, 0.0, translate_army);
    gluCylinder(p, bicep_radius, bicep_radius, height_bicep, slice_per_ring, rings);

    // shoulder
    glPushMatrix();
    glTranslatef(0.0, 0.0, height_bicep - 0.1);
    //gluDisk(p, 0.0, bicep_radius, slice_p_r, rs);
    glutSolidSphere(bicep_radius + 0.1, 20, 20);
    glPopMatrix(); // end of disk on top of arm

    forearmright();
    
    glPopMatrix(); // end of second bicep
}

void robot()
{
	float robot_color[] = {0.442, 0.442, 0.442};
	glColor3fv(robot_color);

    float inner_radius = 0.0f;
    float outer_radius = base_radius;
    int slice_p_r = 40;
    int rs = 40;

    // create objects to draw cylinder
    GLUquadricObj * p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL); // GLU_FILL will make it a solid cylinder

    glPushMatrix();

    glScalef(0.25, 0.25, 0.25);
    //glTranslatef(0.0, 3.0, 0.0);
    // rotate
    glRotatef(270.0, 1.0, 0.0, 0.0);

    // draw cylinder with specified sizes
    gluCylinder(p, base_radius, top_radius, height_r, slice_per_ring, rings);

    // discs - top and bottom
    glPushMatrix();
    //glTranslatef(0.0, 0.0, 0.0);
    gluDisk(p, inner_radius, outer_radius, slice_p_r, rs);
    glPopMatrix();

    // disk on top of head
    glPushMatrix();
    glTranslatef(0.0, 0.0, 3.0);
    gluDisk(p, inner_radius, outer_radius, slice_p_r, rs);

    // neck - beginning coordinates start at the disk on top of the head
    glPushMatrix();
    //glTranslatef(0.0, 0.0, 0.0);
    float neck_radius = base_radius - 0.7;
    float neck_height = height_r / 4 - 0.2;
    gluCylinder(p, neck_radius, neck_radius, neck_height, slice_per_ring, rings);

    // disc for top of head
    //glPushMatrix();
    //glTranslatef(0.0, 0.0, height / 4);
    //gluDisk(p, 0.0, base_radius - 0.5, slice_p_r, rs);
    //glPopMatrix(); // end of disk on top of head

    // head
    float head_height = neck_height + 0.2;
    glTranslatef(0.0, 0.0, head_height);
    glutSolidCube(1.0);
    //gluCylinder(p, 0.5, 0.6, 0.8, slice_per_ring, rings);


    // face
    glPushMatrix();

    // eyes

    // eye no. 1
	float eye_color[] = {1.0, 0.0, 0.0};
	glColor3fv(eye_color);

    glPushMatrix();
    glTranslatef(-0.2, -0.5, 0.2);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix(); // end of eye no. 1

    // eye no. 2
    glPushMatrix();
    glTranslatef(0.2, -0.5, 0.2);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix(); // end of eye no. 2

    // mouth
    glPushMatrix();
    glTranslatef(0.0, -0.5, -0.1);
    glScalef(2.0, 0.2, 0.1);
    glutSolidCube(0.4);
    glPopMatrix();
    
    glPopMatrix(); // end of face

    glPopMatrix(); // end of head
    
    glPopMatrix(); // end of disk on top of robot

    // arms
	glColor3fv(robot_color);
    // biceps

    bicepleft();

    bicepright();

    // legs

    // leg no. 1
    glPushMatrix();
    glPushMatrix();
    float leg_radius = bicep_radius + 0.08;
    float translatelegx = leg_radius * 2;
    glTranslatef(-translatelegx, 0.0, -3.0);
    gluCylinder(p, leg_radius, leg_radius, 3.0, slice_per_ring, rings);

    // foot no. 1
    glPushMatrix();
    float foot_size = 0.7;
    glTranslatef(0.0, -0.4, (foot_size / 2));
    glScalef(1.0, 2.0, 1.0);
    glutSolidCube(foot_size);
    glPopMatrix(); // end of foot no. 1
    
    glPopMatrix(); // end of leg no. 1

    // leg no. 2
    glPushMatrix();
    glTranslatef(translatelegx, 0.0, -3.0);
    gluCylinder(p, leg_radius, leg_radius, 3.0, slice_per_ring, rings);

    // foot no. 2
    glPushMatrix();
    glTranslatef(0.0, -0.4, (foot_size / 2));
    glScalef(1.0, 2.0, 1.0);
    glutSolidCube(foot_size);
    glPopMatrix(); // end of foot no. 2
    
    glPopMatrix(); // end of leg no. 2

    glPopMatrix(); // end of legs
    
    glPopMatrix(); // end of robot
}

Robot::Robot(int r0 = 0, int c0 = 0) :
    row(r0), col(c0)
{    
	alive = true;
    height = 1;
    width = 1;
    depth = 1;
    next = false;
    direction = 0;
    
    translatex = (((col + 1) * CELL_W) - (CELL_W / 2));
    translatey = height / 2;
    translatez= -((row + 1) * CELL_H - (CELL_H / 2));
}

Robot::Robot() :
    row(0), col(0)
{
	alive = true;
    height = 1;
    width = 1;
    depth = 1;
    next = false;
    direction = 0;
    
    translatex = (((col + 1) * CELL_W) - (CELL_W / 2));
    translatey = -(height / 2);
    translatez= -((row + 1) * CELL_H - (CELL_H / 2));
}

void Robot::draw()
{
    float robot_color[] = {0.0, 0.0, 1.0};

    glPushMatrix();

    glColor3fv(robot_color);
    glTranslatef(translatex, translatey, translatez);
    //glutSolidCube(1);
	if (alive == true)
		robot();

    glPopMatrix();
}

void Robot::set_tx(float set)
{
    translatex = set;
}
void Robot::set_tz(float set)
{
    translatez = set;
}

float Robot::get_tx()
{
    return translatex;
}
float Robot::get_ty()
{
    return translatey;
}
float Robot::get_tz()
{
    return translatez;
}

float Robot::get_depth()
{
    return depth;
}
float Robot::get_height()
{
    return height;
}
float Robot::get_width()
{
    return width;
}

int Robot::get_row()
{
    return row;
}
int Robot::get_col()
{
    return col;
}

void Robot::set_row(int set)
{
    row = set;
}
void Robot::set_col(int set)
{
    col = set;
}

void Robot::set_next(bool set)
{
    next = set;
}

bool Robot::get_next()
{
    return next;
}

void Robot::set_dir(int set)
{
    direction = set;
}
int Robot::get_dir()
{
    return direction;
}

void Robot::set_alive(bool set)
{
	alive = set;
}
bool Robot::get_alive()
{
	return alive;
}