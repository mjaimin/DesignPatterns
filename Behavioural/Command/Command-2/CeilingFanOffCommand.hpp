#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_CEILING_FAN_OFF_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_CEILING_FAN_OFF_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class CeilingFanOffCommand : public Command {
	private: CeilingFan* ceilingFan;

	public: CeilingFanOffCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
	public: virtual void execute() {
		ceilingFan->off();
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif