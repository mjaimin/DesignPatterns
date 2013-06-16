#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_GARAGE_DOOR_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_GARAGE_DOOR_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class GarageDoor {
	private: std::string location;
 
	public: GarageDoor(std::string location) {
		this->location = location;
	}
 	public: virtual void up() {
		std::cout << location.c_str() << " garage Door is Up" << std::endl;
	} 
	public: virtual void down() {
		std::cout << location.c_str() << " garage Door is Down" << std::endl;
	}
	public: virtual void stop() {
		std::cout << location.c_str() << " garage Door is Stopped" << std::endl;
	}
	public: virtual void lightOn() {
		std::cout << location.c_str() << " garage light is on" << std::endl;
	}
	public: virtual void lightOff() {
		std::cout << location.c_str() << " garage light is off" << std::endl;
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif