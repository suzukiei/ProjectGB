#include "dxlib.h"
#include "keymovement.h"

//キーボードの入力を取得
char AllKeyState[KEYCODE_NUM] = { '\0' };		//すべてのキーの状態が入る
char OldAllKeyState[KEYCODE_NUM] = { '\0' };	//すべてのキーの状態(直前)が入る

VOID ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[KEYCODE_NUM];

	for (int i = 0; i < KEYCODE_NUM; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); //全てのキーの入力状態を得る 引数はポインタで返される

	for (int i = 0; i < KEYCODE_NUM; i++) //キーが押されているかをTempKey配列で判定する
	{
		if (TempKey[i] != 0)
		{
			AllKeyState[i]++;
		}
		else
		{
			AllKeyState[i] = 0;
		}
	}
	return;
}