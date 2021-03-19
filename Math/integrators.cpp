#include <iostream>
#include <fstream>
#include <string>
#include "Vector3D.h"
#include "integrators.h"

void eulerMethod(Vector3& state, Vector3 dstate, double dt)
{
	state = state + dstate * dt;
}

void verletMethod(double dt)
{}

void rk4Method(Vector3 (*func)(double,Vector3), Vector3& state, double dt, int i)
{
	Vector3 k1 = (*func)(i*dt,state);
	Vector3 k2 = (*func)(i*dt+dt/2, state + k1*dt/(double)2.0);
	Vector3 k3 = (*func)(i*dt+dt/2, state + k2*dt/(double)2.0);
	Vector3 k4 = (*func)(i*dt+dt, state + k3*dt/(double)2.0);

	state = state+(k1+k2*2+k3*2+k4)*dt*1/(double)6;
}

void symplecticMethod(double dt)
{}


void Integrate(Vector3 (*func)(double,Vector3), Vector3& state, double t0, double t1, int steps, Method method)
{
	double dt = (t1-t0)/steps;
	// Compute dt


	for (int i = 0; i < steps; i++)
	{
		// Perform step with the right method
		Vector3 dstate = (*func)(dt*i,state); 
		switch(method){
			case Euler:
				// Compute dstate
				eulerMethod(state,dstate,dt);
				break;
			case Verlet:
				verletMethod(dt);
				break;
			case RK4:
				rk4Method((*func), state, dt, i);
				break;
			case Symplectic:
				symplecticMethod(dt);
				break;
		}

	}
}
