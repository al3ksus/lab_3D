#pragma once
#include "Point3D.h"
#include "Matrix.h"
class Model3D
{
public:
	int v_count;
	Point3D* vertices;
	int** edges;

	Model3D();
};

