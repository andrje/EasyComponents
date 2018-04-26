#pragma once

#include "SFML/Window/Keyboard.hpp"


class Input
{
public:
	~Input();

	static void init();

	static void set_pressed(sf::Keyboard::Key key);
	static void set_released(sf::Keyboard::Key key);
	static bool is_key_press(sf::Keyboard::Key key);
	//static bool is_key_tap(sf::Keyboard::Key key);

	static void clear_buttons();

	static void print();

private:
	static bool* keys_;
};
