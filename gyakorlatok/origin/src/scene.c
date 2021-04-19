#include "scene.h"

#include <GL/glut.h>

#include <math.h>

void init_scene(Scene* scene)
{
}

void draw_scene(const Scene* scene)
{
	int i;
    draw_origin();
	glPushMatrix();
	for(i=0;i<10;i++){
		draw_cylinder();
		glScalef(1,1,1.5);
		glTranslatef(0,1,0);
	}
	glPopMatrix();
	glBegin(GL_TRIANGLES);

    glColor3f(1, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 1, 0);
 

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 1);

    glEnd();
}
void draw_cylinder()
{
	float x,y,phi,h;
	
	glPushMatrix();
	glBegin(GL_QUAD_STRIP);
	
	phi=0.0;
	h=1.0;
	glColor3f(0, 1, 0);
	while (phi<3.14){
		x=cos(phi);
		y=sin(phi);
		glColor3f(phi/3.14, phi+1, phi+1);
		 glVertex3f(x, y, 0);
		  glVertex3f(x, y, h);
		  phi += 0.01;
		  
	}
	

    glEnd();
	
	glPopMatrix();
}
void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
