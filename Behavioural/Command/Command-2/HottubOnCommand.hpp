#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_HOTTUB_ON_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_HOTTUB_ON_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class HottubOnCommand : public Command {
	private: Hottub* hottub;

	public: HottubOnCommand(Hottub* hottub) {
		this->hottub = hottub;
	}
	public: virtual void execute() {
		hottub->turnOn();
		hottub->heat();
		hottub->bubblesOn();
	}
};

} // namespace Simpleemote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif