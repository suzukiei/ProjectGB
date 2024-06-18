#include "DxLib.h"
#include <stdio.h>
#include "keymovement.h"
#include "Tile.h"

//
//�����ŕϐ���p��
//


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
    SetGraphMode(1280,720, 32);//��ʃT�C�Y�w��
    SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
    if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��

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

    if (!LoadCsv("IMAGE\\map_�}�b�v��.csv", bottomLayer, mapWidth, mapHeight) ||
        !LoadCsv("IMAGE\\map_�}�b�v��.csv", middleLayer, mapWidth, mapHeight) ||
        !LoadCsv("IMAGE\\map_�}�b�v��.csv", topLayer, mapWidth, mapHeight)) {
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
        ClearDrawScreen();//����ʏ���
        SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

        DrawMap(map);
       

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
       
    }

    DxLib_End();
    return 0;
}
