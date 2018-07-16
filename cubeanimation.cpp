#include <iostream>
#include <GL/glut.h>  

using namespace std;

double rotate_y = 0;
double rotate_x = 0;
double a = 1;
int mode = 1;
int width = 640;
int height = 640;
float asp = 1;





void reshape(int width, int height) {
	if (height > 0) {
		asp = (double)width / height;
	}
	else {
		asp = 1;
	}
	glViewport(0, 0, width, height);

}


void Movekeys(unsigned char key, int x, int y) {

	if (key == 'D' || key == 'd')
		rotate_y += 5;


	else if (key == 'A' || key == 'a')
		rotate_y -= 5;

	else if (key == 'S' || key == 's')
		rotate_x += 5;

	else if (key == 'W' || key == 'w')
		rotate_x -= 5;

	if (key == 'P' || key == 'p') {
		if (mode == 1) {
			mode = 0;

		}
		else {
			mode = 1;
		}
	}


	glutPostRedisplay();

}



void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	
	if (mode) {
		gluPerspective(60.0, asp, 0.1, 100);
		glTranslatef(0, 0, -6.2);
	}
	else {
		glOrtho(-3 * asp, 3 * asp, -3, 3, -3, 3);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);


	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(a, -a, -a);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(a, a, -a);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-a, a, -a);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-a, -a, -a);
	glEnd();

	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(0.758, 0.231, 0.124);
	glVertex3f(a, -a, a);
	glVertex3f(a, a, a);
	glVertex3f(-a, a, a);
	glVertex3f(-a, -a, a);
	glEnd();

	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(0.21, 0.31, 0.41);
	glVertex3f(a, -a, -a);
	glVertex3f(a, a, -a);
	glVertex3f(a, a, a);
	glVertex3f(a, -a, a);
	glEnd();

	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.31, 0.21);
	glVertex3f(-a, -a, a);
	glVertex3f(-a, a, a);
	glVertex3f(-a, a, -a);
	glVertex3f(-a, -a, -a);
	glEnd();

	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(0.51, 0.61, 0.21);
	glVertex3f(a, a, a);
	glVertex3f(a, a, -a);
	glVertex3f(-a, a, -a);
	glVertex3f(-a, a, a);
	glEnd();


	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.32, 0.123);
	glVertex3f(a, -a, -a);
	glVertex3f(a, -a, a);
	glVertex3f(-a, -a, a);
	glVertex3f(-a, -a, -a);
	glEnd();

	glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(width, height);
	glutCreateWindow("Cube");

	glEnable(GL_DEPTH_TEST);



	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Movekeys);

	glutMainLoop();

	return 0;

}
