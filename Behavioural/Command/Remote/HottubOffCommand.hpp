#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_HOTTUB_OFF_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_HOTTUB_OFF_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class HottubOffCommand : public Command {
	private: Hottub* hottub;

	public: HottubOffCommand(Hottub* hottub) {
		this->hottub = hottub;
	}
	public: virtual void execute() {
		hottub->cool();
		hottub->turnOff();
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif