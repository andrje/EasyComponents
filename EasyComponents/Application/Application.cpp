#include "Application.h"

#include <iostream>

#include "../Vector2f/Vector2f.h"
#include "../Entity/Entity.h"
#include "../Components/ComponentInterface/ComponentInterface.h"
#include "../Input/Input.h"


// cTor
Application::Application(const size_t winWidth, const size_t winHeight, const size_t frameRate)
	:
	r_win_(new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "App")),
	event_(new sf::Event()),
	clock_(new sf::Clock()),
	win_size_(new Vector2f(winWidth, winHeight))
{
	Input::init();

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	r_win_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(winWidth, winHeight), "App", sf::Style::Default, settings);

	Entity* entity = new Entity("Entity_1");
	m_entities_.insert(std::make_pair(*entity->get_name(), entity));
}


// dTor
Application::~Application()
{}


// update
const void Application::update(const float deltaT)
{
	frame_time_ += deltaT;

	if (frame_time_ > FIXED_FRAME_STEP)
	{
		r_win_->clear(sf::Color::Black);

		for (auto i : m_entities_)
		{
			i.second->update(frame_time_);
			i.second->render(*r_win_);
		}

		r_win_->display();

		frame_time_ -= FIXED_FRAME_STEP;
	}
}


// run
const void Application::run()
{
	while (r_win_->isOpen())
	{
		while (r_win_->pollEvent(*event_))
		{
			switch (event_->type)
			{
			case sf::Event::Closed:
				r_win_->close();
				break;

			case sf::Event::KeyPressed:
				Input::set_pressed(event_->key.code);
				break;

			case sf::Event::KeyReleased:
				Input::set_released(event_->key.code);
				break;
			}
		}

		delta_t_ = clock_->restart().asSeconds();

		update(delta_t_);
	}
}
