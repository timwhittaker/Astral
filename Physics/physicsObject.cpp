#include <iostream>
#include "forces.h"
#include "physicsObject.h"
#include "../Math/Vector3D.h"
#include "../Math/integrators.h"

/* Assume Newton's EOM */
Vector3 dx(double t, Vector3 state)
{
        /* R.H.S. of the x component */
	double dv_x = state.z;
	double dx_x = state.y;
        Vector3 dX = Vector3(dx_x,dv_x,0);
        return dX;
}

Vector3 dy(double t, Vector3 state)
{
        /* R.H.S. of the y component */
	double dv_y = state.z;
	double dy_y = state.y;
        Vector3 dY = Vector3(dy_y,dv_y,0);
        return dY;
}

Vector3 dz(double t, Vector3 state)
{
        /* R.H.S. of the z component */
	double dv_z = state.z;
	double dz_z = state.y;
        Vector3 dZ = Vector3(dz_z,dv_z,0);
        return dZ;
}

void PhysicsObject::setPosition(Vector3 position)
{
	this->m_position = position;
}

void PhysicsObject::setVelocity(Vector3 velocity)
{
        this->m_velocity = velocity;
}

void PhysicsObject::setAcceleration(Vector3 acceleration)
{
        this->m_acceleration = acceleration;
}


void PhysicsObject::SimulateObject(double delta)
{
	/* TODO */
	/* Should change Vector3 to a 
	 * 6D vector... compute stuff
	 * in phase space. Current method
	 * is a bit wack.
	 */

	// Compute acceleration from masses
	Vector3 resultingAcc = m_acceleration;
	resultingAcc = resultingAcc+forceAccum/m_mass;
	/* Compute new positions and velocities */
	Vector3 x_state = Vector3(m_position.x, m_velocity.x, resultingAcc.x);
	Vector3 y_state = Vector3(m_position.y, m_velocity.y, resultingAcc.y);
	Vector3 z_state = Vector3(m_position.z, m_velocity.z, resultingAcc.z);
	Integrate(dx,x_state,0,delta,1,RK4);
	Integrate(dy,y_state,0,delta,1,RK4);
	Integrate(dz,z_state,0,delta,1,RK4);
	
	/* Update positions and velocities */
	setPosition(Vector3(x_state.x,y_state.x,z_state.x));
	setVelocity(Vector3(x_state.y,y_state.y,z_state.y));

	clearAccumulator();
}

void PhysicsObject::clearAccumulator()
{
	forceAccum.clear();
}

void PhysicsObject::addForce(const Vector3 &force)
{
	forceAccum += force;
}
