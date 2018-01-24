#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <GL/glut.h>

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0f, 400.0f, 0.0f, 400.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
}

double pi = 3.14150;
double angle = (2 * pi / 3);
double orig_angle = 0;

int n = 0;

float x_1, x_2, x_3, y_1, y_2, y_3;
float orig_x = 50.0, orig_y = 0.0;

double changex = 200.0;
double changey = 200.0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);

	x_1 = orig_x * cos(orig_angle) - orig_y * sin(orig_angle);
	y_1 = orig_x * sin(orig_angle) + orig_y * cos(orig_angle);

	x_2 = (x_1 * cos(angle) - y_1 * sin(angle));
	y_2 = (x_1 * sin(angle) + y_1 * cos(angle));

	x_3 = (x_2 * cos(angle) - y_2 * sin(angle));
	y_3 = (x_2 * sin(angle) + y_2 * cos(angle));

	// Color of vertex 1 
	glColor3f(1.0, 0.0f, 0.0f);
	glVertex2f(x_1 + changex, y_1 + changey);

	// Color of vertex 2
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(x_2 + changex, y_2 + changey);

	// Color of vertex 3
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x_3 + changex, y_3 + changey);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(changex, changey);
	glVertex2i(x_1 + changex, y_1 + changey);
	glVertex2i(changex, changey);
	glVertex2i(x_2 + changex, y_2 + changey);
	glVertex2i(changex, changey);
	glVertex2i(x_3 + changex, y_3 + changey);


	glEnd();
	glFlush();

	orig_angle += (pi / 18);
}

int main(int argc, char ** argv)
{
	srand((unsigned int) time(NULL));

	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Equilateral Triangle");

	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;
}
