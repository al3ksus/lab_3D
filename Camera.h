#pragma once
#include "Point3D.h"
class Camera
{ 
public:
	Point3D Oe;
	Point3D Ov;
	int L;
	int R;
	int B;
	int T;
	int W;
	int H;

	Camera();
	Camera(const Point3D& _Oe, const Point3D& _Ov);

	Camera& operator=(const Camera& other);
};

