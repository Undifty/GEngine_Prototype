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
	for ( int i=0 ; i<512 ; i++ ) keys[i] = false;

	// Begin initializing.
	this->game_state	= GAMESTATE_INIT;
	this->game_ui		= new UserInterface();
	this->game_world	= new World();
	this->game_camera	= new Camera();

	// Done initializing!
	this->game_state = GAMESTATE_RUNNING;
};



/* Destructor */		Game::~Game				( )
{
	// Release memory.
	delete this->game_world;
	delete this->game_ui;
	delete this->game_camera;

	// Nullify/clear variables.
	this->game_world	= NULL;
	this->game_ui		= NULL;
	this->game_camera	= NULL;
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
				else
				{
					this->keys[ lv_Event.key.keysym.sym ] = true;
				}
				break;

			case SDL_KEYUP:
				this->keys[ lv_Event.key.keysym.sym ] = false;
				break;

			default:
				break;
		}
	}
};


void					Game::updateState		( )
{
	if ( this->game_state != GAMESTATE_RUNNING ) return /* Do Nothing */;
	step++;

	Point3f new_pos = *(game_camera->getPoint());
	if ( this->keys[ SDLK_UP ] )
	{
		new_pos.z += 0.25;
	}
	if ( this->keys[ SDLK_DOWN ] )
	{
		new_pos.z -= 0.25;
	}
	if ( this->keys[ SDLK_LEFT ] )
	{
		new_pos.x -= 0.25;
	}
	if ( this->keys[ SDLK_RIGHT ] )
	{
		new_pos.x += 0.25;
	}
	game_camera->getPoint()->x = new_pos.x;
	game_camera->getPoint()->y = new_pos.y;
	game_camera->getPoint()->z = new_pos.z;
	//debug_log( "State-update!" );
};


void					Game::updateAudio		( )
{
	if ( this->game_state != GAMESTATE_RUNNING ) return /* Do Nothing */;
};


void					Game::updateVideo		( )
{
	if ( this->game_state != GAMESTATE_RUNNING ) return /* Do Nothing */;

	Vector3f	cam_targ	= *(game_camera->getTarget());
	Vector3f	cam_up		= *(game_camera->getUp());
	Point3f		cam_pos		= *(game_camera->getPoint());

	gluLookAt( 
		cam_targ.x, cam_targ.y, cam_targ.z, 
		cam_pos.x,	cam_pos.y,	cam_pos.z, 
		cam_up.x,	cam_up.y,	cam_up.z
	);

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
