#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <ctime>
#include <SDL.h>

#define PI 3.14159265

void 			die 		( std::string );
void 			debug_log	( std::string );
void			error_log	( std::string );

std::string 	i2s 		( int );
std::string 	f2s 		( float );
int				s2i			( std::string );

#ifndef TIME_INTERVAL_H__
#define TIME_INTERVAL_H__
class TimeInterval
{
protected:
	long		lastUpdate;
	float		waitDuration;

public:
	TimeInterval ( );
	TimeInterval ( int );

	void		setRate		( int );
	bool		check		( );
	int			getSteps	( );
};
#endif
