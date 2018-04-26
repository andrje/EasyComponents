#include "ShapeVecs.h"

#include "../../../Vector2f/Vector2f.h"


namespace ShapeVecs
{
	// get triangle points
	std::vector<Vector2f*> get_triangle_points_vec(const Vector2f& widthHeight)
	{
		std::vector<Vector2f*> v_points;

		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 0.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 1.00), (widthHeight.y * 1.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 1.00)));

		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 0.00)));

		return v_points;
	}


	// get rect points
	std::vector<Vector2f*> get_rectangle_points_vec(const Vector2f& widthHeight)
	{
		std::vector<Vector2f*> v_points;

		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 0.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 1.00), (widthHeight.y * 0.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 1.00), (widthHeight.y * 1.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 1.00)));

		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 0.00)));

		return v_points;
	}


	// get star points
	std::vector<Vector2f*> get_star_points_vec(const Vector2f& widthHeight)
	{
		std::vector<Vector2f*> v_points;

		v_points.push_back(new Vector2f((widthHeight.x * 0.50), (widthHeight.y * 0.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.65), (widthHeight.y * 0.40)));
		v_points.push_back(new Vector2f((widthHeight.x * 1.00), (widthHeight.y * 0.40)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.75), (widthHeight.y * 0.65)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.90), (widthHeight.y * 1.00)));

		v_points.push_back(new Vector2f((widthHeight.x * 0.50), (widthHeight.y * 0.80)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.10), (widthHeight.y * 1.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.25), (widthHeight.y * 0.65)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 0.40)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.35), (widthHeight.y * 0.40)));

		v_points.push_back(new Vector2f((widthHeight.x * 0.50), (widthHeight.y  * 0.00)));

		return v_points;

		/*std::vector<Vector2f*> v_points;

		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 0.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.50), (widthHeight.y * 1.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 1.00), (widthHeight.y * 0.00)));
		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 0.60)));
		v_points.push_back(new Vector2f((widthHeight.x * 1.00), (widthHeight.y * 0.60)));

		v_points.push_back(new Vector2f((widthHeight.x * 0.00), (widthHeight.y * 0.00)));

		return v_points;*/
	}
}


