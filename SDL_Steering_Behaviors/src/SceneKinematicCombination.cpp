#include "SceneKinematicCombination.h"



SceneKinematicCombination::SceneKinematicCombination()
{
	Agent *agent = new Agent();
	agent->setPosition(Vector2D(600, 50));
	agent->setTarget(Vector2D(900, 650));
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agents.push_back(agent);
	target = Vector2D(900, 650);
	agent = new Agent;
	agent->setTarget(Vector2D(100, 100));
	agent->setMass(0.6f);
	agent->setColor(0, 0, 255, 255);
	agent->loadSpriteTexture("../res/zombie1.png", 8);
	agents.push_back(agent);
	agent = new Agent;
	agent->setPosition(Vector2D(600, 400));
	agent->setTarget(Vector2D(100, 100));
	agent->setMass(0.6f);
	agent->setColor(0, 0, 255, 255);
	agent->loadSpriteTexture("../res/zombie1.png", 8);
	agents.push_back(agent);

	wanderRadius = 100;
}


SceneKinematicCombination::~SceneKinematicCombination()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneKinematicCombination::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			agents[0]->setTarget(target);
		}
		break;
	default:
		break;
	}
	//Soldado
	Vector2D steering_force = agents[0]->Behavior()->Arrive(agents[0], agents[0]->getTarget(), dtime);
	float distance=Vector2D::Distance(agents[0]->getPosition(), agents[1]->getPosition());

	for (int i = 1; i < 3; i++)
	{
		distance = Vector2D::Distance(agents[0]->getPosition(), agents[i]->getPosition());
		if (distance<wanderRadius)
			steering_force += agents[0]->Behavior()->Evade(agents[0], agents[i], dtime);
	}
	agents[0]->update(steering_force, dtime, event);

	//Zombis
	for (int i = 1; i < 3; i++)
	{
		agents[i]->setTarget(agents[0]->getPosition());
		steering_force = agents[i]->Behavior()->Pursue(agents[i], agents[0], dtime);
		steering_force += agents[i]->Behavior()->Flocking(agents[i], agents[i]->getTarget(), dtime, agents);
		agents[i]->update(steering_force, dtime, event);
	}
}

void SceneKinematicCombination::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	for (int i = 0; i < (int)agents.size(); i++)
	{
		agents[i]->draw();
	}
}

const char* SceneKinematicCombination::getTitle()
{
	return "SDL Steering Behaviors :: Evade";
}
