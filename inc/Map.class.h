#ifndef MAP_H__
#define MAP_H__

#include <vector>
#include "graphics.h"

class MapVertex;

typedef std::vector<MapVertex>		Vertex_Arr1D;


class Map
{
private:
	Vertex_Arr1D		vertices;

	int					map_width;
	int					map_height;

public:
	Map ( );
	virtual ~Map ( );

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