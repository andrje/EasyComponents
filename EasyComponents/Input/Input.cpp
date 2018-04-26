#include "Input.h"

#include <iostream>


// static init
bool* Input::keys_ = nullptr;


// dTor
Input::~Input()
{
	delete keys_;
	keys_ = nullptr;
}


// init
void Input::init()
{
	keys_ = new bool[sf::Keyboard::KeyCount];

	for (size_t i = 0; i < sf::Keyboard::KeyCount; i++)
		keys_[i] = false;
}


// set pressed
void Input::set_pressed(sf::Keyboard::Key key)
{
	keys_[key] = true;
}


// set released
void Input::set_released(sf::Keyboard::Key key)
{
	keys_[key] = false;
}


// is pressed
bool Input::is_key_press(sf::Keyboard::Key key)
{
	return keys_[key];
}


// clear buttons
void Input::clear_buttons()
{
	for (size_t i = 0; i < sf::Keyboard::KeyCount; i++)
		keys_[i] = false;
}


// print
void Input::print()
{
	for (size_t i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		if (keys_[i] != 0)
			std::cout << i << std::endl;
	}
}
