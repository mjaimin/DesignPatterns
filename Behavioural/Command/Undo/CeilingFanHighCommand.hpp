#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_CEILING_FAN_HIGH_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_CEILING_FAN_HIGH_COMMAND_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

class CeilingFanHighCommand : public Command {
	private: CeilingFan* ceilingFan;
	private: int prevSpeed;
  
	public: CeilingFanHighCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
 	public: virtual void execute() {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->high();
	}
 	public: virtual void undo() {
		if (prevSpeed == CeilingFan::HIGH) {
			ceilingFan->high();
		} else if (prevSpeed == CeilingFan::MEDIUM) {
			ceilingFan->medium();
		} else if (prevSpeed == CeilingFan::LOW) {
			ceilingFan->low();
		} else if (prevSpeed == CeilingFan::OFF) {
			ceilingFan->off();
		}
	}
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif