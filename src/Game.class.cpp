#include "Game.class.h"

/************************************
*	REGULAR PROPERTIES AND METHODS.
************************************/

enum GameState_e		Game::getState			( )
{
	return game_state;
};



/* Constructor */		Game::Game				( )
{
	for ( int i=0 ; i<512 ; i++ ) keys[i] = false;

	steps_state = 0;

	clock_input.setRate(1000);
	clock_state.setRate(16);
	clock_audio.setRate(1);
	clock_video.setRate(30);

	actor_next	= 0;
	actor_count = 0;

	temp_ent	= Entity();
	Point3f start_pos(1,0.05,1);
	temp_ent.setPoint( &start_pos );
	/*
	temp_ent.getPoint()->x = 2;
	temp_ent.getPoint()->z = 4;
	temp_ent.getPoint()->y = 1;
	*/
	temp_facing = Vector2f( 1, 0 );

	actor[0].setOwner( &temp_ent );
	actor[0].setOffset( ACTORPLACEMENT_RELATIVE, Point3f(0,0,0) );
	actor_active.push_back( &actor[0] );
	actor_count++;
	actor_next++;


	// Begin initializing.
	this->game_state	= GAMESTATE_INIT;
	this->game_ui		= new UserInterface();
	this->game_world	= new World();
	this->game_camera	= new Camera();

	// Done initializing!
	this->game_state	= GAMESTATE_RUNNING;
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
	if ( !clock_state.check() ) return /* Do Nothing */;
	steps_state++;

	Point3f new_pos = *(game_camera->getPoint());
	if ( this->keys[ SDLK_KP8 ] )
	{
		new_pos.z -= 0.25;
	}
	if ( this->keys[ SDLK_KP2 ] )
	{
		new_pos.z += 0.25;
	}
	if ( this->keys[ SDLK_KP4 ] )
	{
		new_pos.x -= 0.25;
	}
	if ( this->keys[ SDLK_KP6 ] )
	{
		new_pos.x += 0.25;
	}
	game_camera->getPoint()->x = new_pos.x;
	game_camera->getPoint()->y = new_pos.y;
	game_camera->getPoint()->z = new_pos.z;

	Vector3f ent_fac_vec = *(temp_ent.getFacing());
	double facing_angle = 0;
	if ( this->keys[ SDLK_LEFT ] )
	{
		facing_angle = -PI / 36.0;
	}
	if ( this->keys[ SDLK_RIGHT ])
	{
		facing_angle = PI / 36.0;
	}
	double fx = ent_fac_vec.x;
	double fy = ent_fac_vec.z;
	ent_fac_vec.x = ( fx * cos(facing_angle) - fy * sin(facing_angle) );
	ent_fac_vec.z = ( fy * cos(facing_angle) + fx * sin(facing_angle) );
	ent_fac_vec.normalize();

	temp_ent.setFacing( &ent_fac_vec );

	
	Point3f ent_new_pos = *(temp_ent.getPoint());
	if ( this->keys[ SDLK_UP ] )
	{
		ent_new_pos += (ent_fac_vec * 0.25);
	}
	if ( this->keys[ SDLK_DOWN ] )
	{
		ent_new_pos -= (ent_fac_vec * 0.25);
	}
	temp_ent.setPoint( &ent_new_pos );


	double angle = 0;
	if ( this->keys[ SDLK_a ] )
	{
		angle = -PI / 36.0;
	}
	if ( this->keys[ SDLK_d ] )
	{
		angle = PI / 36.0;
	}

	double x = temp_facing.x;
	double y = temp_facing.y;
		
	temp_facing.x = ( x * cos(angle) - y * sin(angle) );
	temp_facing.y = ( y * cos(angle) + x * sin(angle) );
};


void					Game::updateAudio		( )
{
	if ( this->game_state != GAMESTATE_RUNNING ) return /* Do Nothing */;
	if ( !clock_audio.check() ) return /* Do Nothing */;
};


void					Game::updateVideo		( )
{
	if ( this->game_state != GAMESTATE_RUNNING ) return /* Do Nothing */;
	if ( !clock_video.check() ) return /* Do Nothing */;

	Vector3f	cam_targ	= *(game_camera->getTarget());
	Vector3f	cam_up		= *(game_camera->getUp());
	Point3f		cam_pos		= *(game_camera->getPoint());

	gluLookAt( 
		cam_pos.x + cam_targ.x, cam_pos.y + cam_targ.y, cam_pos.z + cam_targ.z, 
		cam_pos.x,	cam_pos.y,	cam_pos.z, 
		cam_up.x,	cam_up.y,	cam_up.z
	);

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	GFX::Prepare3D();
	game_world->render();
	int n = actor_active.size();
	for ( int i=0 ; i<n ; i++ )
	{
		actor_active[i]->render();
	}
	

	Vector3f xv( 10, 0, 0 );
	Vector3f yv( 0, 10, 0 );
	Vector3f zv( 0, 0, 10 );
	Point3f orig( 0, 0, 0 );

	xv.render( &orig, 1, 0, 0 );
	yv.render( &orig, 0, 1, 0 );
	zv.render( &orig, 0, 0, 1 );

	Point3f center( 8, 2, 8 );
	xv.render( &center, 1, 0, 1 );

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
