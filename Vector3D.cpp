#include "Vector3D.h"

Vector3D::Vector3D() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	length = 0.0f;
}

Vector3D::Vector3D(const Vector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	length = v.length;
}

Vector3D::Vector3D(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
	length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3D Vector3D::multiply(const Vector3D& v1, const Vector3D& v2)
{
	Vector3D v3;

	v3.x = (v1.y * v2.z - v1.z * v2.y);
	v3.y = (v1.z * v2.x - v1.x * v2.z);
	v3.z = (v1.x * v2.y - v1.y * v2.x);
	v3.length = sqrt(pow(v3.x, 2) + pow(v3.y, 2) + pow(v3.z, 2));

	return v3;
}

void Vector3D::norm()
{
	x = x / length;
	y = y / length;
	z = z / length;
	length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3D& Vector3D::operator=(const Vector3D& other)
{
	if (this != &other) {
		x = other.x;
		y = other.y;
		z = other.z;
		length = other.length;
	}
	return *this;
}
