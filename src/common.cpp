#include "common.h"

void die ( std::string msg )
{
  std::cout << "ERROR: " << msg.c_str() << std::endl;

  msg = "ERROR: " + msg + "\n";

  //OutputDebugString(msg.c_str());
  exit(0);
}


void debug_log ( std::string msg )
{
  std::cout << msg << std::endl;
  msg = msg + "\n";
  //OutputDebugString(msg.c_str());
}


void error_log ( std::string msg )
{
  std::cout << msg << std::endl;
  msg = msg + "\n";
  //OutputDebugString(msg.c_str());
}


std::string 	i2s 	( int a )
{
  char buffer[ 16 ] = "";
  for ( int i=0; i<16; i++ ) buffer[i] = '\0';
  sprintf_s( buffer, "%d", a );
  return buffer;
}


std::string 	f2s 	( float a )
{
  char buffer[ 32 ] = "";
  for ( int i=0; i<16; i++ ) buffer[i] = '\0';
  sprintf_s( buffer, "%f", a );
  return buffer;
}


int		s2i	( std::string s )
{
  return atoi( s.c_str() );
}


/*
*	TimeInterval-class.
*/
/* Constructor */	TimeInterval::TimeInterval		( )
{
	lastUpdate		= SDL_GetTicks();
	waitDuration	= 0;
};

/* Constructor */	TimeInterval::TimeInterval		( int step_sec )
{
	lastUpdate		= SDL_GetTicks();
	setRate( step_sec );
};


void				TimeInterval::setRate			( int step_sec )
{
	if ( step_sec < 1 ) step_sec = 1;
	waitDuration	= 1000.0 / float( step_sec );
};


bool				TimeInterval::check				( )
{
	int currentTime = SDL_GetTicks();
	if ( lastUpdate + waitDuration <= currentTime )
	{
		lastUpdate = currentTime;
		return true;
	}
	return false;
};


int					TimeInterval::getSteps			( )
{
	int currentTime = SDL_GetTicks();
	return int( (currentTime - lastUpdate) / waitDuration );
};
