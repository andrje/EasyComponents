#include "ShapeComponent.h"

#include <algorithm>
#include <string>

#include "../../../Math/Math.h"
#include "../../../Vector2f/Vector2f.h"
#include "../ShapeType/ShapeType.h"


// static init
int ShapeComponent::instance_count_ = -1;


// cTor
ShapeComponent::ShapeComponent(const std::string& name)
{
	component_type_ = new std::string("ShapeComponent");
	instance_name_ = new std::string(name);

	++instance_count_;
	instance_num_ = instance_count_;

	auto type = std::type_index(typeid(ShapeComponent));
	instance_id_ = std::hash<std::type_index>{}(type) + instance_num_;
}


// dTor
ShapeComponent::~ShapeComponent()
{
	SAFE_DEL(component_type_);
	SAFE_DEL(instance_name_);
}


// get shape
ShapeType* ShapeComponent::get_shape(const std::string& instanceName)
{
	for (auto itr = m_shapes_.begin(); itr != m_shapes_.end(); ++itr)
	{
		if (itr->second->get_name() == instanceName)
			return itr->second;
	}
	
	std::cout << "Found no shape named: " << instanceName << '\n';
	return nullptr;
}


// create shape
void ShapeComponent::create_shape(const std::string& shapeType, const std::string& shapeName, const Vector2f& widthHeight, std::shared_ptr<Vector2f>& entity_world_pos)
{
	// IMPLEMENT AND USE THIS TO CHECk STRINGS
	//std::string shape_type = shapeType;	
	//std::transform(shape_type.begin(), shape_type.end(), shape_type.begin(), ::tolower);

	if (m_shapes_.find(shapeName) == m_shapes_.end())
	{
		ShapeType* shape = new ShapeType(shapeType, shapeName, widthHeight, entity_world_pos);
		m_shapes_.emplace(std::make_pair(shapeName, shape));
	}
	else
	{
		std::cout << "A star shape already exists with name: " << shapeName << '\n';
	}
}


// update
const void ShapeComponent::update(const float deltaT)
{
	for (auto& i : m_shapes_)
		i.second->update(deltaT);
}


// render
const void ShapeComponent::render(sf::RenderWindow& rWin)
{
	for (auto& i : m_shapes_)
		i.second->render(rWin);
}
