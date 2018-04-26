#pragma once

#include <string>
#include <typeindex>
#include <memory>
#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"

class ShapeType;

#define SAFE_DEL(x) delete x, x = nullptr


class ComponentInterface
{
public:
	virtual ~ComponentInterface();

	const std::string&	get_type();
	const std::string&	get_name();
	const size_t		get_id();

	virtual const void	update(const float deltaT) = 0;
	virtual const void	render(sf::RenderWindow& rWin) = 0;

protected:
	std::string*	component_type_;
	std::string*	instance_name_;

	size_t			instance_num_;
	size_t			instance_id_;
};
