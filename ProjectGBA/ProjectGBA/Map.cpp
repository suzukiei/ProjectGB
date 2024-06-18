#include "Tile.h"
#include "DxLib.h"

VOID DrawMap(const MAP& map)
{
	for (const LAYER& layer : map.layers)
	{
		for (int y = 0; y < layer.height; ++y)
		{
			for (int x = 0; x < layer.width; ++x)
			{
				int index = y * layer.width + x;
				int ID = layer.tiles[index].ID;

				if (ID == 0)continue;

				ID -= map.tileSet.firstGrid;
				int tileX = (ID % (map.tileSet.imageWidth / map.tileSet.imageWidth) * map.tileSet.tileWidth);
				int tileY = (ID / (map.tileSet.imageWidth / map.tileSet.tileWidth)) * map.tileSet.tileHeight;

				DrawRectGraph(x * map.tileSet.tileWidth, y * map.tileSet.tileHeight, tileX, tileY, 
							map.tileSet.tileWidth, map.tileSet.tileHeight, 
							map.tileSet.textureHandle, true, false);
			}
		}
	}
}