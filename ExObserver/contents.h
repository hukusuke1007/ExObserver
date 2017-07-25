#pragma once
#include "stdafx.h"
#include "state.h"
#include "define_common.h"

using namespace std;
namespace hukusuke {
	class contents : public state_observer
	{
	public:
		contents();
		~contents();

		/* Method */
		void operator()();						// thread用.
		bool get_completed_flag();

	private:

		/* Method */
		void process_();
		void notify_state(const STATUS status);	// オブザーバ通知用.

		/* Veriable*/
		bool   is_completed_;
		state* state_;
	};

}

