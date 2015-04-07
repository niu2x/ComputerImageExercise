

#include "stdafx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Matrix.h"
#include <assert.h>
#include <string.h>
#include <math.h>


Matrix::Matrix(int __row, int __col):row(__row), col(__col)
{
	assert(row > 0 && col > 0);
	data = new float[row * col];
	assert(data != 0 && "operator new failed, data == 0.");
}

Matrix::Matrix(const Matrix &it):row(it.row), col(it.col)
{
	data = new float[row * col];
	assert(data != 0 && "operator new failed, data == 0.");
	memcpy(data, it.data, sizeof(float) * row * col);
}

Matrix& Matrix::operator = (const Matrix &it)
{
	if(this != &it)
	{
		assert(row == it.row && col == it.col && "Matrix dimension don't match.");
		memcpy(data, it.data, sizeof(float) * row * col);
	}
	return *this;
}

Matrix::~Matrix ()
{
	delete []data;
}

float& Matrix::operator () (int i, int j)
{
	assert(i >= 1 && i <= row && j >= 1 && j <= col);
	return data[ (i - 1) * col + j - 1];
}

const float& Matrix::operator () (int i, int j)const
{
	assert(i >= 1 && i <= row && j >= 1 && j <= col);
	return data[ (i - 1) * col + j - 1];
}

Matrix Matrix::operator + (const Matrix &it)
{
	assert(row == it.row && col == it.col && "Matrix dimension don't match.");
	Matrix sum(row, col);
	for(int i = 1; i <= row; i ++)
	{
		for(int j = 1; j <= col; j ++)
		{
			sum(i, j) = (*this)(i, j) + it(i, j);
		}
	}
	return sum;
}

Matrix Matrix::operator - (const Matrix &it)
{
	assert(row == it.row && col == it.col && "Matrix dimension don't match.");
	Matrix diff(row, col);
	for(int i = 1; i <= row; i ++)
	{
		for(int j = 1; j <= col; j ++)
		{
			diff(i, j) = (*this)(i, j) - it(i, j);
		}
	}
	return diff;
}

Matrix Matrix::operator * (const Matrix &it)
{
	assert(col == it.row && "Matrix dimension don't match.");
	Matrix product(row, it.col);
	for(int i = 1; i <= row; i ++)
	{
		for(int j = 1; j <= it.col; j ++)
		{
			product(i, j) = 0;
			for(int k = 1; k <= col; k ++)
			{
				product(i, j) += (*this)(i, k) * it(k, j);
			}
		}
	}
	return product;
}

Matrix Matrix::Unit(int dimension)
{
	Matrix unit = Zero(dimension, dimension);
	for(int i = 1; i <= dimension; i++)
	{
		unit(i, i) = 1;
	}
	return unit;
}
Matrix Matrix::Zero(int row, int col)
{
	Matrix zero(row, col);
	memset(zero.data , 0, sizeof(float) * row * col);
	return zero;
}
Matrix Matrix::Transform3D(float dx, float dy, float dz)
{
	Matrix transform(4, 4);
	transform(1, 1) = 1;	transform(1, 2) = 0;	transform(1, 3) = 0;	transform(1, 4) = 0;
	transform(2, 1) = 0;	transform(2, 2) = 1;	transform(2, 3) = 0;	transform(2, 4) = 0;
	transform(3, 1) = 0;	transform(3, 2) = 0;	transform(3, 3) = 1;	transform(3, 4) = 0;
	transform(4, 1) = dx;	transform(4, 2) = dy;	transform(4, 3) = dz;	transform(4, 4) = 1;
	return transform;
}

