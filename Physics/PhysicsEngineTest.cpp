#include <iostream>
#include "PhysicsEngine.h"
#include "physicsObject.h"
#include "entityTest.h"
#include "../Math/Vector3D.h"

/*
 * Simple test of the PhysicsEngine.
 * Here we create two balls, evolve
 * them, test for collisions.
 */

int main()
{
	// Initialize entities and physics engine
        PhysicsEngine mainEngine = PhysicsEngine();
	Entity ball1 = Entity(Vector3(1.5,0.0,0.0),Vector3(0.0,0.0,0.0),Vector3(0.0,0.0,0.0),1.0,Vector3(0.5,0.5,0.0));
	Entity ball2 = Entity(Vector3(0.0,0.0,0.0),Vector3(1.0,0.0,0.0),Vector3(0.0,0.0,0.0),1.0,Vector3(0.5,0.5,0.0));


	// Add entities physics and collisions to physics engine
	mainEngine.addEntityPhysics(&(ball1.entityPhys));
	mainEngine.addEntityCollision(&(ball1.entityObj));
	mainEngine.addEntityPhysics(&(ball2.entityPhys));
	mainEngine.addEntityCollision(&(ball2.entityObj));
	mainEngine.displayObjects();
	mainEngine.updateKinematics(1.0);
	mainEngine.resolveCollision();
	mainEngine.displayObjects();
	mainEngine.updateKinematics(1.0);
	mainEngine.resolveCollision();
	mainEngine.displayObjects();
	return 1;
}
