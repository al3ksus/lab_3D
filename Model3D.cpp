#include "Model3D.h"

Model3D::Model3D()
{
	v_count = 8;
	vertices = new Point3D[8]{
		Point3D(1, 1, 1),
		Point3D(-1, 1, 1),
		Point3D(1, -1, 1),
		Point3D(-1, -1, 1),
		Point3D(1, 1, -1),
		Point3D(-1, 1, -1),
		Point3D(1, -1, -1),
		Point3D(-1, -1, -1),
	};

	edges = new int* [8];
	edges[0] = new int[8] { 0, 1, 1, 1, 1, 0, 0, 0};
	edges[1] = new int[8] { 1, 0, 1, 1, 0, 1, 0, 0};
	edges[2] = new int[8] { 1, 1, 0, 1, 0, 0, 1, 0};
	edges[3] = new int[8] { 1, 1, 1, 0, 0, 0, 0, 1};
	edges[4] = new int[8] { 1, 0, 0, 0, 0, 1, 1, 1};
	edges[5] = new int[8] { 0, 1, 0, 0, 1, 0, 1, 1};
	edges[6] = new int[8] { 0, 0, 1, 0, 1, 1, 0, 1};
	edges[7] = new int[8] { 0, 0, 0, 1, 1, 1, 1, 0};
	
	/*v_count = 5;
	vertices = new Point3D[5]{
		Point3D(0, 0, 1),
		Point3D(1, 1, -1),
		Point3D(-1, 1, -1),
		Point3D(1, -1, -1),
		Point3D(-1, -1, -1),
	};

	edges = new int* [5];
	edges[0] = new int[5] { 0, 1, 1, 1, 1};
	edges[1] = new int[5] { 1, 0, 1, 1, 1};
	edges[2] = new int[5] { 1, 1, 0, 1, 1};
	edges[3] = new int[5] { 1, 1, 1, 0, 1};
	edges[4] = new int[5] { 1, 1, 1, 1, 0};*/
}

