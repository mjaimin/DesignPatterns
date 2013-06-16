#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_HOT_TUB_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_HOT_TUB_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class Hottub {
	private: bool on;
	private: int temperature;

	public: Hottub() : on(false), temperature(0) {
	}
	public: virtual void turnOn() {
		on = true;
	}
	public: virtual void turnOff() {
		on = false;
	}
	public: virtual void bubblesOn() {
		if (on) {
			std::cout << "Hottub is bubbling!" << std::endl;
		}
	}
	public: virtual void bubblesOff() {
		if (on) {
			std::cout << "Hottub is not bubbling" << std::endl;
		}
	}
	public: virtual void jetsOn() {
		if (on) {
			std::cout << "Hottub jets are on" << std::endl;
		}
	}
	public: virtual void jetsOff() {
		if (on) {
			std::cout << "Hottub jets are off" << std::endl;
		}
	}
	public: virtual void setTemperature(int temperature) {
		this->temperature = temperature;
	}
	public: virtual void heat() {
		temperature = 105;
		std::cout << "Hottub is heating to a steaming 105 degrees" << std::endl;
	}
	public: virtual void cool() {
		temperature = 98;
		std::cout << "Hottub is cooling to 98 degrees" << std::endl;
	}

};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif