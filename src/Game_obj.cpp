/*
 * Drawable.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: carl
 */

#include "Game_obj.h"
#include <iostream>

Game_obj::Game_obj(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Game_obj::~Game_obj() {

}

void Game_obj::render() {
	//std::cout << "basic obj here" << std::endl;
}

