#pragma once
#include "stdafx.h"
#include "define_common.h"

using namespace std;
namespace hukusuke {

	class state_observer;							// �錾
	/*--------------------------------*/
	/* state.                         */
	/*--------------------------------*/
	class state
	{
	public:
		state();
		~state();

		void attach_observer(state_observer* obs);	// �I�u�U�[�o�o�^.
		void dettach_observer();					// �I�u�U�[�o����.
		void process_change_state();

	private:
		state_observer* observer_;
	};

	/*--------------------------------*/
	/* state_observer.                */
	/*--------------------------------*/
	class state_observer
	{
	public:
		state_observer() {};
		virtual ~state_observer() {};

		/* Virtual method*/
		virtual void notify_state(const STATUS status) = 0;
	};
}

