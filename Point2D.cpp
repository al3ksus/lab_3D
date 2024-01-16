#include "Point2D.h"

Point2D::Point2D()
{
	u1 = 0.0f;
	u2 = 0.0f;
	u3 = 1.0f;
	x = 0.0f;
	y = 0.0f;
}

Point2D::Point2D(float _x, float _y)
{
	u1 = _x;
	u2 = _y;
	u3 = 1.0f;
	x = _x;
	y = _y;
}
