#ifndef _MyMatrix
#define _MyMatrix

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Matrix
{
	int row;
	int col;
	float *data;
public:
	Matrix(int row, int col);
	Matrix(const Matrix &);
	Matrix& operator=(const Matrix &);
	~Matrix();

	float& operator()(int, int);
	const float& operator()(int, int)const;

	Matrix operator*(const Matrix &);
	Matrix operator+(const Matrix &);
	Matrix operator-(const Matrix &);

	static Matrix Unit(int dimension);
	static Matrix Zero(int row, int col);
	static Matrix Transform3D(float dx, float dy, float dz);
	static Matrix Rotation3DX(float);
	static Matrix Rotation3DY(float);
	static Matrix Rotation3DZ(float);
	static Matrix Rotation3DX(float, float);
	static Matrix Rotation3DY(float, float);
	static Matrix Rotation3DZ(float, float);
	static Matrix Zoom3D(float xScale, float yScale, float zScale);
	static Matrix HomogeneousCoordinate3D(float x, float y, float z);
	static Matrix ProjectionPointZ(float distance);
	static Matrix ProjectionPingXingZ(float, float, float);
	static Matrix Vector2Z(float, float, float);
	static Matrix Z2Vector(float, float, float);
	static Matrix Vector2X(float, float, float);
	static Matrix X2Vector(float, float, float);
	static Matrix Vector2Y(float, float, float);
	static Matrix Y2Vector(float, float, float);
};

#endif