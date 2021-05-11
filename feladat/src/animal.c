#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "draw.h"
#include "draw_scene.h"

void draw_cat(Object* cat)
{
	cat->position.x = sin((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 10.0f) * 10.0f;
	cat->position.z = cos((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 10.0f) * 10.0f;

	glPushMatrix();
		glTranslatef(cat->position.x, cat->position.y, cat->position.z);
		glBindTexture(GL_TEXTURE_2D, cat->texture);
		glScalef(1.5f, 1.5f, 1.5f);
		glTranslatef(-50, -1, -70);
		glRotatef(-90,1,0,0);
		glRotatef(-90,0,0,1);
		draw_model(&cat->model);
	glPopMatrix();
}

void draw_dog(Object* dog)
{
	dog->position.x = sin((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 10.0f) * 10.0f;
	dog->position.z = cos((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 10.0f) * 10.0f;

	glPushMatrix();
		glTranslatef(dog->position.x, dog->position.y, dog->position.z);
		glBindTexture(GL_TEXTURE_2D, dog->texture);
		glScalef(1.5f, 1.5f, 1.5f);
		glTranslatef(-50, -1, -70);
		glRotatef(-90,1,0,0);
		glRotatef(-90,0,0,1);
		draw_model(&dog->model);
	glPopMatrix();
}
