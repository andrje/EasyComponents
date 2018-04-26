#pragma once

#include <memory>
#include <map>
#include <string>

#include "SFML/Graphics.hpp"

class Vector2f;
class Entity;

template <typename T>
using u_ptr = std::unique_ptr<T>;
using entity_map = std::map<std::string, Entity*>;

static const float FRAMES_PER_SECOND = 120.0;
static const float FIXED_FRAME_STEP = 1.0 / (float)FRAMES_PER_SECOND;


class Application
{
public:
	Application(const size_t winWidth = 640, const size_t winHeight = 360, const size_t frameRate = 60);
	~Application();

	const void update(const float deltaT);
	const void run();

private:
	u_ptr<sf::RenderWindow>		r_win_;

	u_ptr<sf::Event>			event_;
	u_ptr<sf::Clock>			clock_;
	u_ptr<Vector2f>				win_size_;

	float						frame_time_,
								delta_t_;

	entity_map					m_entities_;
};
