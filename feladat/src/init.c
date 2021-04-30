/**
 * init.c
 */

#include <GL/glut.h>

#include "callbacks.h"

GLfloat light_position[] = {0, 100, 150};//, 0};
GLfloat light_ambient[] = { 0.8, 0.8, 0.8, 0.8};
GLfloat light_diffuse[] = {0.3, 0.3, 0.3, 0.9};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

void init()
{
	set_callbacks();

	init_camera(&camera);
	init_entities(&world);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
}
