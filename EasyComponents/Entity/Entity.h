#pragma once

#include <string>
#include <map>
#include <memory>

#include "SFML/Graphics/RenderWindow.hpp"
#include "../Vector2f/Vector2f.h"

class ComponentInterface;

#define SAFE_DEL(x) delete x, x = nullptr

using components_map = std::map<std::string, ComponentInterface*>;
template<typename T>
using shared_ptr = std::shared_ptr<T>;


class Entity
{
public:
	Entity(const std::string& name, const Vector2f& worldPos = Vector2f(2.0, 5.0));
	~Entity();

	const std::string*	get_name();
	const void			set_name(const std::string& name);

	template<typename T>
	void	add_component(const std::string& name);
	template<typename Y>
	Y*		get_component(const std::string& name);

	const void update(const float deltaT);
	const void render(sf::RenderWindow& rWin);

private:
	std::string*			instance_name_;

	shared_ptr<Vector2f>	entity_world_pos_;

	components_map			m_components_;

	bool tmp_bool_;	// DELETE SOMETIME LATER
};




// add component
template<typename T>
inline void Entity::add_component(const std::string& name)	// MAKE OVERLOAD FOR THIS. ONE WITH NAME, ONE WITHOUT
{
	auto it = m_components_.find(name);
	if (it == m_components_.end())
	{
		auto new_comp = new T(name);
		m_components_.insert(std::make_pair(name, new_comp));

		std::cout << "Component added: " << m_components_.find(name)->second->get_type() << '\n';
	}
	else
	{
		std::cout << "No component added as a component already exists with name: " << name << '\n';
	}
}


// get component
template<typename Y>
inline Y* Entity::get_component(const std::string& name)
{

	for (auto itr = m_components_.begin(); itr != m_components_.end(); ++itr)
	{
		if (itr->second->get_name() == name)
			return dynamic_cast<Y*>(itr->second);

		/*if (itr->second->get_name() == name)
		{
			auto template_type = std::type_index(typeid(Y));
			auto instance_type = std::type_index(typeid(*itr->second));

			if (template_type == instance_type)
				return dynamic_cast<Y*>(itr->second);
		}*/
	}

	std::cout << "Found no shape named: " << name << '\n';
	return nullptr;
}
