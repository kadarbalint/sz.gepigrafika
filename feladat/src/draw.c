/**
 * draw.c
 */

#include "GL/glut.h"
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "draw.h"
#include "model.h"
#include "callbacks.h"

float sizeOfRoom = 200.0f;
extern GLfloat light_ambient[4];
GLfloat material_ambient_default[] = {0.9f, 0.9f, 0.9f, 0.5f};

void draw_teapot_for_light(){
    glPushMatrix();
        glTranslatef(120, 15, 120);
        glScalef(12, 12, 12);
        glutSolidTeapot(1.0);
    glPopMatrix();
}

void draw_content(World* world)
{
	world->dog.position.x = sin((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 5.0f) * 40.0f;
	world->dog.position.z = cos((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 5.0f) * 40.0f;

	world->cat.position.x = cos((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 5.0f) * 40.0f;
	world->cat.position.z = sin((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 5.0f) * 40.0f;
	world->cat.position.y= abs(sin((glutGet(GLUT_ELAPSED_TIME) / 1000.0f) * 5.0f)) * 40.0f;


	Room roomToDraw = world -> room;
	glEnable(GL_TEXTURE_2D);
	glClearDepth(1);

    glPushMatrix();
		draw_walls(roomToDraw);
		draw_ground(roomToDraw);
	glPopMatrix();

	glPushMatrix();

		GLfloat light_position[] = {0, 100, 150};//, 0};
		GLfloat light_diffuse[] = {0.3f, 0.3f, 0.3f, 0.9f};
		GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
		GLfloat shinnes [] = {50};
		GLfloat matdiffu[] = {1.0f, 0.f, 0.f, 1.0f};
		GLfloat matspec[] = {1.0f, 0.f, 0.f, 1.0f};
		glMaterialfv(GL_FRONT, GL_AMBIENT, light_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, light_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shinnes);


		glPushMatrix();
			glTranslatef(world->dog.position.x, world->dog.position.y, world->dog.position.z);
			glBindTexture(GL_TEXTURE_2D, world->dog.texture);
			glScalef(1.5f, 1.5f, 1.5f);
			glTranslatef(-50, -1, -70);
			glRotatef(-90,1,0,0);
			glRotatef(-90,0,0,1);
			draw_model(&world->dog.model);
		glPopMatrix();

		
		glPushMatrix();
			glTranslatef(world->cat.position.x, world->cat.position.y, world->cat.position.z);
			glBindTexture(GL_TEXTURE_2D, world->cat.texture);
			glScalef(1.5f, 1.5f, 1.5f);
			glTranslatef(-50, -1, -70);
			glRotatef(-90,1,0,0);
			glRotatef(-90,0,0,1);
			draw_model(&world->cat.model);
		glPopMatrix();

		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, world->couch.texture);
			glScalef(1.5f, 1.5f, 1.5f);
			glTranslatef(0, 0, 80);
			//glRotatef(-90,1,0,0);
			glRotatef(180,0,1,0);
			draw_model(&world->couch.model);
		glPopMatrix();
	glPopMatrix();

	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient_default);

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,matdiffu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,matspec);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,shinnes);
}

void draw_ground(Room room) {
	glBindTexture(GL_TEXTURE_2D, room.ground);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBegin(GL_QUADS);
	float x, z;
	float uvTile = 1.0f / (2.0f * sizeOfRoom / 50.0f);
	for (x = -sizeOfRoom; x < sizeOfRoom; x += 50.0f) {
		for (z = -sizeOfRoom; z < sizeOfRoom; z += 50.0f) {
			float uvX = x / sizeOfRoom / 2 + 0.5f;
			float uvY = z / sizeOfRoom / 2 + 0.5f;
			glTexCoord2f(uvX, uvY);
			glNormal3f(0, -1, 0);
			glVertex3f(x, 0, z);
			glTexCoord2f(uvX + uvTile, uvY);
			glNormal3f(0, -1, 0);
			glVertex3f(x + 50, 0, z);
			glTexCoord2f(uvX + uvTile, uvY + uvTile);
			glNormal3f(0, -1, 0);
			glVertex3f(x + 50, 0, z + 50);
			glTexCoord2f(uvX, uvY + uvTile);
			glNormal3f(0, -1, 0);
			glVertex3f(x, 0, z + 50);
		}
	}
	glEnd();
}
void draw_walls(Room room) {
	glBindTexture(GL_TEXTURE_2D, room.left);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-sizeOfRoom, 0, -sizeOfRoom);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-sizeOfRoom, sizeOfRoom, -sizeOfRoom);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-sizeOfRoom, sizeOfRoom, sizeOfRoom);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-sizeOfRoom, 0, sizeOfRoom);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, room.right);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(sizeOfRoom, 0, sizeOfRoom);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(sizeOfRoom, sizeOfRoom, sizeOfRoom);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(sizeOfRoom, sizeOfRoom, -sizeOfRoom);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(sizeOfRoom, 0, -sizeOfRoom);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, room.front);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-sizeOfRoom, 0, -sizeOfRoom);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(sizeOfRoom, 0, -sizeOfRoom);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(sizeOfRoom, sizeOfRoom, -sizeOfRoom);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-sizeOfRoom, sizeOfRoom, -sizeOfRoom);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, room.back);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-sizeOfRoom, 0, sizeOfRoom);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-sizeOfRoom, sizeOfRoom, sizeOfRoom);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(sizeOfRoom, sizeOfRoom, sizeOfRoom);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(sizeOfRoom, 0, sizeOfRoom);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, room.top);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(sizeOfRoom, sizeOfRoom, sizeOfRoom);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(sizeOfRoom, sizeOfRoom, -sizeOfRoom);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-sizeOfRoom, sizeOfRoom, -sizeOfRoom);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-sizeOfRoom, sizeOfRoom, sizeOfRoom);
	glEnd();
}

void draw_triangles(const struct Model* model)
{
	int i, k;
	int vertex_index, texture_index, normal_index;
	double x, y, z, normal_x, normal_y, normal_z, u, v;

	glBegin(GL_TRIANGLES);

	for (i = 0; i < model->n_triangles; ++i) {
		for (k = 0; k < 3; ++k) {
			normal_index = model->triangles[i].points[k].normal_index;
			normal_x = model->normals[normal_index].x;
			normal_y = model->normals[normal_index].y;
			normal_z = model->normals[normal_index].z;
			glNormal3d(normal_x, normal_y, normal_z);

			vertex_index = model->triangles[i].points[k].vertex_index;
			x = model->vertices[vertex_index].x;
			y = model->vertices[vertex_index].y;
			z = model->vertices[vertex_index].z;

			texture_index = model->triangles[i].points[k].texture_index;
			u = model->texture_vertices[texture_index].u;
			v = model->texture_vertices[texture_index].v;
			// NOTE: The 1-v is model file specific!
			glTexCoord2f(u, 1 - v);

			glVertex3d(x, y, z);

		}
	}

	glEnd();
}


void draw_quads(const struct Model* model)
{
    int i, k;
    int vertex_index, texture_index, normal_index;
    float x, y, z, u, v;

	glBegin(GL_QUADS);

    for (i = 0; i < model->n_quads; ++i) {
        for (k = 0; k < 4; ++k) {

            texture_index = model->quads[i].points[k].texture_index;
            u = model->texture_vertices[texture_index].u;
            v = model->texture_vertices[texture_index].v;
            // NOTE: The 1-v is model file specific!
            glTexCoord2f(u, 1-v);

            vertex_index = model->quads[i].points[k].vertex_index;
            x = model->vertices[vertex_index].x;
            y = model->vertices[vertex_index].y;
            z = model->vertices[vertex_index].z;
            glVertex3d(x, y, z);
        }
    }

    glEnd();
}

void draw_normals(const struct Model* model, double length)
{
	int i;
	float x1, y1, z1, x2, y2, z2;

	glColor3f(0, 0, 1);

	glBegin(GL_LINES);

	for (i = 0; i < model->n_vertices; ++i) {
		x1 = model->vertices[i].x;
		y1 = model->vertices[i].y;
		z1 = model->vertices[i].z;
		x2 = x1 + model->normals[i].x * length;
		y2 = y1 + model->normals[i].y * length;
		z2 = z1 + model->normals[i].z * length;
		glVertex3d(x1, y1, z1);
		glVertex3d(x2, y2, z2);
	}
	glEnd();
}

void draw_model(const struct Model* model)
{
	draw_triangles(model);
	draw_quads(model);
}

void draw_help(int texture) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);

	glTexCoord2f(1, 0);
	glVertex3f(WINDOW_WIDTH, 0, 0);

	glTexCoord2f(1, 1);
	glVertex3f(WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	glTexCoord2f(0, 1);
	glVertex3f(0, WINDOW_HEIGHT, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
