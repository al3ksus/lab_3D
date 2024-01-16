#include "Model2D.h"

Model2D::Model2D()
{
	v_count = 0;
	vertices = nullptr;
	edges = nullptr;
}

Model2D::Model2D(Point2D _vertices[], int** _edges, int _v_count)
{
	v_count = _v_count;
	vertices = new Point2D[v_count];
	for (int i = 0; i < v_count; i++) {
		vertices[i] = _vertices[i];
	}

	edges = new int* [v_count];
	for (int i = 0; i < v_count; i++) {
		edges[i] = new int[v_count];
		for (int j = 0; j < v_count; j++) {
			edges[i][j] = _edges[i][j];
		}
	}
	
}
