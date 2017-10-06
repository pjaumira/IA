#include "SteeringBehavior.h"



SteeringBehavior::SteeringBehavior()
{
}


SteeringBehavior::~SteeringBehavior()
{
}

//Dummy Seek
Vector2D SteeringBehavior::KinematicSeek(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	return steering * agent->max_velocity;
}

Vector2D SteeringBehavior::KinematicSeek(Agent *agent, Agent *target, float dtime)
{
	return KinematicSeek(agent, target->position, dtime);
}

// Dummy Flee
Vector2D SteeringBehavior::KinematicFlee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = agent->position - target;
	steering.Normalize();
	return steering * agent->max_velocity;
}

Vector2D SteeringBehavior::KinematicFlee(Agent *agent, Agent *target, float dtime)
{
	return KinematicFlee(agent, target->position, dtime);
}

/* Add here your own Steering Behavior functions definitions */

//Seek
//Algoritmo implementado
Vector2D SteeringBehavior::Seek(Agent *agent, Vector2D target, float dtime)
{
	Vector2D DesiredVelocity = target - agent->position;
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->max_velocity;
	Vector2D SteeringForce = (DesiredVelocity - agent->velocity);
	SteeringForce /= agent->max_velocity;
	return SteeringForce * agent->max_force;
}

Vector2D SteeringBehavior::Seek(Agent *agent, Agent *target, float dtime)
{
	return Seek(agent, target->position, dtime);
}

//Flee
Vector2D SteeringBehavior::Flee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D DesiredVelocity = agent->position - target;
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->max_velocity;
	return DesiredVelocity;
}

Vector2D SteeringBehavior::Flee(Agent *agent, Agent *target, float dtime)
{
	return Flee(agent, target->position, dtime);
}

//Arrive
Vector2D SteeringBehavior::Arrive(Agent *agent, Vector2D target, float dtime)
{
	// Radius to start slowing down
	const int SlowingRadius = 2;

	/*float distanceToTarget = target - agent->position;
	Vector2D ArriveSpeed = agent->max_velocity;
	float speedFactor = 1.0f;
	if (distanceToTarget < SlowingRadius)
	{
		speedFactor = (distanceToTarget / SlowingRadius);
	}
	ArriveSpeed *= speedFactor;
	
	return ArriveSpeed;
	*/
	return Vector2D(0, 0);
}

Vector2D SteeringBehavior::Arrive(Agent *agent, Agent *target, float dtime)
{
	return Arrive(agent, target->position, dtime);
}

//Pursue
Vector2D SteeringBehavior::Pursue(Agent *agent, Vector2D target, float dtime)
{

	return Vector2D(0, 0);
}

Vector2D SteeringBehavior::Pursue(Agent *agent, Agent *target, float dtime)
{
	////Comprobar si target necessita canvis per ser un altre "agent"
	////Vector2D T = (target->position - agent->position)/agent->velocity;
	//Vector2D predictedTarget = target->position + target->velocity * (target->position - agent->position) / agent->velocity;

	//// Maximum Time to look ahead to calculate FuturePosition
	//const float MaxLookAheadTime = 50;

	//// If TimeLookAhead is too big, the prediction can be
	//// misleading, limit TimeLookAhead
	//if (TimeLookAhead > MaxLookAheadTime)
	//	TimeLookAhead = MaxLookAheadTime;

	//return Pursue(agent, target->position, dtime);
	return Vector2D(0, 0);
}

//Evade
Vector2D SteeringBehavior::Evade(Agent *agent, Vector2D target, float dtime)
{
	return Vector2D(0, 0);
}

Vector2D SteeringBehavior::Evade(Agent *agent, Agent *target, float dtime)
{
	return Evade(agent, target->position, dtime);
}

//Wander
Vector2D SteeringBehavior::Wander(Agent *agent, Vector2D target, float dtime)
{
	return Vector2D(0, 0);
}

Vector2D SteeringBehavior::Wander(Agent *agent, Agent *target, float dtime)
{
	return Wander(agent, target->position, dtime);
}