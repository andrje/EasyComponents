#include "Vector2f.h"


// set
const void Vector2f::setXY(const float theX, const float theY)
{
	x = theX; y = theY;
}


// set
const void Vector2f::setXY(const Vector2f& v)
{
	x = v.x; y = v.y;
}


// get
Vector2f Vector2f::getXY() const
{
	return *this;
}


// add 
Vector2f Vector2f::operator+(const Vector2f& v)
{
	return Vector2f(x + v.x, y + v.y);
}


Vector2f Vector2f::operator+(const float f)
{
	return Vector2f(x + f, y +f);
}


// sub
Vector2f Vector2f::operator-(const Vector2f& v)
{
	return Vector2f(x - v.x, y - v.y);
}


Vector2f Vector2f::operator-(const float f)
{
	return Vector2f(x - f, y - f);
}


// multi
Vector2f Vector2f::operator*(const Vector2f& v)
{
	return Vector2f(x * v.x, y * v.y);
}


Vector2f Vector2f::operator*(const float f)
{
	return Vector2f(x * f, y * f);
}


// copy
Vector2f Vector2f::operator=(const Vector2f& v)
{
	return Vector2f(x = v.x, y = v.y);
}


Vector2f Vector2f::operator=(const float f)
{
	return Vector2f(x = f, y = f);
}


// multi add
Vector2f Vector2f::operator*=(const Vector2f& v)
{
	return Vector2f(x = x * v.x, y = y * v.y);
}


Vector2f Vector2f::operator*=(const float f)
{
	return Vector2f(x = x * f, y = y * f);
}


// print overload
std::ostream& operator<<(std::ostream& out, const Vector2f vec)
{
	return out << "(" << vec.x << ", " << vec.y << ")";
}