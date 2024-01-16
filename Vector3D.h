#pragma once
#include <cmath>
class Vector3D
{
public:
	float x, y, z, length;
	Vector3D();
	Vector3D(const Vector3D& v);
	Vector3D(float _x, float _y, float _z);

	static Vector3D multiply(const Vector3D& v1, const Vector3D& v2);
	void norm();

	Vector3D& operator=(const Vector3D& other);
};

