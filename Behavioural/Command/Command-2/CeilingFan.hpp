#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_CEILING_FAN_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_CEILING_FAN_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class CeilingFan {
	private: std::string location;
	private: int level;
	public: static const int HIGH = 2;
	public: static const int MEDIUM = 1;
	public: static const int LOW = 0;
 
	public: CeilingFan(std::string location) : level(0) {
		this->location = location;
	}
	public: virtual void high() {
		// turns the ceiling fan on to high
		level = HIGH;
		std::cout << location.c_str() << " ceiling fan is on high" << std::endl;
	} 
	public: virtual void medium() {
		// turns the ceiling fan on to medium
		level = MEDIUM;
		std::cout << location.c_str() << " ceiling fan is on medium" << std::endl;
	}
	public: virtual void low() {
		// turns the ceiling fan on to low
		level = LOW;
		std::cout << location.c_str() << " ceiling fan is on low" << std::endl;
	}
	public: virtual void off() {
		// turns the ceiling fan off
		level = 0;
		std::cout << location.c_str() << " ceiling fan is off" << std::endl;
	}
	public: virtual int getSpeed() {
		return level;
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif