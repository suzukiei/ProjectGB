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

				if (ID == -1)continue;
				// タイルIDがfirstgidより小さい場合はスキップ
				if (ID < map.tileSet.firstGrid) continue;

				ID -= map.tileSet.firstGrid;
				int tilesPerRow = map.tileSet.imageWidth / map.tileSet.tileWidth;
				int tileX = (ID % tilesPerRow) * map.tileSet.tileWidth;
				int tileY = (ID / tilesPerRow) * map.tileSet.tileHeight;

				DrawRectGraph(x * map.tileSet.tileWidth, y * map.tileSet.tileHeight, tileX, tileY, 
							map.tileSet.tileWidth, map.tileSet.tileHeight, 
							map.tileSet.textureHandle, true, false);
			}
		}
	}
}