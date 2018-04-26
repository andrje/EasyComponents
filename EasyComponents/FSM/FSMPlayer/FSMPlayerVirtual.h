#pragma once

#include <iostream>

#include "../../Input/Input.h"


class FSMPlayerVirtual
{
public:
	virtual ~FSMPlayerVirtual() {}

	virtual FSMPlayerVirtual*	handle_input() = 0;
	virtual void				update() = 0;
};