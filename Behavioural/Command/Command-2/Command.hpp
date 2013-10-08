#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_COMMAND_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class Command {
	public: virtual void execute() = 0;
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif