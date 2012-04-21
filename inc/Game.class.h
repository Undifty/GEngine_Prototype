#ifndef GAME_H__
#define GAME_H__

#include <stdlib.h>
#include <vector>
#include "graphics.h"
#include "common.h"
#include "UserInterface.class.h"
#include "Vector.class.h"
#include "World.class.h"
#include "Entity.class.h"
#include "Camera.class.h"
#include "Actor.class.h"


typedef std::vector<Actor*> Actor_Arr;


/*
*	GameState_e has all the different types of states
*	that the Game-object can have. The current state
*	can be retrieved by using the getState()-method.
*/
enum	GameState_e
{
	GAMESTATE_INIT		=1,		// The Game-object is currently initializing.
	GAMESTATE_RUNNING	=3,		// Game is running.
	GAMESTATE_PAUSED	=7,		// Game is paused.
	GAMESTATE_QUIT		=5,		// Game is currently quitting.
	GAMESTATE_NONE		=0		// Game has quit, object should be destroyed.
};


/*
*
*/
class Game
{
private:
	TimeInterval			clock_input;
	TimeInterval			clock_state;
	TimeInterval			clock_audio;
	TimeInterval			clock_video;
	long					steps_state;

	enum GameState_e		game_state;

	World*					game_world;
	UserInterface*			game_ui;
	Camera*					game_camera;

	int						actor_count;
	int						actor_next;
	Actor					actor[1024];
	Actor_Arr				actor_active;

	// temporary manages input, should be refactored into other class or function
	bool keys[1024];
	float	mouse_step_x;
	float	mouse_step_y;
	float	mouse_sensitivity;

	static Game				*obj_instance;

	/*
	*	We only want to be able to create this object
	*	from within the static methods Initialize() and Tidy().
	*/
	Game (void);
	virtual ~Game (void);

public:

	// Temporary variables.
	Entity					temp_ent;
	Vector2f				temp_facing;

	enum GameState_e		getState			( );

	void					updateInput			( );
	void					updateState			( );
	void					updateAudio			( );
	void					updateVideo			( );


	/*
	*	Initializes the Game-object.
	*	Returns 0 on success and error code on failure.
	*/
	static int				Initialize			( );


	/*
	*	Tidying up the Game-object.
	*	Returns 0 on success and error code on failure.
	*/
	static int				Tidy				( );


	/*
	*	Returns a pointer to the Game-object.
	*/
	static Game*			GetInstance			( );
};

#endif