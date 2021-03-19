#include "forces.h"

void ForcesRegistry::updateForces(double delta)
{
	Registry::iterator i = registrations.begin();
	for (; i != registrations.end(); i++)
	{
		i->forces->updateForce(i->PhysObj, delta);
	}
}

void ParticleGravity::updateForce(PhysicsObject *PhysObj, double delta)
{
	PhysObj->addForce(gravity / PhysObj->GetMass());
}
