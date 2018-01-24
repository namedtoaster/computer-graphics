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
double angle = 0;

float x_1, x_2, x_3, x_4, y_1, y_2, y_3, y_4;
float o_x1, o_x2, o_x3, o_x4, o_y1, o_y2, o_y3, o_y4;
//float orig_x = 50.0, orig_y = 0.0;

double changex = 200.0;
double changey = 200.0;

int num = 0;

void display()
{
	if (num == 0)
	{
		o_x1 = 20 + rand() % 21;
		o_y1 = 20 + rand() % 21;
	
		o_x2 = -40 + rand() % 21;
		o_y2 = 20 + rand() % 21;
	
		o_x3 = -40 + rand() % 21;
		o_y3 = -40 + rand() % 21;
		
		o_x4 = 20 + rand() % 21;
		o_y4 = -40 + rand() % 21;
	}
	else
	{
		x_1 = o_x1 * cos(angle) - o_y1 * sin(angle);
		y_1 = o_x1 * sin(angle) + o_y1 * cos(angle);

		x_2 = o_x2 * cos(angle) - o_y2 * sin(angle);
		y_2 = o_x2 * sin(angle) + o_y2 * cos(angle);

		x_3 = o_x3 * cos(angle) - o_y3 * sin(angle);
		y_3 = o_x3 * sin(angle) + o_y3 * cos(angle);

		x_4 = o_x4 * cos(angle) - o_y4 * sin(angle);
		y_4 = o_x4 * sin(angle) + o_y4 * cos(angle);
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);

	if (num == 0)
	{
		// Color of vertex 1 
		glColor3f(1.0, 0.0f, 0.0f);
		glVertex2f(o_x1 + changex, o_y1 + changey);
		glVertex2f(o_x2 + changex, o_y2 + changey);

		// Color of vertex 3
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(o_x3 + changex, o_y3 + changey);
		glVertex2f(o_x4 + changex, o_y4 + changey);
	}

	else
	{
		// Color of vertex 1 
		glColor3f(1.0, 0.0f, 0.0f);
		glVertex2f(x_1 + changex, y_1 + changey);
		glVertex2f(x_2 + changex, y_2 + changey);
	
		// Color of vertex 3
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(x_3 + changex, y_3 + changey);
		glVertex2f(x_4 + changex, y_4 + changey);
	}

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(changex, 0);
	glVertex2i(changex, 400);
	glVertex2i(0, changey);
	glVertex2i(400, changey);


	glEnd();
	glFlush();

	if (num == 0) num++;
	angle += (pi / 18);
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
