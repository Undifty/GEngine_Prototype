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
	this->game_state = GAMESTATE_INIT;
	this->game_world = new World();

	// Done initializing!
	this->game_state = GAMESTATE_RUNNING;
};



/* Destructor */		Game::~Game				( )
{
	// Release memory.
	delete this->game_world;

	// Nullify/clear variables.
	this->game_world = NULL;
	this->game_state = GAMESTATE_NONE;
};



void					Game::updateInput		( )
{
};


void					Game::updateState		( )
{
};


void					Game::updateAudio		( )
{
};


void					Game::updateVideo		( )
{
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
