#pragma once
#include "stdafx.h"

struct Vector3
{
public:
	float x, y, z;

	//Constructors
	Vector3();
	Vector3(float x, float y, float z);

	//Methods
	float Length();
	Vector3 Normalize();
	float DotProduct(Vector3& vector);
	Vector3 CrossProduct(Vector3& vector);
	float AngleBetween(Vector3& vector, bool inDegrees = false);

	//Operator Overloading
	Vector3 operator+(const Vector3& vector);
	Vector3 operator-(const Vector3& vector);
	Vector3 operator*(float value);
	Vector3 operator/(float value);

	void operator+=(const Vector3& vector);
	void operator-=(const Vector3& vector);
	void operator*=(float value);
	void operator/=(float value);
};
