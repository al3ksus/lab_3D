#include "Camera.h"

Camera::Camera() {
	L = -10;
	R = 10;
	B = -10;
	T = 10;
	W = 800;
	H = 600;
}

Camera::Camera(const Point3D& _Oe, const Point3D& _Ov) : Camera() {
	Oe = _Oe;
	Ov = _Ov;
}

Camera& Camera::operator=(const Camera& other)
{
	if (this != &other) {
		Oe = other.Oe;
		Ov = other.Ov;
	}
	return *this;
}
