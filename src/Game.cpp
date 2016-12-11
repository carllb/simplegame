/*
 * Game.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#include <iostream>

#include "Game.h"
#include "Cube.h"
using namespace std;

#define FIELD_OF_VIEW 60.0
#define FPS 60.0

Game::Game(int width, int height) :
		width(width), height(height), runnung(true), start(0), end(0) {

}

Game::~Game() {
	SDL_Quit();
}

void Game::init() {
	setup_SDL();
	init_opengl();
	Cube cube(10, 10, 10);
	cube.k = -20;
	world.add_obj(&cube);

	world.get_camera()->z = -100;

	begin_loop();

}

void Game::setup_SDL() {
	/* Information about the current video settings. */
	const SDL_VideoInfo* info = NULL;

	/* Color depth in bits of our window. */
	int bpp = 0;
	/* Flags we will pass into SDL_SetVideoMode. */
	int flags = 0;

	/* First, initialize SDL's video subsystem. */
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		/* Failed, exit. */
		fprintf( stderr, "Video initialization failed: %s\n", SDL_GetError());

	}

	/* Let's get some video information. */
	info = SDL_GetVideoInfo();

	if (!info) {
		/* This should probably never happen. */
		fprintf( stderr, "Video query failed: %s\n", SDL_GetError());

	}

	/*
	 * Set our width/height to 640/480 (you would
	 * of course let the user decide this in a normal
	 * app). We get the bpp we will request from
	 * the display. On X11, VidMode can't change
	 * resolution, so this is probably being overly
	 * safe. Under Win32, ChangeDisplaySettings
	 * can change the bpp.
	 */
	bpp = info->vfmt->BitsPerPixel;

	/*
	 * Now, we want to setup our requested
	 * window attributes for our OpenGL window.
	 * We want *at least* 5 bits of red, green
	 * and blue. We also want at least a 16-bit
	 * depth buffer.
	 *
	 * The last thing we do is request a double
	 * buffered window. '1' turns on double
	 * buffering, '0' turns it off.
	 *
	 * Note that we do not use SDL_DOUBLEBUF in
	 * the flags to SDL_SetVideoMode. That does
	 * not affect the GL attribute state, only
	 * the standard 2D blitting setup.
	 */
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	/*
	 * We want to request that SDL provide us
	 * with an OpenGL window, in a fullscreen
	 * video mode.
	 *
	 * EXERCISE:
	 * Make starting windowed an option, and
	 * handle the resize events properly with
	 * glViewport.
	 */
	flags = SDL_OPENGL; // | SDL_FULLSCREEN;

	/*
	 * Set the video mode
	 */
	if (SDL_SetVideoMode(width, height, bpp, flags) == 0) {
		/*
		 * This could happen for a variety of reasons,
		 * including DISPLAY not being set, the specified
		 * resolution not being available, etc.
		 */
		fprintf( stderr, "Video mode set failed: %s\n", SDL_GetError());

	}
}

void Game::init_opengl() {
	float ratio = (float) width / (float) height;

	/* Our shading model--Gouraud (smooth). */
	glShadeModel( GL_SMOOTH);

	/* Culling. */
	glCullFace( GL_BACK);
	glFrontFace( GL_CCW);
	glEnable( GL_CULL_FACE);

	/* Set the clear color. */
	glClearColor(0, 0, 0, 0);

	/* Setup our viewport. */
	glViewport(0, 0, width, height);

	/*
	 * Change to the projection matrix and set
	 * our viewing volume.
	 */
	glMatrixMode( GL_PROJECTION);
	glLoadIdentity();
	/*
	 * EXERCISE:
	 * Replace this with a call to glFrustum.
	 */
	gluPerspective(FIELD_OF_VIEW, ratio, 1.0, 1024.0);

}

void Game::begin_loop() {
	while (runnung) {
		start = SDL_GetTicks();
		/* Process incoming events. */
		proccess_events();

		/* Draw the screen. */
		world.draw();

		// linit fps
		end = SDL_GetTicks();

		double mspf = 1000.0 / FPS;
		double diff = end - start;

		if (mspf > diff) {
			std::cout << mspf - diff << std::endl;
			SDL_Delay(mspf - diff);
		}

		//move the camera
		Uint8* keys = SDL_GetKeyState(NULL);
		if (keys[SDLK_w]) {
			world.get_camera()->z++;
		}
		if (keys[SDLK_a]) {
			world.get_camera()->x--;
		}
		if (keys[SDLK_s]) {
			world.get_camera()->z--;
		}
		if (keys[SDLK_d]) {
			world.get_camera()->x++;
		}

	}
}

void Game::proccess_events() {
	/* Our SDL event placeholder. */
	SDL_Event event;

	/* Grab all the events off the queue. */
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_KEYDOWN:
			/* Handle key presses. */
			handle_input(&event.key.keysym);
			break;
		case SDL_QUIT:
			/* Handle quit requests (like Ctrl-c). */
			runnung = false;
			break;
		}

	}
}

void Game::handle_input(SDL_keysym* keysym) {
	SDL_PumpEvents();
	switch (keysym->sym) {
	/*
	 case SDLK_w:
	 world.get_camera()->z++;
	 //cout << "key w" << endl;
	 break;
	 case SDLK_a:
	 world.get_camera()->x--;
	 //cout << "key a" << endl;
	 break;

	 case SDLK_s:
	 world.get_camera()->z--;
	 //cout << "key s" << endl;
	 break;

	 case SDLK_d:
	 world.get_camera()->x++;
	 //cout << "key d" << endl;
	 break;
	 */
	default:
		;
	}
}

