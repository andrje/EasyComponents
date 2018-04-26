#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

class Vector2f;
class ShapeType;

#define SAFE_DEL(x) delete x, x = nullptr

// function ptr
using creator_funcs_ptr = void(ShapeType::*)(const Vector2f&);
using creator_funcs_map = std::map<std::string, creator_funcs_ptr>;


class ShapeType
{
public:
	ShapeType(const std::string& shapeType, const std::string& shapeName, const Vector2f& widthHeight, std::shared_ptr<Vector2f>& entity_world_pos);
	~ShapeType();

	const std::string&	get_name();
	const size_t		get_num();
	const size_t		get_id();
	const float			get_width();
	const float			get_height();
	const Vector2f&		get_world_pos();
	const float			get_scaling_value();
	const float			get_deg_rotated();

	const void	set_name(const std::string& instanceName);
	const void	set_world_pos(const float theX, const float theY);
	const void	set_world_pos(const Vector2f& pos);
	const void	set_center_of_grav(const Vector2f& centerOfGrav);
	const void	set_color(const float r = 0.0, const float g = 0.0, const float b = 0.0, const float a = 255.0);

	const void	scale_shape(const float amount);
	const void	rotate_shape(const float deg);

	const void	update(const float deltaT);
	const void	render(sf::RenderWindow& rWin);

private:
	void	get_triangle_vec(const Vector2f& widthHeight);
	void	get_rectangle_vec(const Vector2f& widthHeight);
	void	get_star_vec(const Vector2f& widthHeight);

private:
	size_t		instance_num_,
				instance_id_;

	float		shape_width_,
				shape_height_,
				scaling_value_,
				deg_rotated_;

	std::string	instance_name_;

	std::shared_ptr<Vector2f>	entity_world_pos_;
	Vector2f*					this_world_pos_;
	Vector2f*					center_of_gravity_;

	std::vector<Vector2f*>	v_points_;
	sf::Vertex*				verts_;

	static const creator_funcs_map	m_creator_funcs_;
};
