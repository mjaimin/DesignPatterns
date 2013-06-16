#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_LIGHT_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_LIGHT_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class Light {
	private: std::string location;

	public: Light(std::string location) {
		this->location = location;
	}
	public: virtual void on() {
		std::cout << location.c_str() << " light is on" << std::endl;
	}
	public: virtual void off() {
		std::cout << location.c_str() << " light is off" << std::endl;
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif