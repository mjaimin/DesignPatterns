#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_NO_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_NO_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class NoCommand : public Command{
	public: virtual void execute() {
	};
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif