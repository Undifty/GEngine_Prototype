#include <stdio.h>
#include <stdlib.h>
#include "Game.class.h"

int main ( int argc, char * argv[] )
{
	Game::Initialize();
	Game * lv_Game = Game::GetInstance();

	while ( lv_Game->getState() == GAMESTATE_RUNNING )
	{
		
	}

	Game::Tidy();

	return 1;
}