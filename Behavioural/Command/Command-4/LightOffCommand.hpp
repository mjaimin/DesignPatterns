#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_LIGHT_OFF_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_LIGHT_OFF_COMMAND_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

class LightOffCommand : public Command {
	private: Light* light;
 
	public:  LightOffCommand(Light* light) {
		this->light = light;
	}
	public: virtual void execute() {
		light->off();
	}
	public: virtual void undo() {
		light->on();
	}
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif