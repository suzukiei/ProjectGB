#include "DxLib.h"
#include "Tile.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

BOOL LoadCsv(const char* fileName, LAYER& layer, int width, int height)
{
	ifstream file(fileName);
	if (!file.is_open()) {
		return FALSE;
	}

	string line;
	while (getline(file, line))
	{
		istringstream lineStream(line);
		string cell;
		while (getline(lineStream, cell, ',')) {
			TILE tile;
			tile.ID = stoi(cell);
			layer.tiles.push_back(tile);
		}
	}

	layer.width = width;
	layer.height = height;

	return TRUE;
}