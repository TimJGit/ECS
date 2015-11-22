#include "Vector3.h"

Vector3::Vector3() :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}

Vector3::Vector3(float x, float y, float z) :
	x(x),
	y(y),
	z(z)
{
}

float Vector3::Length()
{
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::Normalize()
{
	Vector3 normalizedVector;
	float vectorLength = Length();

	normalizedVector.x = x / vectorLength;
	normalizedVector.y = y / vectorLength;
	normalizedVector.z = z / vectorLength;

	return normalizedVector;
}

float Vector3::DotProduct(Vector3& vector)
{
	return (x * vector.x) + (y * vector.y) + (z * vector.z);
}

Vector3 Vector3::CrossProduct(Vector3& vector)
{
	Vector3 crossVector;

	crossVector.x = (y * vector.z) - (z * vector.y);
	crossVector.y = (z * vector.x) - (x * vector.z);
	crossVector.z = (x * vector.y) - (y * vector.x);

	return crossVector;
}

float Vector3::AngleBetween(Vector3& vector, bool inDegrees)
{
	Vector3 v1 = Normalize();
	Vector3 v2 = vector.Normalize();

	float angle = acos(v1.DotProduct(v2));

	if(inDegrees){
		angle *= static_cast<float>(180 / M_PI);
	}

	return angle;
}

Vector3 Vector3::operator+(const Vector3& vector)
{
	Vector3 newVector;

	newVector.x = x + vector.x;
	newVector.y = y + vector.y;
	newVector.z = z + vector.z;

	return newVector;
}

Vector3 Vector3::operator-(const Vector3& vector)
{
	Vector3 newVector;

	newVector.x = x - vector.x;
	newVector.y = y - vector.y;
	newVector.z = z - vector.z;

	return newVector;
}

Vector3 Vector3::operator*(float value)
{
	Vector3 newVector;

	newVector.x = x * value;
	newVector.y = y * value;
	newVector.z = z * value;

	return newVector;
}

Vector3 Vector3::operator/(float value)
{
	Vector3 newVector;

	newVector.x = x / value;
	newVector.y = y / value;
	newVector.z = z / value;

	return newVector;
}

void Vector3::operator+=(const Vector3& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
}

void Vector3::operator-=(const Vector3& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
}

void Vector3::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;
}

void Vector3::operator/=(float value)
{
	x /= value;
	y /= value;
	z /= value;
}
