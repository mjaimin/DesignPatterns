#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_TV_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_TV_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class TV {
	private: std::string location;
	private: int channel;

	public: TV(std::string location) {
		this->location = location;
	}
	public: virtual void on() {
		std::cout << location.c_str() << " TV is on" << std::endl;
	}
	public: virtual void off() {
		std::cout << location.c_str() << " TV is off" << std::endl;
	}
	public: virtual void setInputChannel() {
		channel = 3;
		std::cout << location.c_str() << " Channel is set for VCR" << std::endl;
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif