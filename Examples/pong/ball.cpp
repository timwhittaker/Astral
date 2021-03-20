#include <iostream>
#include <GL/glut.h>
#include "ball.h"

extern int windowL;
extern int windowH;

Ball::Ball(Player* playerOne, Player* playerTwo)
{
	this->playerOne = playerOne;
	this->playerTwo = playerTwo;

	// Initialize pos,vel,acc,mass
	// Saving the same info twice here, should fix this
	this->position = Vector3(0.0,0.0,0.0);
	this->velocity = Vector3(0.0,0.0,0.0);
	this->acceleration = Vector3(0.0,0.0,0.0);
	double mass = 0.0;

	this->ballPhys = PhysicsObject(position,velocity,acceleration,mass);
}

void Ball::setPosition(Vector3 pos)
{
	this->position = pos;
	ballPhys.setPosition(pos);
}

void Ball::setVelocity(Vector3 vel)
{
	this->velocity = vel;
	ballPhys.setVelocity(vel);
}

void Ball::setAcceleration(Vector3 acc)
{
	this->acceleration = acc;
}


// Need to add something to deal with corners

void Ball::checkWallHit()
{
	// Collide with left wall
	if(this->position.x < 0.0)
	{
	        // flip sign of x component
                this->setVelocity(Vector3(this->velocity.x*(-1),this->velocity.y,this->velocity.z));
	}
	// Collide with rightt wall
	if(this->position.x > (double)windowL)
	{
		// flip sign of x component
		this->setVelocity(Vector3(this->velocity.x*(-1),this->velocity.y,this->velocity.z));
	}
}

void Ball::checkPlayerOneHit()
{
	if(this->position.y < 0.0)
	{
		// Check if whithing bar of player
		if(this->position.x > playerOne->getCoord1() && this->position.x < playerOne->getCoord3())
		{
			// flip sign of y component
			this->setVelocity(Vector3(this->velocity.x,this->velocity.y*(-1),this->velocity.z));
		}
	}
}

void Ball::checkPlayerTwoHit()
{
	if(this->position.y > (double)windowH)
	{
                // Check if whithing bar of player
                if(this->position.x > playerTwo->getCoord1() && this->position.x < playerTwo->getCoord3())
                {
                        // flip sign of y component
                        this->setVelocity(Vector3(this->velocity.x,this->velocity.y*(-1),this->velocity.z));
                }
        }

}

void Ball::simBall(double delta)
{
	// Check for collisions
	checkWallHit();
	checkPlayerOneHit();
	checkPlayerTwoHit();
	// Update velocities as required
	// Perform time step
	ballPhys.SimulateObject(delta);
	// Update ball position
	this->position = ballPhys.GetPosition();
	this->velocity = ballPhys.GetVelocity();
}
