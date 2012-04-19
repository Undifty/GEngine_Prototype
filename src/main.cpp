#include <stdio.h>
#include <stdlib.h>
#include "Game.class.h"
#include "graphics.h"

int main ( int argc, char * argv[] )
{
	GFX::Init();

	Game::Initialize( );

	Game		*lv_Game	= Game::GetInstance();
	GameState_e lv_State	= GAMESTATE_NONE;

	do
	{
		lv_Game->updateInput();
		lv_Game->updateState();
		lv_Game->updateAudio();
		lv_Game->updateVideo();

		lv_State = lv_Game->getState();
	}
	while ( lv_State == GAMESTATE_RUNNING || lv_State == GAMESTATE_PAUSED );

	Game::Tidy();

	GFX::Tidy();

	return 1;
}