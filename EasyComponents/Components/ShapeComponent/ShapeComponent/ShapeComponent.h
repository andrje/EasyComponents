#pragma once

#include <map>
#include <memory>

#include "../../ComponentInterface/ComponentInterface.h"

class Vector2f;
class ShapeType;

using shape_map = std::map<std::string, ShapeType*>;


class ShapeComponent : public ComponentInterface
{
public:
	ShapeComponent(const std::string& name);
	~ShapeComponent();

	ShapeType*	get_shape(const std::string& instanceName);

	void		create_shape(const std::string& shapeType, const std::string& shapeName, const Vector2f& widthHeight, std::shared_ptr<Vector2f>& entity_world_pos);

	virtual const void update(const float deltaT) override;
	virtual const void render(sf::RenderWindow& rWin) override;

private:
	static int	instance_count_;

	shape_map	m_shapes_;
};
