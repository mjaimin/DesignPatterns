#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_LIGHT_ON_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_LIGHT_ON_COMMAND_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

class LightOnCommand : public Command {
	private: Light* light;
 
	public:  LightOnCommand(Light* light) {
		this->light = light;
	}
	public: virtual void execute() {
		light->on();
	}
	public: virtual void undo() {
		light->off();
	}
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif