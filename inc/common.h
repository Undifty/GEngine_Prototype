#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <ctime>

#define PI 3.14159265

void 			die 		( std::string );
void 			debug_log	( std::string );
void			error_log	( std::string );

std::string 	i2s 		( int );
std::string 	f2s 		( float );
int				s2i			( std::string );
