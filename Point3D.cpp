#include "Point3D.h"

Point3D::Point3D() {
	u1 = 0.0f;
	u2 = 0.0f;
	u3 = 0.0f;
	u4 = 1.0f;
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Point3D::Point3D(float _x, float _y, float _z)
{
	u1 = _x;
	u2 = _y;
	u3 = _z;
	u4 = 1.0f;
	x = _x;
	y = _y;
	z = _z;
}

Point3D& Point3D::operator=(const Point3D& other)
{
	if (this != &other) {
		u1 = other.u1;
		u2 = other.u2;
		u3 = other.u3;
		u4 = other.u4;
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}
