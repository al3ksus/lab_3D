#pragma once
#include "Point3D.h"
#include <cmath>
#include "Vector3D.h"
#include "Matrix.h"

class AffineTransform
{
public:
	Matrix worldToViewMatrix;
	Matrix viewToProjectMatrix;
	Matrix affineTransfromMatrix;

	AffineTransform();
	AffineTransform(Vector3D I, Vector3D J, Vector3D K, Point3D Ov, float F);

	void set_worldToViewMatrix(const Vector3D& I, const Vector3D& J, const Vector3D& K, const Point3D& Ov);
	void set_viewToProjectMatrix(float F);

	void worldToViewMatrixApply();

	void rotateX(float deg);
	void rotateY(float deg);
	void rotateZ(float deg);
	void transform(float k);
};

