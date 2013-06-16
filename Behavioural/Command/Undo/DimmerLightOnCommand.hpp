#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_DIMMER_LIGHT_ON_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_DIMMER_LIGHT_ON_COMMAND_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

class DimmerLightOnCommand : public Command {
	private: Light* light;
	private: int prevLevel;
 
	public:  DimmerLightOnCommand(Light* light) {
		this->light = light;
	}
	public: virtual void execute() {
		prevLevel = light->getLevel();
		light->dim(75);
	}
	public: virtual void undo() {
		light->dim(prevLevel);
	}
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif