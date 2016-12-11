/*
 * Camera.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#include "Camera.h"

Camera::Camera(GLfloat x, GLfloat y, GLfloat z, World* world):
x(x), y(y), z(y)
{
	rx = 0;
	ry = 0;
	rz = 0;
	this->world = world;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::translate_gl() {
	glTranslatef(-x, y, z);
}

void Camera::rotate_gl(){
	glRotatef(rx, 1, 0, 0);
	glRotatef(ry, 0, 1, 0);
	glRotatef(rz, 0, 0, 1);
}
