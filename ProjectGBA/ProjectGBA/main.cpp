#include "DxLib.h"
#include <stdio.h>
#include "keymovement.h"
#include "Tile.h"

//
//ここで変数を用意
//


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    ChangeWindowMode(TRUE);//非全画面にセット
    SetGraphMode(1280,720, 32);//画面サイズ指定
    SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
    if (DxLib_Init() == 1) { return -1; }//初期化に失敗時にエラーを吐かせて終了

    MAP map;
    TILESET tileset;
    tileset.firstGrid = 0;
    tileset.image = "IMAGE\\mapchip1.png";
    tileset.tileWidth = 32;
    tileset.tileHeight = 32;
    tileset.imageWidth = 1024;
    tileset.imageHeight = 1312;
    tileset.textureHandle = LoadGraph(tileset.image.c_str());
    
    map.tileSet = tileset;

    LAYER bottomLayer, middleLayer, topLayer;
    int mapWidth = 90;
    int mapHeight = 50;

    if (!LoadCsv("IMAGE\\map_マップ下.csv", bottomLayer, mapWidth, mapHeight) ||
        !LoadCsv("IMAGE\\map_マップ中.csv", middleLayer, mapWidth, mapHeight) ||
        !LoadCsv("IMAGE\\map_マップ上.csv", topLayer, mapWidth, mapHeight)) {
        MessageBox(NULL, "Failed to load map", "Error", MB_OK);
        DxLib_End();
        return -1;
    }

    map.layers.push_back(bottomLayer);
    map.layers.push_back(middleLayer);
    map.layers.push_back(topLayer);

    while (ProcessMessage() == 0)
    {

        ALL_KEYDOWN_UPDATE();
        ClearDrawScreen();//裏画面消す
        SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

        DrawMap(map);
       

        ScreenFlip();//裏画面を表画面にコピー
       
    }

    DxLib_End();
    return 0;
}
