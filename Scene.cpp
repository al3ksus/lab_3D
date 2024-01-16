#include "Scene.h"
Scene::Scene() {}

Scene& Scene::operator=(const Scene& other)
{
	if (this != &other) {
		model3D = other.model3D;
		model2D = other.model2D;
		camera = other.camera;
		T = other.T;
		N = other.N;
		I = other.I;
		J = other.J;
		K = other.K;
		F = other.F;
	}
	return *this;
}

void Scene::set_LRBTWH(Point2D p[])
{
	int max_x = p[0].x;
	int min_x = p[0].x;
	int max_y = p[0].y;
	int min_y = p[0].y;

	for (int i = 0; i < model3D.v_count; i++) {
		if (p[i].x > max_x) {
			max_x = p[i].x;
		}
		if (p[i].x < min_x) {
			min_x = p[i].x;
		}
		if (p[i].y > max_y) {
			max_y = p[i].y;
		}
		if (p[i].y < min_y) {
			min_y = p[i].y;
		}
	}

	camera.L = min_x * 2;
	camera.R = max_x * 2;
	camera.B = min_y * 2;
	camera.T = max_y * 2;
	camera.W = 800;
	camera.H = 600;
}

Scene::Scene(const Point3D& _Oe, const Point3D& _Ov, const Vector3D& _T) {
	camera = Camera(_Oe, _Ov);
	T = _T;
	N = Vector3D(_Oe.x - _Ov.x, _Oe.y - _Ov.y, _Oe.z - _Ov.z);
	K = N;
	K.norm();
	I = Vector3D::multiply(T, N);
	I.norm();
	J = Vector3D::multiply(K, I);
	F = N.length;
}
