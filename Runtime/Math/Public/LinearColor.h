#pragma once

#include "CoreDefinition.h"
#include "Color32.h"
#include "Math.h"

struct LinearColor
{
public:
	FORCEINLINE LinearColor() {}

	constexpr FORCEINLINE LinearColor(float InR, float InG, float InB, float InA = 1.0f) : R(InR), G(InG), B(InB), A(InA) { }
	LinearColor(const Color32 &InColor32, const bool bSRGB = false);

	FORCEINLINE bool EqualseInRnage(const LinearColor &InColor, float InRange) const;
	Color32 ToColor32(const bool bSRGB = false) const;
	 
	FORCEINLINE LinearColor operator+(const LinearColor &InColor) const;
	FORCEINLINE LinearColor operator-(const LinearColor &InColor) const;
	FORCEINLINE LinearColor operator*(const LinearColor &InColor) const;
	FORCEINLINE LinearColor operator*(float InScalaar) const;
	FORCEINLINE bool operator==(const LinearColor InColor) const;
	FORCEINLINE bool operator!=(const LinearColor InColor) const;

	static const float OneOver255;
	static const LinearColor Error;
	static const LinearColor White;
	static const LinearColor Black;
	static const LinearColor Red;
	static const LinearColor Green;
	static const LinearColor Blue;
	static const LinearColor Yellow;

public:
	float R = 0.0f;
	float G = 0.0f;
	float B = 0.0f;
	float A = 1.0f;
};

FORCEINLINE bool LinearColor::EqualseInRnage(const LinearColor & InColor, float InRange) const
{
	return ((Math::Abs(R - InColor.R) < InRange) &&
		(Math::Abs(G - InColor.G) < InRange) &&
		(Math::Abs(B - InColor.B) < InRange) &&
		(Math::Abs(A - InColor.A) < InRange));
}

FORCEINLINE LinearColor LinearColor::operator+(const LinearColor & InColor) const
{
	return LinearColor(
		R + InColor.R,
		G + InColor.G,
		B + InColor.B,
		A + InColor.A
	);
}

FORCEINLINE LinearColor LinearColor::operator-(const LinearColor & InColor) const
{
	return LinearColor(
		R - InColor.R,
		G - InColor.G,
		B - InColor.B,
		A - InColor.A
	);
}

FORCEINLINE LinearColor LinearColor::operator*(const LinearColor & InColor) const
{
	return LinearColor(
		R * InColor.R,
		G * InColor.G,
		B * InColor.B,
		A * InColor.A
	);
}

inline LinearColor LinearColor::operator*(float InScalaar) const
{
	return LinearColor(
		R * InScalaar,
		G * InScalaar,
		B * InScalaar,
		A * InScalaar
	);
}

FORCEINLINE bool LinearColor::operator==(const LinearColor InColor) const
{
	return (R == InColor.R && G == InColor.G && B == InColor.B && A ==InColor.A);
}

FORCEINLINE bool LinearColor::operator!=(const LinearColor InColor) const
{
	return (R != InColor.R || G != InColor.G || B != InColor.B || A != InColor.A);
}
