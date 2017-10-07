#pragma once
#include "Agent.h"
#include "Vector2D.h"
#include <vector>

class Agent;

class SteeringBehavior
{
public:
	SteeringBehavior();
	~SteeringBehavior();

	//Dummy Seek
	Vector2D KinematicSeek(Agent *agent, Vector2D target, float dtime);
	Vector2D KinematicSeek(Agent *agent, Agent *target, float dtime);

	//Dummy Flee
	Vector2D KinematicFlee(Agent *agent, Vector2D target, float dtime);
	Vector2D KinematicFlee(Agent *agent, Agent *target, float dtime);

	/* Add here your own Steering Behavior functions declarations */

	// Seek
	Vector2D Seek(Agent *agent, Vector2D target, float dtime);
	Vector2D Seek(Agent *agent, Agent *target, float dtime);

	//Flee
	Vector2D Flee(Agent *agent, Vector2D target, float dtime);
	Vector2D Flee(Agent *agent, Agent *target, float dtime);

	//Arrive
	Vector2D Arrive(Agent *agent, Vector2D target, float dtime);
	Vector2D Arrive(Agent *agent, Agent *target, float dtime);

	//Pursue
	Vector2D Pursue(Agent *agent, Vector2D target, float dtime);
	Vector2D Pursue(Agent *agent, Agent *target, float dtime);

	//Evade
	Vector2D Evade(Agent *agent, Vector2D target, float dtime);
	Vector2D Evade(Agent *agent, Agent *target, float dtime);

	//Wander
	Vector2D Wander(Agent *agent, Vector2D target, float dtime);
	Vector2D Wander(Agent *agent, Agent *target, float dtime);

	//Flocking
	Vector2D Flocking(Agent *agent, Vector2D target, float dtime, std::vector<Agent*> agents);
	Vector2D Flocking(Agent *agent, Agent *target, float dtime);
};
