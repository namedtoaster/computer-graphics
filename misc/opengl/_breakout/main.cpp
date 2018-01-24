#include <ctime>
#include <cstdlib>
#include <GL/glut.h>

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0f, 400.0f, 0.0f, 400.0f);
	glPointSize(8.0f);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
}

float x0 = 10, y0 = 20, dx0 = -0.6, dy0 = 1.2;
int x_0 = 150, y_0 = 250;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x0, y0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(x_0, 10);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(y_0, 10);

	glEnd();

	glutSwapBuffers();

}
	
void mod(float & a, float & da)
{
	a += da;
	if (a < 0)
	{
		a = 0; da = -da;
	}
	else if (a > 400)
	{
		a = 400; da = -da;
	}
}

// This function will be executed when the event queue is empty.
void idle()
{
	mod(x0, dx0);
	mod(y0, dy0);

	display();
}

void specialkeyboard(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT : x_0 -= 7; y_0 -= 7; break;
		case GLUT_KEY_RIGHT: x_0 += 7; y_0 += 7; break;
		
	}

	display();
}

int main(int argc, char ** argv)
{
	srand((unsigned int) time(NULL));

	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("test");

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutSpecialFunc(specialkeyboard);

	init();
	glutMainLoop();

	return 0;
}

