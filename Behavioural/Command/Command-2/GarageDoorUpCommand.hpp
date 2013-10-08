#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_GARAGE_DOOR_UP_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_GARAGE_DOOR_UP_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class GarageDoorUpCommand : public Command {
	private: GarageDoor* garageDoor;

	public: GarageDoorUpCommand(GarageDoor* garageDoor) {
		this->garageDoor = garageDoor;
	}
	public: virtual void execute() {
		garageDoor->up();
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif