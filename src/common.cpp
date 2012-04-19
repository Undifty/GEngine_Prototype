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
