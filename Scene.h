#pragma once
#include "Model3D.h"
#include "Camera.h"
#include "Vector3D.h"
#include "Model2D.h"
class Scene
{
public:
	Model3D model3D;
	Model2D model2D;
	Camera camera;
	Vector3D T;
	Vector3D N;
	Vector3D I;
	Vector3D J;
	Vector3D K;
	float F;

	Scene();
	Scene(const Point3D& _Oe, const Point3D& _Ov, const Vector3D& _T);

	Scene& operator=(const Scene& other);

	void set_LRBTWH(Point2D p[]);
};

