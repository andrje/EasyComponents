#include "ShapeType.h"

#include <iostream>
#include <string> 

#include "../../../Math/Math.h"
#include "../../../Vector2f/Vector2f.h"
#include "../ShapeVecs/ShapeVecs.h"


// static init for map of function ptrs
const creator_funcs_map ShapeType::m_creator_funcs_ = 
{
	{ "triangle",	&ShapeType::get_triangle_vec },
	{ "rectangle",	&ShapeType::get_rectangle_vec },
	{ "star",		&ShapeType::get_star_vec }
};


 //cTor
ShapeType::ShapeType(const std::string& shapeType, const std::string& shapeName, const Vector2f& widthHeight, std::shared_ptr<Vector2f>& entity_world_pos)
{
	instance_name_		= shapeName;
	shape_width_		= widthHeight.x;
	shape_height_		= widthHeight.y;
	entity_world_pos_	= entity_world_pos;

	scaling_value_	= 1.0;
	deg_rotated_	= 0;

	this_world_pos_		= new Vector2f();
	center_of_gravity_	= new Vector2f((widthHeight.x * 0.5), (widthHeight.y * 0.5));
		
	// create points vector
	(this->*(m_creator_funcs_.find(shapeType)->second))(widthHeight);

	// create verts array
	verts_ = new sf::Vertex[v_points_.size()];
}


// dTor
ShapeType::~ShapeType()
{
	SAFE_DEL(this_world_pos_);
	SAFE_DEL(center_of_gravity_);

	for (auto& i : v_points_)
		SAFE_DEL(i);

	SAFE_DEL(verts_);
}


// get name
const std::string& ShapeType::get_name()
{
	return instance_name_;
}


// get instance num
const size_t ShapeType::get_num()
{
	return instance_id_;
}


// get instance id
const size_t ShapeType::get_id()
{
	return instance_id_;
}


// get width
const float ShapeType::get_width()
{
	return shape_width_;
}


// get height
const float ShapeType::get_height()
{
	return shape_height_;
}


// get world pos
const Vector2f& ShapeType::get_world_pos()
{
	return *this_world_pos_;
}


// get scaling
const float ShapeType::get_scaling_value()
{
	return scaling_value_;
}


// get deg roatted
const float ShapeType::get_deg_rotated()
{
	return deg_rotated_;
}


// set name
const void ShapeType::set_name(const std::string& instanceName)
{
	instance_name_ = instanceName;
}


// set world pos
const void ShapeType::set_world_pos(const float theX, const float theY)
{
	this_world_pos_->setXY(theX, theY);
}


// set world pos
const void ShapeType::set_world_pos(const Vector2f& pos)
{
	this_world_pos_->setXY(pos);
}


// set center of grav
const void ShapeType::set_center_of_grav(const Vector2f& centerOfGrav)
{
	center_of_gravity_->setXY(centerOfGrav);
}


// set color
const void ShapeType::set_color(const float r, const float g, const float b, const float a)
{
	for (size_t i = 0; i < v_points_.size(); ++i)
		verts_[i].color = sf::Color(r, g, b, a);
}


// scale
const void ShapeType::scale_shape(const float amount)
{
	scaling_value_ = amount;
	shape_width_ *= amount;
	shape_height_ *= amount;

	for (auto& i : v_points_)
		*i *= amount;
}


// rotate
const void ShapeType::rotate_shape(const float deg)
{
	deg_rotated_ = deg;

	for (size_t i = 0; i < v_points_.size(); ++i)
	{
		v_points_.at(i)->setXY(*v_points_.at(i) - *center_of_gravity_);			// reset center of gravity
		v_points_.at(i)->setXY(Math::rotate_point(*v_points_.at(i), deg));		// rotate points
		v_points_.at(i)->setXY(*v_points_.at(i) + *center_of_gravity_);			// set back center of gravity
	}
}


// get triangle vec
void ShapeType::get_triangle_vec(const Vector2f& widthHeight)
{
	v_points_ = ShapeVecs::get_triangle_points_vec(widthHeight);
}


// get rectangle vec
void ShapeType::get_rectangle_vec(const Vector2f& widthHeight)
{
	v_points_ = ShapeVecs::get_rectangle_points_vec(widthHeight);
}


// get star vec
void ShapeType::get_star_vec(const Vector2f& widthHeight)
{
	v_points_ = ShapeVecs::get_star_points_vec(widthHeight);
}


// update
const void ShapeType::update(const float deltaT)
{
	for (size_t i = 0; i < v_points_.size(); ++i)
	{
		verts_[i].position.x = v_points_.at(i)->x + this_world_pos_->x;
		verts_[i].position.y = v_points_.at(i)->y + this_world_pos_->y;
	}
}


// render
const void ShapeType::render(sf::RenderWindow& rWin)
{
	//_tracer->render(rWin);	// trajectory line & corners
	rWin.draw(verts_, v_points_.size(), sf::LinesStrip);
}



