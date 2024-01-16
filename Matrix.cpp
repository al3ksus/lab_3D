#include "Matrix.h"

Matrix::Matrix() {
	data = nullptr;
	str_count = 0;
	col_count = 0;
}

Matrix::Matrix(int n, int m) {
	str_count = n;
	col_count = m;

	data = new float* [str_count];
	
	for (int i = 0; i < str_count; i++) {
		data[i] = new float[col_count];
		for (int j = 0; j < col_count; j++) {
			data[i][j] = 0;
		}
	}
}

Matrix::Matrix(float _data[], int _str_count, int _col_count) {
	str_count = _str_count;
	col_count = _col_count;
	data = new float*[str_count];

	for (int i = 0; i < str_count; i++) {
		data[i] = new float[col_count];
		for (int j = 0; j < col_count; j++) {
			data[i][j] = _data[i * _col_count + j];
		}
	}
}

Matrix Matrix::multiply(const Matrix& m1, const Matrix& m2)
{
	Matrix m3(m1.str_count, m2.col_count);

	if (m1.col_count == m2.str_count) {
		for (int i = 0; i < m3.str_count; i++) {
			for (int j = 0; j < m3.col_count; j++) {
				for (int k = 0; k < m1.col_count; k++) {
					m3.data[i][j] += m1.data[i][k] * m2.data[k][j];
				}
			}
		}
	}
	
	return m3;
}

Point3D* Matrix::multiplyTo3D(const Matrix& m, Point3D p[], int v_count)
{
	Point3D* temp = new Point3D[v_count];

	for (int i = 0; i < v_count; i++) {
		temp[i].u1 = m.data[0][0] * p[i].u1 + m.data[0][1] * p[i].u2 + m.data[0][2] * p[i].u3 + m.data[0][3] * p[i].u4;
		temp[i].u2 = m.data[1][0] * p[i].u1 + m.data[1][1] * p[i].u2 + m.data[1][2] * p[i].u3 + m.data[1][3] * p[i].u4;
		temp[i].u3 = m.data[2][0] * p[i].u1 + m.data[2][1] * p[i].u2 + m.data[2][2] * p[i].u3 + m.data[2][3] * p[i].u4;
		temp[i].u4 = m.data[3][0] * p[i].u1 + m.data[3][1] * p[i].u2 + m.data[3][2] * p[i].u3 + m.data[3][3] * p[i].u4;
		temp[i].x = temp[i].u1 / temp[i].u4;
		temp[i].y = temp[i].u2 / temp[i].u4;
		temp[i].z = temp[i].u3 / temp[i].u4;
	}

	return temp;
}

Point2D* Matrix::multiplyTo2D(const Matrix& m, Point3D p[], int v_count)
{
	Point2D* temp = new Point2D[v_count];

	for (int i = 0; i < v_count; i++) {
		temp[i].u1 = m.data[0][0] * p[i].u1 + m.data[0][1] * p[i].u2 + m.data[0][2] * p[i].u3 + m.data[0][3] * p[i].u4;
		temp[i].u2 = m.data[1][0] * p[i].u1 + m.data[1][1] * p[i].u2 + m.data[1][2] * p[i].u3 + m.data[1][3] * p[i].u4;
		temp[i].u3 = m.data[2][0] * p[i].u1 + m.data[2][1] * p[i].u2 + m.data[2][2] * p[i].u3 + m.data[2][3] * p[i].u4;
		temp[i].x = temp[i].u1 / temp[i].u3;
		temp[i].y = temp[i].u2 / temp[i].u3;
	}

	return temp;
}
