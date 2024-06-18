#pragma once
#include "Dxlib.h"
#include <vector>
#include <string>

using namespace std;

typedef struct _Tile
{
	int ID; //ƒ^ƒCƒ‹‚ÌID

}TILE;

typedef struct _layer
{
	vector<TILE> tiles;
	int width, height;
}LAYER;

typedef struct _TileSet
{
	int firstGrid;
	string image;
	int tileWidth, tileHeight;
	int imageWidth, imageHeight;
	int textureHandle;
}TILESET;

typedef struct _map
{
	vector<LAYER> layers;
	TILESET tileSet;
}MAP;


BOOL LoadCsv(const char* filename, LAYER& layer, int width, int height);
VOID DrawMap(const MAP& map);