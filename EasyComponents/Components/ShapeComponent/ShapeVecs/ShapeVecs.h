#pragma once

#include <vector>

class Vector2f;


namespace ShapeVecs
{
	std::vector<Vector2f*> get_triangle_points_vec(const Vector2f& widthHeight);
	std::vector<Vector2f*> get_rectangle_points_vec(const Vector2f& widthHeight);
	std::vector<Vector2f*> get_star_points_vec(const Vector2f& widthHeight);
}

