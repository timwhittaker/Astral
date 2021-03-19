#ifndef PHYSICS_OBJECT_INCLUDED_H
#define PHYSICS_OBJECT_INCLUDED_H

#include "../Math/Vector3D.h"
#include "../Math/integrators.h"

/* A class to represent a point particle */

class PhysicsObject
{
public:
	PhysicsObject(const Vector3& position, const Vector3& velocity, const Vector3& acceleration, const double& mass):
		m_position(position),
		m_velocity(velocity),
       		m_acceleration(acceleration),
       		m_mass(mass)	{}

	void SimulateObject(double delta);
	
	inline const Vector3 GetPosition() const { return m_position; };
	inline const Vector3 GetVelocity() const { return m_velocity; };
	inline const Vector3 GetAcceleration() const { return m_acceleration; };
	inline const double  GetMass() const { return m_mass; };


	void setPosition(Vector3 position);
	void setVelocity(Vector3 velocity);
	void setAcceleration(Vector3 acceleration);
	
	void addForce(const Vector3 &force);	
	void clearAccumulator();
	Vector3 forceAccum;

private:
	Vector3 m_position;
	Vector3 m_velocity;
	Vector3 m_acceleration;
	double m_mass;
};

#endif
