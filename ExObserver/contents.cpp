#include "contents.h"
#include "logout.h"

namespace hukusuke {

	/*--------------------------------*/
	/* contents.                      */
	/*--------------------------------*/
	/* Constructor */
	contents::contents(){
		is_completed_ = false;

		// �I�u�U�[�o�o�^����.
		state_ = new state();
		state_->attach_observer(this);
	}

	/* Destructor */
	contents::~contents(){
		if (NULL != state_) {

			// �I�u�U�[�o��������.
			state_->dettach_observer();

			// �㏈��.
			delete state_;
			state_ = NULL;
		} else {}
	}

	/* Operator method. */
	void contents::operator()() {
		process_();
	}

	/* Get completed flag method. */
	bool contents::get_completed_flag() {
		return is_completed_;
	}

	/* process method. */
	void contents::process_() {
		if (NULL != state_) state_->process_change_state();
	}
	/* notify state from observer.*/
	void contents::notify_state(const STATUS status) {
		LOG_OUTPUT("%d", status);
		if (STATUS_END == status) { is_completed_ = true; } else {}
	}

}
