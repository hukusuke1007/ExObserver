// ExObserver.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
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
	
	// 状態変化の処理開始(非同期).
	thread t1(ref(cont));

	// 状態が完了するまで待つ.
	while (true)
	{
		LOG_OUTPUT("wait...");
		if (true == cont.get_completed_flag()) break;
		Sleep(30);
	}

	// スレッドの待ち合わせ.
	t1.join();

	LOG_OUTPUT("Terminate.");
	return 0;
}
