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
#ifndef SlowingRadius
	const int SlowingRadius = 200;
#endif // !SlowingRadius

	//Radius circle
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, SlowingRadius, 255, 255, 255, 255);

	float distanceToTarget = Vector2D::Distance(target, agent->position);
	Vector2D ArriveSpeed = agent->max_velocity;
	float speedFactor = 1.0f;

	//Seek
	Vector2D DesiredVelocity = target - agent->position;
	DesiredVelocity.Normalize();

	if (distanceToTarget > SlowingRadius)
	{
		DesiredVelocity *= agent->max_velocity;
	}
	else {
		DesiredVelocity *= agent->max_velocity * (distanceToTarget / SlowingRadius);
	}
	
	Vector2D SteeringForce = (DesiredVelocity - agent->velocity);
	SteeringForce /= agent->max_velocity;
	
	return SteeringForce * agent->max_force;
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
	Vector2D DistanceToTarget = target->position - agent->position;
	float t = hypot(DistanceToTarget.x, DistanceToTarget.y) / agent->max_velocity;
	Vector2D TargetPosition = target->position + (target->getVelocity() * t);
	return Seek(agent, TargetPosition, dtime);
}

//Evade
Vector2D SteeringBehavior::Evade(Agent *agent, Vector2D target, float dtime)
{
	return Vector2D(0, 0);
}

Vector2D SteeringBehavior::Evade(Agent *agent, Agent *target, float dtime)
{
	Vector2D DistanceToTarget = target->position - agent->position;
	float t = hypot(DistanceToTarget.x, DistanceToTarget.y) / agent->max_velocity;
	Vector2D TargetPosition = target->position + (target->getVelocity() * t);
	return Flee(agent, TargetPosition, dtime);
}

//Wander
Vector2D SteeringBehavior::Wander(Agent *agent, Vector2D target, float dtime)
{
	////Maximum Change of Angle in one frame
	//const float WanderMaxAngleChange = 30;

	////Distance from Agent to Wander Circle Center
	//const float WanderOffset = 200;

	////Radius of Wander Circle
	//const float WanderRadius = 100;

	//float RandomBinomial = 0.0f;
	//float TargetAngle = 0.0f;

	////Update Wander Angle
	//if (agent->wanderCounter > 1000.0f) {
	//	RandomBinomial = ((float)rand() / (RAND_MAX)) - ((float)rand() / (RAND_MAX));
	//	agent->wanderAngle += RandomBinomial * WanderMaxAngleChange;
	//	TargetAngle = agent->orientation + agent->wanderAngle;

	//	agent->wanderCounter = 0.0f;
	//}
	//agent->wanderCounter += 1.0f;
	////crear un contador aqui para frenar la ejecución medio segundo, por ejemplo
	////el contador se debe alojar en agent o en algun otro lado, porque sino la ejecución se encalla aqui

	////Calculate new wander Position
	//Vector2D CircleCenter = agent->position + Vector2D::Normalize(agent->velocity) * WanderOffset;

	//Vector2D TargetPosition = (0, 0);

	//TargetPosition.x = CircleCenter.x + WanderRadius * cos(TargetAngle);
	//TargetPosition.y = CircleCenter.y + WanderRadius * sin(TargetAngle);

	//return TargetPosition;
	return Vector2D(0, 0);
}

Vector2D SteeringBehavior::Wander(Agent *agent, Agent *target, float dtime)
{
	return Wander(agent, target->position, dtime);
}