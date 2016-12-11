/*
 * Cube.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: carl
 */

#include <iostream>
#include "Cube.h"
#include "GL/gl.h"

Cube::Cube(int x, int y, int z) :
		Game_obj(x, y, z), k(2) {

}

Cube::~Cube() {

}

void Cube::render() {
	//std::cout << "rendering cube" << std::endl;
	static GLfloat v0[] = { -1.0f, -1.0f, 1.0f };
	static GLfloat v1[] = { 1.0f, -1.0f, 1.0f };
	static GLfloat v2[] = { 1.0f, 1.0f, 1.0f };
	static GLfloat v3[] = { -1.0f, 1.0f, 1.0f };
	static GLfloat v4[] = { -1.0f, -1.0f, -1.0f };
	static GLfloat v5[] = { 1.0f, -1.0f, -1.0f };
	static GLfloat v6[] = { 1.0f, 1.0f, -1.0f };
	static GLfloat v7[] = { -1.0f, 1.0f, -1.0f };
	static GLubyte red[] = { 255, 0, 0, 255 };
	static GLubyte green[] = { 0, 255, 0, 255 };
	static GLubyte blue[] = { 0, 0, 255, 255 };
	static GLubyte white[] = { 255, 255, 255, 255 };
	static GLubyte yellow[] = { 0, 255, 255, 255 };
	static GLubyte black[] = { 0, 0, 0, 255 };
	static GLubyte orange[] = { 255, 255, 0, 255 };
	static GLubyte purple[] = { 255, 0, 255, 0 };

//	/* Clear the color and depth buffers. */
//	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* We don't want to modify the projection matrix. */
//	glMatrixMode( GL_MODELVIEW);
//	glLoadIdentity();
	glPushMatrix();
	/* Move down the z-axis. */
	glTranslatef(x, y, z);

	/* Send our triangle data to the pipeline. */
	glBegin( GL_TRIANGLES);

	glColor4ubv(red);
	glVertex3fv(v0);
	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(blue);
	glVertex3fv(v2);

	glColor4ubv(red);
	glVertex3fv(v0);
	glColor4ubv(blue);
	glVertex3fv(v2);
	glColor4ubv(white);
	glVertex3fv(v3);

	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(black);
	glVertex3fv(v5);
	glColor4ubv(orange);
	glVertex3fv(v6);

	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(orange);
	glVertex3fv(v6);
	glColor4ubv(blue);
	glVertex3fv(v2);

	glColor4ubv(black);
	glVertex3fv(v5);
	glColor4ubv(yellow);
	glVertex3fv(v4);
	glColor4ubv(purple);
	glVertex3fv(v7);

	glColor4ubv(black);
	glVertex3fv(v5);
	glColor4ubv(purple);
	glVertex3fv(v7);
	glColor4ubv(orange);
	glVertex3fv(v6);

	glColor4ubv(yellow);
	glVertex3fv(v4);
	glColor4ubv(red);
	glVertex3fv(v0);
	glColor4ubv(white);
	glVertex3fv(v3);

	glColor4ubv(yellow);
	glVertex3fv(v4);
	glColor4ubv(white);
	glVertex3fv(v3);
	glColor4ubv(purple);
	glVertex3fv(v7);

	glColor4ubv(white);
	glVertex3fv(v3);
	glColor4ubv(blue);
	glVertex3fv(v2);
	glColor4ubv(orange);
	glVertex3fv(v6);

	glColor4ubv(white);
	glVertex3fv(v3);
	glColor4ubv(orange);
	glVertex3fv(v6);
	glColor4ubv(purple);
	glVertex3fv(v7);

	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(red);
	glVertex3fv(v0);
	glColor4ubv(yellow);
	glVertex3fv(v4);

	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(yellow);
	glVertex3fv(v4);
	glColor4ubv(black);
	glVertex3fv(v5);

	glEnd();

	glPopMatrix();
}

