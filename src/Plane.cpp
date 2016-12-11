/*
 * Plane.cpp
 *
 *  Created on: Dec 9, 2016
 *      Author: carl
 */

#include "Plane.h"
#include "GL/gl.h"

Plane::Plane() {
	// TODO Auto-generated constructor stub

}

Plane::~Plane() {
	// TODO Auto-generated destructor stub
}

void Plane::render() {
	glPushMatrix();
	/* Move down the z-axis. */
	glTranslatef(x, y, z);

	glColor3f(1, 0, 1);
	glVertex3f(-10, -10, -10);
	glVertex3f(10, -10, -10);
	glVertex3f(-10, -10, 10);

	glPopMatrix();

	/* Send our triangle data to the pipeline. */
	glBegin( GL_TRIANGLES);
}

