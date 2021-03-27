#ifndef ENTITY_TEST_H
#define ENTITY_TEST_H

#include "../Math/Vector3D.h"
#include "physicsObject.h"
#include "collisionObject.h"

/*
 * Example of entity to use with PhysicsEngine.
 */

class Entity
{
public:
	// Let's build a simple ball
	Entity(Vector3 position, Vector3 velocity, Vector3 acceleration, double mass,Vector3 width):
		m_position(position),
		m_velocity(velocity),
		m_acceleration(acceleration),
       		m_mass(mass),
		entityPhys(position,velocity,acceleration,mass),
		entityObj(position,width,bouncyBall) {}

	PhysicsObject entityPhys; 
	CollisionObject entityObj;
	Vector3 test;

	// Get func
	Vector3 getPosition(){ return m_position; };	
	Vector3 getVelocity(){ return m_velocity; };	
	Vector3 getAcceleration(){ return m_acceleration; };	
private:
	Vector3 m_position;
	Vector3 m_velocity;
	Vector3 m_acceleration;
	double m_mass;
};

#endif
