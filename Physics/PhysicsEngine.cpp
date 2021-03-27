#include <iostream>
#include "PhysicsEngine.h"

/*
 * PhysicsEngine.
 * The idea is to hold all the entities here.
 * The entities may contain physics components
 * collision components. The PhysicsEngine
 * can be called to resolve all collisions
 * and update forces, positions, velocities.
 */


void PhysicsEngine::addEntityPhysics(PhysicsObject *p)
{
	// insert new object at end 
	physObjList.insert(physObjList.end(),p);
}

void PhysicsEngine::addEntityCollision(CollisionObject *c)
{
	// insert new object at end 
	CollisionObjList.insert(CollisionObjList.end(),c);
}

void PhysicsEngine::rmEntityPhysics()
{}

void PhysicsEngine::rmEntityCollision()
{}

void PhysicsEngine::resolveCollision()
{
	// Loop through collision objects and find which objects are colliding.
	// Then make appropriate update depending on collisionType.
	// **Probably don't need to check every object. Should change this**
	for (int i = 0; i < CollisionObjList.size(); i++)
	{
		for (int j = i+1; j < CollisionObjList.size(); j++)
		{
			std::cout<<"Checking collisions"<<std::endl;
			// Check if i,j are colliding
			// First check what type of collision we are dealing with
			if(CollisionObjList[i]->AABBCollision(*CollisionObjList[j]))
			{
				std::cout<<"Here"<<std::endl;
			}
		}
	}
}

void PhysicsEngine::updateKinematics(double dt)
{
	// Go through physics objects and run simulation
	for (int i = 0; i <  physObjList.size(); i++)
	{
		physObjList[i]->SimulateObject(dt);
		// Update collision box
		CollisionObjList[i]->setPosition(physObjList[i]->GetPosition());
	}
}

void PhysicsEngine::findForces()
{}

void PhysicsEngine::displayObjects()
{
	for(int i = 0; i < physObjList.size(); i++)
	{
		std::cout<< "Object at:" << i << " has x pos: " << physObjList[i]->GetPosition().x << std::endl;
	}
}
