#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "SDL_SimpleApp.h"
#include "SceneKinematicSeek.h"
#include "SceneKinematicFlee.h"
#include "SceneKinematicArrive.h"
#include "SceneKinematicPursue.h"
#include "SceneKinematicEvade.h"
#include "SceneKinematicWander.h"

using namespace std;

int main(int argc, char ** argv)
{
	bool quit = false;
	SDL_Event event;

	SDL_SimpleApp *app = SDL_SimpleApp::Instance();

	Scene *curr_scene = new SceneKinematicSeek;
	app->setWindowTitle(curr_scene->getTitle());

	while (!quit)
	{
		// run app frame by frame
		event = app->run(curr_scene);

		/* Keyboard events */
		switch (event.type)
		{
		case SDL_KEYDOWN:
			//Seek
			if (event.key.keysym.scancode == SDL_SCANCODE_1)
			{
				delete(curr_scene);
				curr_scene = new SceneKinematicSeek;
				app->setWindowTitle(curr_scene->getTitle());
			}
			//Flee
			if (event.key.keysym.scancode == SDL_SCANCODE_2)
			{
				delete(curr_scene);
				curr_scene = new SceneKinematicFlee;
				app->setWindowTitle(curr_scene->getTitle());
			}
			//Arrive
			if (event.key.keysym.scancode == SDL_SCANCODE_3)
			{
				delete(curr_scene);
				curr_scene = new SceneKinematicArrive;
				app->setWindowTitle(curr_scene->getTitle());
			}
			//Pursue
			if (event.key.keysym.scancode == SDL_SCANCODE_4)
			{
				delete(curr_scene);
				curr_scene = new SceneKinematicPursue;
				app->setWindowTitle(curr_scene->getTitle());
			}
			//Evade
			if (event.key.keysym.scancode == SDL_SCANCODE_5)
			{
				delete(curr_scene);
				curr_scene = new SceneKinematicEvade;
				app->setWindowTitle(curr_scene->getTitle());
			}
			//Wander
			if (event.key.keysym.scancode == SDL_SCANCODE_6)
			{
				delete(curr_scene);
				curr_scene = new SceneKinematicWander;
				app->setWindowTitle(curr_scene->getTitle());
			}


			if ((event.key.keysym.scancode == SDL_SCANCODE_Q) || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			{
				quit = true;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_F)
			{
				app->setFullScreen();
			}
			break;
		case SDL_QUIT:
			quit = true;
			break;
		}

	}

	return 0;
}