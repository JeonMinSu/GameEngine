#pragma once

#include "Vector2.h"

struct Vector3
{
public:
	Vector3() = default;
	FORCEINLINE Vector3(const Vector2& InV, bool IsPoint = true) : X(InV.X), Y(InV.Y) { Z = IsPoint ? 1.0f : 0.0f; }
	FORCEINLINE Vector3(float InX, float InY, float InZ) : X(InX), Y(InY), Z(InZ) { }

	FORCEINLINE Vector3 Cross(const Vector3& InV) const;
	FORCEINLINE Vector3 Normalize()const;

	FORCEINLINE float SizeSquared() const;
	FORCEINLINE bool IsZero() const
	{
		return X == 0.0f && Y == 0.0f && Z == 0.0f;
	}

	FORCEINLINE float Dot(const Vector3 &InV) const;

	FORCEINLINE static float Dot(const Vector3 &InV1, const Vector3 &InV2);
	FORCEINLINE static float Angle(const Vector3 from, const Vector3 to);

	FORCEINLINE Vector2 ToVector2() const;

	FORCEINLINE float operator[](int InIndex) const;
	FORCEINLINE float &operator[](int InIndex);

	FORCEINLINE Vector3 operator-() const { return Vector3(-X, -Y, -Z); }
	FORCEINLINE Vector3 operator*(float InScale) const;
	FORCEINLINE Vector3 operator*(const Vector3& InV) const;
	FORCEINLINE Vector3 operator+(const Vector3& InV) const;
	FORCEINLINE Vector3 operator-(const Vector3& InV) const;
	FORCEINLINE Vector3 operator+=(const Vector3& InV);
	FORCEINLINE Vector3 operator/=(float InScale);


	static const Vector3 UnitX;
	static const Vector3 UnitY;
	static const Vector3 UnitZ;
	static const Vector3 One;
	static const Vector3 Zero;
	static const Vector3 Infinity;
	static const Vector3 InfinityNeg;


public:
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;
};

FORCEINLINE Vector3 Vector3::Cross(const Vector3 & InV) const
{
	//23 31 12
	return Vector3(
		Y * InV.Z - Z * InV.Y,
		Z * InV.X - X * InV.Z,
		X * InV.Y - Y * InV.X);
}

FORCEINLINE Vector3 Vector3::Normalize() const
{
	float squareSum = SizeSquared();
	if (squareSum == 1.0f)
	{
		return *this;
	}
	else if (squareSum == 0.0f)
	{
		return Vector3::Zero;
	}

	float invLength = 1 / sqrtf(squareSum);
	return Vector3(X * invLength, Y * invLength, Z * invLength);
}

FORCEINLINE float Vector3::SizeSquared() const
{
	return X * X + Y * Y + Z * Z;
}

FORCEINLINE float Vector3::Dot(const Vector3 & InV) const
{
	return X * InV.X + Y * InV.Y + Z * InV.Z;
}

FORCEINLINE float Vector3::Dot(const Vector3 & InV1, const Vector3 & InV2)
{
	return InV1.X * InV2.X + InV1.Y * InV2.Y + InV1.Z * InV2.Z;
}

FORCEINLINE Vector2 Vector3::ToVector2() const
{
	return Vector2(X, Y);
}

FORCEINLINE float Vector3::operator[](int InIndex) const
{
	return ((float *)this)[InIndex];
}

FORCEINLINE float & Vector3::operator[](int InIndex)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return ((float *)this)[InIndex];
}

FORCEINLINE Vector3 Vector3::operator*(float InScale) const
{
	return Vector3(X * InScale, Y * InScale, Z * InScale);
}

FORCEINLINE Vector3 Vector3::operator*(const Vector3 & InV) const
{
	return Vector3(X * InV.X, Y * InV.Y, Z * InV.Z);
}

FORCEINLINE Vector3 Vector3::operator+(const Vector3 & InV) const
{
	return Vector3(X + InV.X , Y + InV.Y, Z + InV.Z);
}

FORCEINLINE Vector3 Vector3::operator-(const Vector3 & InV) const
{
	return Vector3(X - InV.X, Y - InV.Y, Z - InV.Z);
}

FORCEINLINE Vector3 Vector3::operator+=(const Vector3 & InV)
{
	X += InV.X;
	Y += InV.Y;
	Z += InV.Z;

	return *this;
}

FORCEINLINE Vector3 Vector3::operator/=(float InScale)
{
	X /= InScale;
	Y /= InScale;
	Z /= InScale;

	return *this;
}

FORCEINLINE float Vector3::Angle(const Vector3 from, const Vector3 to)
{

	float theta = Vector3::Dot(from, to) / (from.SizeSquared() * to.SizeSquared());
	Vector3 dirAngle = to.Cross(from);
	//float Sin;
	//float Cos;
	//Math::GetSinCos(Sin, Cos, theta);

	
	
/*	float theta = Vector3.Dot(Vector3.up, Vector3.forward) / (Vector3.up.magnitude * Vector3.up.magnitude);
	Vector3 dirAngle = Vector3.Cross(Vector3.up, Vector3.forward);
	float angle = Mathf.Acos(theta) * Mathf.Rad2Deg;

	if (dirAngle.z < 0.0f) angle = 360.0f - angle;

	Debug.Log(angle)*/

	return 0.0f;
}
