#include "dxlib.h"
#include "keymovement.h"

//�L�[�{�[�h�̓��͂��擾
char AllKeyState[KEYCODE_NUM] = { '\0' };		//���ׂẴL�[�̏�Ԃ�����
char OldAllKeyState[KEYCODE_NUM] = { '\0' };	//���ׂẴL�[�̏��(���O)������

VOID ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[KEYCODE_NUM];

	for (int i = 0; i < KEYCODE_NUM; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); //�S�ẴL�[�̓��͏�Ԃ𓾂� �����̓|�C���^�ŕԂ����

	for (int i = 0; i < KEYCODE_NUM; i++) //�L�[��������Ă��邩��TempKey�z��Ŕ��肷��
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