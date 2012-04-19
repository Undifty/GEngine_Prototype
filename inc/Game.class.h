#ifndef GAME_H__
#define GAME_H__

#include <stdlib.h>


/*
*	GameState_e has all the different types of states
*	that the Game-object can have. The current state
*	can be retrieved by using the getState()-method.
*/
enum GameState_e
{
	GAMESTATE_INITIALIZING,		// The Game-object is currently initializing.
	GAMESTATE_RUNNING,			// Game is running.
	GAMESTATE_PAUSED,			// Game is paused.
	GAMESTATE_QUITTING,			// Game is currently quitting.
	GAMESTATE_NONE				// Game has quit, object should be destroyed.
};


/*
*
*/
class Game
{
private:
	enum GameState_e		game_state;

	static Game				*obj_instance;

	/*
	*	We only want to be able to create this object
	*	from within the static methods Initialize() and Tidy().
	*/
	Game (void);
	virtual ~Game (void);
public:

	enum GameState_e		getState			( );


	/*
	*	Initializes the Game-object.
	*	Returns 0 on success and error code on failure.
	*/
	static int				Initialize		( );


	/*
	*	Tidying up the Game-object.
	*	Returns 0 on success and error code on failure.
	*/
	static int				Tidy			( );


	/*
	*	Returns a pointer to the Game-object.
	*/
	static Game*			GetInstance		( );
};

#endif