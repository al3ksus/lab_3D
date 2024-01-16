#pragma once
#include <string>
#include "Point3D.h"
#include "Point2D.h"
class Matrix
{
public:
	int str_count;
	int col_count;
	float** data;

	Matrix();
	Matrix(int n, int m);
	Matrix(float data[], int _str_count, int _col_count);
	
	static Matrix multiply(const Matrix& m1, const Matrix& m2);
	static Point3D* multiplyTo3D(const Matrix& m, Point3D p[], int v_count);
	static Point2D* multiplyTo2D(const Matrix& m, Point3D p[], int v_count);
};

 