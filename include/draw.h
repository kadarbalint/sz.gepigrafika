/**
 * draw.h
 */

#include "model.h"
 
#ifndef INCLUDE_DRAW_H_
#define INCLUDE_DRAW_H_

#ifndef GL_EXT_texture_edge_clamp
#define GL_CLAMP_TO_EDGE                 0x812F
#endif

/**
 * Content.
 */
void draw_content(World* world);

/**
* Ground.
*/
void draw_ground(Room room);

/*
* Room.
*/
void draw_walls(Room room);

/**
* Model.
*/
void draw_model(const struct Model* model);

/*
* Help menu.
*/
void draw_help(int texture);

#endif /* INCLUDE_DRAW_H_ */
