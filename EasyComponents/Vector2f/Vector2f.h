#pragma once#pragma once

#include <ostream>


class Vector2f
{
public:
	Vector2f(float theX = 0, float theY = 0) : x(theX), y(theY) {}

	const void setXY(const float theX, const float theY);
	const void setXY(const Vector2f& v);
	Vector2f getXY() const;

	Vector2f operator+(const Vector2f& v);
	Vector2f operator+(const float f);
	Vector2f operator-(const Vector2f& v);
	Vector2f operator-(const float f);
	Vector2f operator*(const Vector2f& v);
	Vector2f operator*(const float f);
	Vector2f operator=(const Vector2f& v);
	Vector2f operator=(const float f);
	Vector2f operator*=(const Vector2f& v);
	Vector2f operator*=(const float f);
	friend std::ostream& operator<<(std::ostream& out, const Vector2f vec);

public:
	float x;
	float y;
};