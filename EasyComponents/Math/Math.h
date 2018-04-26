#pragma once

class Vector2f;

#define DEG_2_RAD 3.14159265359 / 180   // as cmath returns degress for sin/cos/tan, DEG_2_RAD is needed for radian conversion


// namespace for generic functions
namespace Math
{
	Vector2f rotate_point(const Vector2f& point, const float deg);
	int get_random(const float min, const float max);
	//RectValues create_rect_values(const size_t baseValue);
	//ForceValues create_force_values(const size_t baseValue);
}