Matrix Matrix::Rotation3DX(float s, float c)
{
	Matrix rotation(4, 4);
	rotation(1, 1) = 1;		rotation(1, 2) = 0;		rotation(1, 3) = 0;		rotation(1, 4) = 0;
	rotation(2, 1) = 0;		rotation(2, 2) = c;		rotation(2, 3) = s;		rotation(2, 4) = 0;
	rotation(3, 1) = 0;		rotation(3, 2) = -s;	rotation(3, 3) = c;		rotation(3, 4) = 0;
	rotation(4, 1) = 0;		rotation(4, 2) = 0;		rotation(4, 3) = 0;		rotation(4, 4) = 1;
	return rotation;
}
Matrix Matrix::Rotation3DY(float s, float c)
{
	Matrix rotation(4, 4);
	rotation(1, 1) = c;		rotation(1, 2) = 0;		rotation(1, 3) = -s;	rotation(1, 4) = 0;
	rotation(2, 1) = 0;		rotation(2, 2) = 1;		rotation(2, 3) = 0;		rotation(2, 4) = 0;
	rotation(3, 1) = s;		rotation(3, 2) = 0;		rotation(3, 3) = c;		rotation(3, 4) = 0;
	rotation(4, 1) = 0;		rotation(4, 2) = 0;		rotation(4, 3) = 0;		rotation(4, 4) = 1;
	return rotation;
}
Matrix Matrix::Rotation3DZ(float s, float c)
{
	Matrix rotation(4, 4);
	rotation(1, 1) = c;		rotation(1, 2) = s;		rotation(1, 3) = 0;		rotation(1, 4) = 0;
	rotation(2, 1) = -s;	rotation(2, 2) = c;		rotation(2, 3) = 0;		rotation(2, 4) = 0;
	rotation(3, 1) = 0;		rotation(3, 2) = 0;		rotation(3, 3) = 1;		rotation(3, 4) = 0;
	rotation(4, 1) = 0;		rotation(4, 2) = 0;		rotation(4, 3) = 0;		rotation(4, 4) = 1;
	return rotation;
}
Matrix Matrix::Rotation3DX(float angle)
{
	return Rotation3DX(sin(angle), cos(angle));
}
Matrix Matrix::Rotation3DY(float angle)
{
	return Rotation3DY(sin(angle), cos(angle));
}
Matrix Matrix::Rotation3DZ(float angle)
{
	return 	Rotation3DZ(sin(angle), cos(angle));
}
Matrix Matrix::Vector2Z(float x, float y, float z)
{
	Matrix mat = Matrix::Unit (4);
	if(z*z + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DX (y/sqrt(y*y+z*z),z/sqrt(y*y+z*z));
	}
	if(x*x + z*z + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DY (-x/sqrt(y*y+z*z+x*x), sqrt(y*y+z*z)/sqrt(y*y+z*z+x*x));
	}
	return mat;
}
Matrix Matrix::Z2Vector(float x, float y, float z)
{
	Matrix mat = Matrix::Unit (4);
	if(x*x + z*z + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DY (x/sqrt(y*y+z*z+x*x), sqrt(y*y+z*z)/sqrt(y*y+z*z+x*x));
	}
	if(z*z + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DX (-y/sqrt(y*y+z*z),z/sqrt(y*y+z*z));
	}
	return mat;
}
Matrix Matrix::Zoom3D(float xScale, float yScale, float zScale)
{
	Matrix zoom(4, 4);
	zoom(1, 1) = xScale;zoom(1, 2) = 0;		zoom(1, 3) = 0;		zoom(1, 4) = 0;
	zoom(2, 1) = 0;		zoom(2, 2) = yScale;zoom(2, 3) = 0;		zoom(2, 4) = 0;
	zoom(3, 1) = 0;		zoom(3, 2) = 0;		zoom(3, 3) = zScale;zoom(3, 4) = 0;
	zoom(4, 1) = 0;		zoom(4, 2) = 0;		zoom(4, 3) = 0;		zoom(4, 4) = 1;
	return zoom;
}
Matrix Matrix::HomogeneousCoordinate3D(float x, float y, float z)
{
	Matrix homogeneousCoordinate3D(1, 4);
	homogeneousCoordinate3D(1, 1) = x;
	homogeneousCoordinate3D(1, 2) = y;
	homogeneousCoordinate3D(1, 3) = z;
	homogeneousCoordinate3D(1, 4) = 1;
	return homogeneousCoordinate3D;
}
Matrix Matrix::ProjectionPointZ(float distance)
{
	Matrix projection(4, 4);
	projection(1, 1) = 1;	projection(1, 2) = 0;	projection(1, 3) = 0;	projection(1, 4) = 0;
	projection(2, 1) = 0;	projection(2, 2) = 1;	projection(2, 3) = 0;	projection(2, 4) = 0;
	projection(3, 1) = 0;	projection(3, 2) = 0;	projection(3, 3) = 1;	projection(3, 4) = 1/distance;
	projection(4, 1) = 0;	projection(4, 2) = 0;	projection(4, 3) = 0;	projection(4, 4) = 0;
	return projection;
}
Matrix Matrix::ProjectionPingXingZ(float x, float y, float z)
{
	Matrix projection(4, 4);
	projection(1, 1) = 1;	projection(1, 2) = 0;	projection(1, 3) = 0;	projection(1, 4) = 0;
	projection(2, 1) = 0;	projection(2, 2) = 1;	projection(2, 3) = 0;	projection(2, 4) = 0;
	projection(3, 1) = -x/z;projection(3, 2) = -y/z;projection(3, 3) = 0;	projection(3, 4) = 0;
	projection(4, 1) = 0;	projection(4, 2) = 0;	projection(4, 3) = 0;	projection(4, 4) = 1;
	return projection;
}
Matrix Matrix::Vector2Y(float x, float y, float z)
{
	Matrix mat = Matrix::Unit (4);
	if(x*x + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DZ (x/sqrt(y*y+x*x),y/sqrt(y*y+x*x));
	}
	if(x*x + z*z + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DX (-z/sqrt(y*y+z*z+x*x), sqrt(y*y+x*x)/sqrt(y*y+z*z+x*x));
	}
	return mat;
}

Matrix Matrix::Vector2X(float x, float y, float z)
{
	Matrix mat = Matrix::Unit (4);
	if(x*x + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DZ (y/sqrt(y*y+x*x),x/sqrt(y*y+x*x));
	}
	if(x*x + z*z + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DY (z/sqrt(y*y+z*z+x*x), sqrt(y*y+x*x)/sqrt(y*y+z*z+x*x));
	}
	return mat;
}

Matrix Matrix::X2Vector(float x, float y, float z)
{
	Matrix mat = Matrix::Unit (4);
	if(x*x + z*z + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DY (-z/sqrt(y*y+z*z+x*x), sqrt(y*y+x*x)/sqrt(y*y+z*z+x*x));
	}
	if(x*x + y*y != 0)
	{
		mat = mat * Matrix::Rotation3DZ (y/sqrt(y*y+x*x),x/sqrt(y*y+x*x));
	}
	return mat;
}