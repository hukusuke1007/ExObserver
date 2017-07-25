#include "state.h"
#include "Windows.h"

namespace hukusuke {
	state::state(){
		observer_ = NULL;
	}
	state::~state(){}

	/* attach observer method. */
	void state::attach_observer(state_observer* obs){
		if (NULL == observer_) { observer_ = obs; } else {}
	}

	/* dettach observer method. */
	void state::dettach_observer() {
		if (NULL != observer_) { observer_ = NULL; } else {}
	}

	/* process_change_state method. */
	void state::process_change_state() {
		if (NULL != observer_) {
			observer_->notify_state(STATUS_START);
			Sleep(100);
			observer_->notify_state(STATUS_PROCESSING);
			Sleep(100);
			observer_->notify_state(STATUS_WAITING);
			Sleep(100);
			observer_->notify_state(STATUS_END);
		} else {}
	}
}