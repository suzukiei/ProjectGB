#include "DxLib.h"
#include <stdio.h>
#include "keymovement.h"

//
//�����ŕϐ���p��
//


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
    SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
    SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
    if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��


    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();//����ʏ���
        SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

        DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

       

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
        ALL_KEYDOWN_UPDATE();
    }

    DxLib_End();
    return 0;
}
