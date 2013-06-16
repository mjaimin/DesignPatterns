#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_STEREO_ON_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_STEREO_ON_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class StereoOnWithCDCommand : public Command {
	private: Stereo* stereo;
 
	public:  StereoOnWithCDCommand(Stereo* stereo) {
		this->stereo = stereo;
	}
	public: virtual void execute() {
		stereo->on();
		stereo->setCD();
		stereo->setVolume(11);
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif