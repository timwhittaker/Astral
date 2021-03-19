#ifndef FORCES_INCLUDED_H
#define FORCES_INCLUDED_H

/* 
 * Force interface
 * Code based off of Ch5 of Ian Millington's book
 */
#include <vector>
#include "physicsObject.h"

// Generate forces
class Forces
{
public:
	virtual void updateForce(PhysicsObject *PhysObj, double delta) = 0;
private:
};


// Store all the forces
class ForcesRegistry
{
protected:
	struct ForceRegister
	{
		PhysicsObject *PhysObj;
		Forces *forces;
	};

	typedef std::vector<ForceRegister> Registry;
	Registry registrations;

public:
	void add(PhysicsObject *PhysObj,Forces *forces);
	void remove(PhysicsObject *PhysObj,Forces *forces);
	void clear();
	void updateForces(double delta);
};

// Gravity force
class ParticleGravity : public Forces
{
	Vector3 gravity;
public:
	ParticleGravity(const Vector3 &gravity);
	virtual void updateForce(PhysicsObject *PhysObj, double delta);
};	

#endif
