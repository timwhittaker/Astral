#ifndef __INTEGRATOR_H__
#define __INTEGRATOR_H__

/*
* Integrator object
* Should make this more general than vector3f
*/
#include "Vector3D.h"

// Enumeration of methods to be implemented
enum Method {
	Euler,
	Verlet,
	RK4,
	Symplectic
};

void Integrate(Vector3 (*func)(double,Vector3), Vector3& state, double t0, double t1, int steps, Method method);

#endif
