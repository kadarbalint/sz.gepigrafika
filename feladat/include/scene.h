#ifndef INCLUDE_SCENE_H
#define INCLUDE_SCENE_H

#include "model.h"
#include <stdio.h>
#include <GL/glut.h>
#include "SOIL/SOIL.h"

typedef struct {
    Model model;
    float material_ambient[4];
    int texture;
    struct Vertex position;
}Object;

typedef struct {
    int front, back, left, right, ground, top;
}Room;

typedef struct {
	Room room;
	Object dog;
    Object cat;
    Object couch;
	int helpTexture;
}World;

World world;

/**
 * Initialize my entities
 */
void init_entities(World* world);

#endif 
