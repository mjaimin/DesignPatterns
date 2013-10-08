#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_CEILING_FAN_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_CEILING_FAN_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

class CeilingFan {
	public: static const int HIGH = 3;
	public: static const int MEDIUM = 2;
	public: static const int LOW = 1;
	public: static const int OFF = 0;
	private: std::string location;
	private: int speed;
 
	public: CeilingFan(std::string location) {
		this->location = location;
		speed = OFF;
	}
  	public: virtual void high() {
		speed = HIGH;
		std::cout << location.c_str() << " ceiling fan is on high" << std::endl;
	} 
 	public: virtual void medium() {
		speed = MEDIUM;
		std::cout << location.c_str() << " ceiling fan is on medium" << std::endl;
	}
 	public: virtual void low() {
		speed = LOW;
		std::cout << location.c_str() << " ceiling fan is on low" << std::endl;
	}
 	public: virtual void off() {
		speed = OFF;
		std::cout << location.c_str() << " ceiling fan is off" << std::endl;
	}
 	public: virtual int getSpeed() {
		return speed;
	}
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif
