#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_STEREO_OFF_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_SIMPLE_REMOTE_STEREO_OFF_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class StereoOffCommand : public Command {
	private: Stereo* stereo;
 
	public:  StereoOffCommand(Stereo* stereo) {
		this->stereo = stereo;
	}
	public: virtual void execute() {
		stereo->off();
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif