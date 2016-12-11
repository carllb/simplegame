/*
 * Cube.h
 *
 *  Created on: Dec 2, 2016
 *      Author: carl
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Game_obj.h"

class Cube: public Game_obj {
public:
	Cube(int x, int y, int z);
	virtual ~Cube();

	virtual void render();

	int k;
};

#endif /* CUBE_H_ */
