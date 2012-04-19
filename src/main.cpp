#include <stdio.h>
#include <stdlib.h>
#include "../inc/Game.class.h"

int main ( int argc, char * argv[] )
{
	Game::Initialize();
	Game * lv_Game = Game::GetInstance();

	while ( lv_Game->running() )
	{
		
	}

	Game::Tidy();

	return 1;
}