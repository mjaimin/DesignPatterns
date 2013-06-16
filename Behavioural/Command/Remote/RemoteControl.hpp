#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_CONTROL_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_CONTROL_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

//
// This is the invoker
//
class RemoteControl {
	private: Command* onCommands[7];
	private: Command* offCommands[7];

	public: RemoteControl() {
		Command* noCommand = new NoCommand();
		for (int i = 0; i < 7; i++) {
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}
	}
	public: virtual void setCommand(int slot, Command* onCommand, Command* offCommand) {
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}
	public: virtual void onButtonWasPushed(int slot) {
		onCommands[slot]->execute();
	}
	public: virtual void offButtonWasPushed(int slot) {
		offCommands[slot]->execute();
	}
	public: virtual std::string toString() {
		std::stringstream stringBuff;
		stringBuff << "\n------ Remote Control -------\n" << std::endl;
		for (int i = 0; i < 7; i++) {
			stringBuff  << "[slot " << i << "] "
						<< typeid(*onCommands[i]).name()
						<< "    "
						<< typeid(*offCommands[i]).name()
						<< std::endl;
		}
		return stringBuff.str();
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif