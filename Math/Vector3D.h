#ifndef Vector3D_H_INCLUDED
#define Vector3D_H_INCLUDED

#include <math.h>

// 3D vector class
class Vector3
{
public:
	/* init */
	Vector3(): x(0), y(0), z(0) {}
	Vector3(const double x, const double y, const double z): 
		x(x), y(y), z(z) {}
	/* values of vetor entries */
	double x,y,z;
	/* Useful functions */
	double norm() const
	{return sqrt(x*x+y*y+z*z);}

	void normalize()
	{
		// Check norm > 0
		double n = norm();
		if (n>0)
		{
			(*this)*=((double)1)/n;
		}
	}

	/* Overload multiplication with scalar multiplication */
	Vector3 operator*(const double value) const
	{
		return Vector3(x*value, y*value, z*value);
	}
	void operator*=(const double value)
	{
		x *= value;
		y *= value;
		z *= value;
	}
	/* Overload division with scalar */
        Vector3 operator/(const double value) const
        {
                return Vector3(x/value, y/value, z/value);
        }
        void operator/=(const double value)
        {
                x /= value;
                y /= value;
                z /= value;
        }

        /* Overload addition with vector addition */
	Vector3 operator+(const Vector3& v) const
	{
		return Vector3(x+v.x,y+v.y,z+v.z);
	}
	void operator+=(const Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}
        /* Overload subtraction with vector subtraction */
	Vector3 operator-(const Vector3& v) const
	{
		return Vector3(x-v.x,y-v.y,z-v.z);
	}
	void operator-=(const Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	/* Vector products */

	/* Dot Product */
	double dot(const Vector3 &v) const
	{
		return x*v.x+y*v.y+z*v.z;
	}
	/* Element wise product */
	Vector3 elementProduct(const Vector3 &v) const
	{
		return Vector3(x*v.x, y*v.y, z*v.z);
	}
	/* Cross product */
	Vector3 crossProduct(const Vector3 &v) const
	{
		return Vector3(y*v.z-z*v.y,
			       z*v.x-x*v.z,
			       x*v.y-y*v.y);
	}

	void clear()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
};

#endif
