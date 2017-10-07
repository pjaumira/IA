#include "SceneKinematicFlocking.h"

#define NUMBER_AGENTS 6
#define SEPARATION_AGENTS 70

using namespace std;

SceneKinematicFlocking::SceneKinematicFlocking()
{
	for (int i = 0; i < NUMBER_AGENTS; i++) {
		Agent *agent = new Agent;
		agent->setPosition(Vector2D(200 + SEPARATION_AGENTS , 250 + SEPARATION_AGENTS * i));
		agent->setTarget(Vector2D(640, 360));
		agent->loadSpriteTexture("../res/soldier.png", 4);
		agents.push_back(agent);
		target = Vector2D(640, 360);
	}
}

SceneKinematicFlocking::~SceneKinematicFlocking()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneKinematicFlocking::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			for (int i = 0; i < NUMBER_AGENTS; i++) {
				agents[i]->setTarget(target);
			}
			
		}
		break;
	default:
		break;
	}
	for (int i = 0; i < NUMBER_AGENTS; i++) {
		Vector2D steering_force = agents[i]->Behavior()->Flocking(agents[i], agents[i]->getTarget(), dtime, agents);
		agents[i]->update(steering_force, dtime, event);
	}
	
}

void SceneKinematicFlocking::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	for (int i = 0; i < NUMBER_AGENTS; i++) {
		agents[i]->draw();
	}
}

const char* SceneKinematicFlocking::getTitle()
{
	return "SDL Steering Behaviors :: Flocking";
}