/*
 * Drawable.h
 *
 *  Created on: Dec 2, 2016
 *      Author: carl
 */

#ifndef GAME_OBJ_H_
#define GAME_OBJ_H_

class Game_obj {
public:
	Game_obj(int x, int y, int z);
	virtual ~Game_obj();

	virtual void render();
	int x,y,z;
};

#endif /* GAME_OBJ_H_ */
