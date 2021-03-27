#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

/*
 * PhysicsEngine.
 * The idea is to hold all the entities here.
 * The entities may contain physics components
 * collision components. The PhysicsEngine
 * can be called to resolve all collisions
 * and update forces, positions, velocities.
 */


#include <iostream>
#include <vector>
#include "collisionObject.h"
#include "physicsObject.h"

class PhysicsEngine
{
public:
	PhysicsEngine() {}
	void addEntityPhysics(PhysicsObject *p);
	void addEntityCollision(CollisionObject *c);
	void rmEntityPhysics();
	void rmEntityCollision();
	void resolveCollision();
	void updateKinematics(double dt);
	void findForces();
	void displayObjects();
private:

	// Maybe i should make some linked list for this?
	std::vector<PhysicsObject*> physObjList;
	std::vector<CollisionObject*> CollisionObjList;
};

#endif
