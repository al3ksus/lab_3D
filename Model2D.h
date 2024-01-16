#pragma once
#include "Point2D.h"
class Model2D
{
public:
	int v_count;
	Point2D* vertices;
	int** edges;

	Model2D();
	Model2D(Point2D _vertices[], int** _edges, int _v_count);
};

