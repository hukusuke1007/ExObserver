// ExObserver.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "logout.h"
#include "contents.h"
#include "Windows.h"
#include <thread>

using namespace std;
using namespace hukusuke;

/* main function. */
int main(void) {
	LOG_OUTPUT("Start.");

	contents cont;
	
	// ��ԕω��̏����J�n(�񓯊�).
	thread t1(ref(cont));

	// ��Ԃ���������܂ő҂�.
	while (true)
	{
		LOG_OUTPUT("wait...");
		if (true == cont.get_completed_flag()) break;
		Sleep(30);
	}

	// �X���b�h�̑҂����킹.
	t1.join();

	LOG_OUTPUT("Terminate.");
	return 0;
}
