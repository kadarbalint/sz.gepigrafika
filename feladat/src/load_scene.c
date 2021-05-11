#include "scene.h"
#include "texture.h"
#include "load.h"

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_object(Object* object, int x, int z)
{
	object->position.x = x;
	object->position.y = 0;
	object->position.z = z;

	object->material_ambient[0] = 1;
	object->material_ambient[1] = 1;
	object->material_ambient[2] = 1;
	object->material_ambient[3] = 0.5;
}

void init_entities(World* world) {

		load_model(&world->cat.model, "data/models//cat.obj");
	world->cat.texture = load_texture("data/textures//cat.jpg");
	init_object(&world->cat, 120, 170);

	// dog
	load_model(&world->dog.model, "data/models//dog.obj");
	world->dog.texture = load_texture("data/textures//dog.jpg");
	init_object(&world->dog, 120, 170);

    // couch
	load_model(&world->couch.model, "data/models//couch2.obj");
	world->couch.texture = load_texture("data/textures//couch2.png");
	init_object(&world->couch, 0, 0);

	// Room
		world->room.ground = load_texture("data/textures//simpsonsfloor.jpg");
	world->room.back = load_texture("data/textures//simpsonswallpicture.jpg");
	world->room.front = load_texture("data/textures//simpsonswalltv.jpg");
	world->room.left = load_texture("data/textures//simpsonswalldoor.jpg");
	world->room.right = load_texture("data/textures//simpsonswallnopicture.jpg");
	world->room.top = load_texture("data/textures//simpsonsceiling.jpg");
	
	// Help
	world->helpTexture = load_texture("data/textures//help1.png");
}
