#include "AffineTransform.h"

AffineTransform::AffineTransform() 
{
	float mas[16]{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
	affineTransfromMatrix = Matrix(mas, 4, 4);
}

AffineTransform::AffineTransform(Vector3D I, Vector3D J, Vector3D K, Point3D Ov, float F)
{
	float mas1[16]{ 
		I.x, I.y, I.z, -1.0f * (I.x * Ov.x + I.y * Ov.y + I.z * Ov.z),
		J.x, J.y, J.z, -1.0f * (J.x * Ov.x + J.y * Ov.y + J.z * Ov.z),
		K.x, K.y, K.z, -1.0f * (K.x * Ov.x + K.y * Ov.y + K.z * Ov.z),
		0.0f, 0.0f, 0.0f, 1.0f
	};
	worldToViewMatrix = Matrix(mas1, 4, 4);

	float mas2[12]{ 
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, -1.0f / F, 1.0f
	};
	viewToProjectMatrix = Matrix(mas2, 3, 4);
	
	float mas3[16]{ 
		1.0f, 0.0f, 0.0f, 0.0f, 
		0.0f, 1.0f, 0.0f, 0.0f, 
		0.0f, 0.0f, 1.0f, 0.0f, 
		0.0f, 0.0f, 0.0f, 1.0f 
	};
	affineTransfromMatrix = Matrix(mas3, 4, 4);
}

void AffineTransform::set_worldToViewMatrix(const Vector3D& I, const Vector3D& J, const Vector3D& K, const Point3D& Ov)
{
	float mas[16]{
		I.x, I.y, I.z, -1.0f * (I.x * Ov.x + I.y * Ov.y + I.z * Ov.z),
		J.x, J.y, J.z, -1.0f * (J.x * Ov.x + J.y * Ov.y + J.z * Ov.z),
		K.x, K.y, K.z, -1.0f * (K.x * Ov.x + K.y * Ov.y + K.z * Ov.z),
		0.0f, 0.0f, 0.0f, 1.0f
	};
	worldToViewMatrix = Matrix(mas, 4, 4);
}

void AffineTransform::set_viewToProjectMatrix(float F)
{
	float mas[12]{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
	viewToProjectMatrix = Matrix(mas, 3, 4);
}

void AffineTransform::worldToViewMatrixApply()
{
	affineTransfromMatrix = Matrix::multiply(worldToViewMatrix, affineTransfromMatrix);
}

void AffineTransform::rotateX(float deg)
{
	float mas[16]{
		1, 0, 0, 0,
		0, cos(deg), -1 * sin(deg), 0,
		0, sin(deg), cos(deg), 0,
		0, 0, 0, 1
	};

	affineTransfromMatrix = Matrix::multiply(Matrix(mas, 4, 4), affineTransfromMatrix);
}

void AffineTransform::rotateY(float deg)
{
	float mas[16]{
		cos(deg), 0, sin(deg), 0,
		0, 1, 0, 0,
		-1 * sin(deg), 0, cos(deg), 0,
		0, 0, 0, 1
	};

	affineTransfromMatrix = Matrix::multiply(Matrix(mas, 4, 4), affineTransfromMatrix);
}

void AffineTransform::rotateZ(float deg)
{
	float mas[16]{
		cos(deg), -1 * sin(deg), 0, 0,
		sin(deg), cos(deg), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	affineTransfromMatrix = Matrix::multiply(Matrix(mas, 4, 4), affineTransfromMatrix);
}

void AffineTransform::transform(float k)
{
	float mas[16]{
		k, 0, 0, 0,
		0, k, 0, 0,
		0, 0, k, 0,
		0, 0, 0, 1
	};

	affineTransfromMatrix = Matrix::multiply(Matrix(mas, 4, 4), affineTransfromMatrix);
}
