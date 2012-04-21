#ifndef MAP_H__
#define MAP_H__

#include <iostream>
#include <cstring>
#include <vector>
#include "graphics.h"

class MapVertex;

typedef std::vector<MapVertex>		Vertex_Arr1D;
typedef std::vector<Vertex_Arr1D>	Vertex_Arr2D;


class Map
{
private:
	Vertex_Arr2D		vertices;

	int					map_width;
	int					map_height;

public:
	Map ( );
	virtual ~Map ( );

	void		parseHeightmap	( std::string, int, int );
	void		resizeCanvas	( int, int );

	void		render		( );
};


class MapVertex
{
public:
	MapVertex ( float, float, float );
	~MapVertex ( );

	float x, y, z;
};

#endif