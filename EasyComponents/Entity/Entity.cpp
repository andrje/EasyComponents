#include "Entity.h"

#include <iostream>

#include "../Components/ComponentInterface/ComponentInterface.h"
#include "../Components/ShapeComponent/ShapeComponent/ShapeComponent.h"
#include "../Components/ShapeComponent/ShapeType/ShapeType.h"

#include "../Input/Input.h"
#include "SFML\Window\Keyboard.hpp"


// cTor
Entity::Entity(const std::string& instanceName, const Vector2f& worldPos)
	:
	instance_name_(new std::string(instanceName)),
	entity_world_pos_(std::make_shared<Vector2f>(worldPos))
{
	add_component<ShapeComponent>("Shapes_1");

	get_component<ShapeComponent>("Shapes_1")->create_shape("star", "MyShape_1", Vector2f(50.0, 50.0), entity_world_pos_);
	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->set_color(255.0, 255.0, 0.0);
	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->set_world_pos(-get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->get_width(), 125.0);

	get_component<ShapeComponent>("Shapes_1")->create_shape("rectangle", "MyShape_2", Vector2f(50.0, 50.0), entity_world_pos_);
	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_2")->set_color(255.0, 0.0, 255.0);
	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_2")->set_world_pos(100.0, 100.0);

	get_component<ShapeComponent>("Shapes_1")->create_shape("triangle", "MyShape_3", Vector2f(50.0, 50.0), entity_world_pos_);
	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_3")->set_color(0.0, 255.0, 255.0);
	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_3")->set_world_pos(300.0, 200.0);

	tmp_bool_ = false;
}


// dTor
Entity::~Entity()
{
	SAFE_DEL(instance_name_);
}


// get name
const std::string* Entity::get_name()
{
	return instance_name_;
}


// set name
const void Entity::set_name(const std::string& name)
{
	*instance_name_ = name;
}


// update
const void Entity::update(const float deltaT)
{
	Vector2f current_pos = get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->get_world_pos();
	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->set_world_pos(current_pos.x + (40.0 * deltaT), current_pos.y);

	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->rotate_shape(80.0 * deltaT);
	get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_2")->rotate_shape(-80.0 * deltaT);

	float width = get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->get_width();

	if (width < 50.0 && tmp_bool_)
		tmp_bool_ = false;

	if (width > 100.0 && !tmp_bool_)
		tmp_bool_ = true;

	if (!tmp_bool_)
	{
		get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->scale_shape(1.005);
		get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_3")->scale_shape(0.995);
	}

	if (tmp_bool_)
	{
		get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_1")->scale_shape(0.995);
		get_component<ShapeComponent>("Shapes_1")->get_shape("MyShape_3")->scale_shape(1.005);
	}



	for (auto& i : m_components_)
		i.second->update(deltaT);

	if (Input::is_key_press(sf::Keyboard::A))
		std::cout << "hej" << '\n';
}


// render
const void Entity::render(sf::RenderWindow& rWin)
{
	for (auto& i : m_components_)
		i.second->render(rWin);
}
