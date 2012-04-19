#ifndef GAME_H__
#define GAME_H__

class Game
{
private:

public:
	Game ( );
	virtual ~Game ( );

	bool		running			( );


	/*
	*	Initializes the Game-object.
	*	Returns 0 on success and error code on failure.
	*/
	static int		Initialize		( );


	static int		Tidy			( );
};

#endif