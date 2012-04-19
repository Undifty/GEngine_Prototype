#include "Game.class.h"

/************************************
*	REGULAR PROPERTIES AND METHODS.
************************************/

enum GameState_e		Game::getState			( )
{
	return GAMESTATE_RUNNING;
};



/* Constructor */		Game::Game				( )
{
	// Begin initializing.
	this->game_state	= GAMESTATE_INIT;
	this->game_ui		= new UserInterface();
	this->game_world	= new World();

	// Done initializing!
	this->game_state = GAMESTATE_RUNNING;
};



/* Destructor */		Game::~Game				( )
{
	// Release memory.
	delete this->game_world;
	delete this->game_ui;

	// Nullify/clear variables.
	this->game_world	= NULL;
	this->game_ui		= NULL;
	this->game_state	= GAMESTATE_NONE;
};



void					Game::updateInput		( )
{
	SDL_Event lv_Event;
	while ( SDL_PollEvent( &lv_Event ) )
	{
		switch ( lv_Event.type )
		{
			case SDL_QUIT:
				this->game_state = GAMESTATE_QUIT;
				debug_log( "Quitting Game (Window was closed)!" );
				break;

			case SDL_KEYDOWN:
				if ( lv_Event.key.keysym.sym == SDLK_ESCAPE )
				{
					this->game_state = GAMESTATE_QUIT;
					debug_log( "Quitting Game (ESCAPE was pressed)!" );
				}
				break;

			default:
				break;
		}
	}
};


void					Game::updateState		( )
{
	if ( this->game_state != GAMESTATE_RUNNING ) return /* Do Nothing */;
	debug_log( "State-update!" );
};


void					Game::updateAudio		( )
{
	if ( this->game_state != GAMESTATE_RUNNING ) return /* Do Nothing */;
};


void					Game::updateVideo		( )
{
	if ( this->game_state != GAMESTATE_RUNNING ) return /* Do Nothing */;

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	GFX::Prepare3D();
	game_world->render();

	GFX::Prepare2D();
	game_ui->render();

	SDL_GL_SwapBuffers();
};


/**********************************
*	STATIC PROPERTIES AND METHODS.
***********************************/

Game*					Game::obj_instance = NULL;


int						Game::Initialize		( )
{
	if ( Game::obj_instance == NULL )
	{
		Game::obj_instance = new Game();
		return 0;
	}
	return -1;
};


int						Game::Tidy				( )
{
	if ( Game::obj_instance != NULL )
	{
		delete Game::obj_instance;
		Game::obj_instance = NULL;
		return 0;
	}
	return -1;
};


Game*					Game::GetInstance		( )
{
	return Game::obj_instance;
};
