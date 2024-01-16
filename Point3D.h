#pragma once

class Point3D {
public:
	float u1, u2, u3, u4, x, y, z;

	Point3D();
	Point3D(float _x, float _y, float _z);

	Point3D& operator=(const Point3D& other);
};


