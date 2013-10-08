#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_COMMAND_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_COMMAND_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

class Command {
	public: virtual void execute() = 0;
	public: virtual void undo() = 0;
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif