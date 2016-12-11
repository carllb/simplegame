/*
 * Camera.h
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <GL/gl.h>
#include <GL/glu.h>

class World;

class Camera {
public:
	Camera(GLfloat x, GLfloat y, GLfloat z, World* world);
	virtual ~Camera();

	void translate_gl();
	void rotate_gl();
	GLfloat x, y, z;
	GLfloat rx, ry, rz;

private:
	World* world;

};

#endif /* CAMERA_H_ */
