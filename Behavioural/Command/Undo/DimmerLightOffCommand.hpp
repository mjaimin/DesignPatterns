#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_DIMMER_LIGHT_OFF_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_DIMMER_LIGHT_OFF_COMMAND_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

class DimmerLightOffCommand : public Command {
	private: Light* light;
	private: int prevLevel;
 
	public:  DimmerLightOffCommand(Light* light) {
		this->light = light;
	}
	public: virtual void execute() {
		prevLevel = light->getLevel();
		light->off();
	}
	public: virtual void undo() {
		light->dim(prevLevel);
	}
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif