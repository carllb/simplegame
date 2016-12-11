/*
 * World.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <iostream>
#include "World.h"
#include "Cube.h"

World::World() :
		cam(0, 0, 0, this), head(NULL), tail(NULL) {

}

World::~World() {
	recursive_clear(head);
}

World::Node* World::add_obj(Game_obj* obj) {
	if (head == NULL){
		head = new Node;
		head->obj = obj;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
	}else{
		tail->next = new Node;
		tail->next->obj = obj;
		tail->next->prev = tail;
		tail = tail->next;
	}
	return tail;
}

void World::remove_obj(World::Node* node) {
	if (node->prev == NULL){ //node is at the head
		head = node->next;
		if (head != NULL){
			head->prev = NULL;
		}else{ // the removed node is the only node in the linked list
			tail = NULL;
		}
		delete(node);
	}else if(tail == NULL){// node is at the end
		tail->prev->next == NULL;
		tail = tail->prev;
		delete(node);
	}else{// somewhere in the middle
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete(node);
	}
}


void World::draw() {

	/* Clear the color and depth buffers. */
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* We don't want to modify the projection matrix. */
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	/* Move down the z-axis. */
	cam.translate_gl();
	cam.rotate_gl();

	/* Rotate. */
	//glRotatef( angle, 1, 1.0, 1);
	World::Node* curr = head;
	while(curr != NULL){
		curr->obj->render();
		curr = curr->next;
	}

	glPopMatrix();
	SDL_GL_SwapBuffers( );
}

Camera* World::get_camera(){
	return &cam;
}

void World::clear_objs(){
	recursive_clear(head);
}

void World::recursive_clear(World::Node* node){
	if (node != NULL){
		recursive_clear(node->next);
		delete(node);
	}
}

