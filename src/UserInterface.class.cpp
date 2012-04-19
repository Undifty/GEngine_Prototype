#include "UserInterface.class.h"

/* Constructor */	UserInterface::UserInterface		( )
{
};


/* Destructor */	UserInterface::~UserInterface		( )
{
};


void				UserInterface::render				( )
{
	/*
	glColor3f(1.0, 1.0, 1.0);
	glBegin( GL_LINES );
		glVertex2f(0,0);
		glVertex2f(100,50);
	glEnd();
	*/

	// minimap?
	glColor3f(1.0, 1.0, 1.0);
	float radius = 64;
	int x = 64, y = 64;
	glBegin( GL_LINE_LOOP );
	float max = 2*PI;
	float step = PI/36.0;
	for ( float i=0 ; i<max ; i+=step )
	{
		glVertex2f( x + sin(i) * radius, y + cos(i) * radius );
	}
	glEnd();
};