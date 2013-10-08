#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_LIGHT_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_LIGHT_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

class Light {
	private: std::string location;
	private: int level;

	public: Light(std::string location) {
		this->location = location;
	}
	public: virtual void on() {
		level = 100;
		std::cout << location.c_str() << " light is on" << std::endl;
	}
	public: virtual void off() {
		level = 0;
		std::cout << location.c_str() << " light is off" << std::endl;
	}
	public: virtual void dim(int level) {
		this->level = level;
		if (level == 0) {
			off();
		}
		else {
			std::cout << "Light is dimmed to " << level << "%" << std::endl;
		}
	}
	public: virtual int getLevel() {
		return level;
	}
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif