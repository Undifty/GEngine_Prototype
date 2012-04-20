#ifndef USER_INTERFACE_H__
#define USER_INTERFACE_H__

class UserInterface;

#include "graphics.h"
#include "Game.class.h"
#include "Vector.class.h"

class UserInterface
{
private:
public:
	UserInterface();
	virtual ~UserInterface();

	void		render		( );
};

#endif