/*
 * World.h
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Camera.h"
#include "Game_obj.h"



class World {
	typedef struct node{
		struct node* prev;
		Game_obj* obj;
		struct node* next;
	}Node;
public:
	World();
	virtual ~World();

	/**
	 * Adds a copy of the object to the vector and returns an object id
	 */
	Node* add_obj(Game_obj* obj);

	void remove_obj(Node* node);

	void draw();

	Camera* get_camera();

	void clear_objs();

private:
	//std::vector<Game_obj> objs;
	Node* head;
	Node* tail;
	Camera cam;
	void recursive_clear(Node* node);

};

#endif /* WORLD_H_ */
