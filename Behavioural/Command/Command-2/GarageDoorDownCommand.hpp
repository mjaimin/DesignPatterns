#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_GARAGE_DOOR_DOWN_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_GARAGE_DOOR_DOWN_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class GarageDoorDownCommand : public Command {
	private: GarageDoor* garageDoor;

	public: GarageDoorDownCommand(GarageDoor* garageDoor) {
		this->garageDoor = garageDoor;
	}
	public: virtual void execute() {
		garageDoor->down();
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif