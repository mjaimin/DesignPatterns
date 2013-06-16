#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_CEILING_FAN_ON_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_CEILING_FAN_ON_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class CeilingFanOnCommand : public Command {
	private: CeilingFan* ceilingFan;

	public: CeilingFanOnCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
	public: virtual void execute() {
		ceilingFan->high();
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif