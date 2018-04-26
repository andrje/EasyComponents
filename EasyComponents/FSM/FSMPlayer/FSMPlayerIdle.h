#pragma once

#include "FSMPlayerVirtual.h"


class FSMPlayerIdle : public FSMPlayerVirtual
{
public:
	FSMPlayerIdle();
	~FSMPlayerIdle();

	virtual FSMPlayerVirtual*	handle_input()	override;
	virtual void				update()		override;
};