#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_LIVINGROOM_LIGHT_ON_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_LIVINGROOM_LIGHT_ON_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class LivingroomLightOnCommand : public Command {
	private: Light* light;
 
	public:  LivingroomLightOnCommand(Light* light) {
		this->light = light;
	}
	public: virtual void execute() {
		light->on();
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif