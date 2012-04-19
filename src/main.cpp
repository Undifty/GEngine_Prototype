#include <stdio.h>
#include <stdlib.h>
#include "Game.class.h"
#include "graphics.h"

int main ( int argc, char * argv[] )
{
	GFX::Init();

	Game::Initialize( );
	Game * lv_Game = Game::GetInstance();

	while ( lv_Game->getState() == GAMESTATE_RUNNING )
	{
		lv_Game->updateInput();
		lv_Game->updateState();
		lv_Game->updateAudio();
		lv_Game->updateVideo();
		
		break; // Prevent looping until input is added.
	}

	Game::Tidy();

	GFX::Tidy();

	return 1;
}