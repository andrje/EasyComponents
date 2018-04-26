#include "Math.h"

#include <cmath>
#include <cstdlib>
#include <random>
#include <functional>

#include "SFML//System.hpp"

// forwarded
#include "../Vector2f/Vector2f.h"


namespace Math
{
	// matrix rotation
	Vector2f rotate_point(const Vector2f& point, const float deg)
	{
		float cos_rad, sin_rad;
		cos_rad = static_cast<float>(std::cos(deg * DEG_2_RAD));
		sin_rad = static_cast<float>(std::sin(deg * DEG_2_RAD));

		Vector2f rotated;
		rotated.x = point.x * cos_rad - point.y * sin_rad;
		rotated.y = point.x * sin_rad + point.y * cos_rad;

		return rotated;
	}


	// random number generator
	int get_random(const float min, const float max)
	{
		int range = max - min + 1;

		return rand() % range + min;
	}
}