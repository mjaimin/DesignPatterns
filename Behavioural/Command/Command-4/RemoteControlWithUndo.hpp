#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_CONTROL_WITH_UNDO_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_CONTROL_WITH_UNDO_HPP_

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Undo {

//
// This is the invoker
//
class RemoteControlWithUndo {
	private: Command* onCommands[7];
	private: Command* offCommands[7];
	private: Command* undoCommand;

	public: RemoteControlWithUndo() {
		Command* noCommand = new NoCommand();
		for (int i = 0; i < 7; i++) {
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}
		undoCommand = noCommand;
	}
	public: virtual void setCommand(int slot, Command* onCommand, Command* offCommand) {
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}
	public: virtual void onButtonWasPushed(int slot) {
		onCommands[slot]->execute();
		undoCommand = onCommands[slot];
	}
	public: virtual void offButtonWasPushed(int slot) {
		offCommands[slot]->execute();
		undoCommand = offCommands[slot];
	}
	public: virtual void undoButtonWasPushed() {
		undoCommand->undo();
	}
	public: virtual std::string toString() {
		std::stringstream stringBuff;
		stringBuff << std::endl << "------ Remote Control -------" << std::endl;
		for (int i = 0; i < 7; i++) {
			stringBuff  << "[slot " << i << "] "
						<< typeid(*onCommands[i]).name()
						<< "    "
						<< typeid(*offCommands[i]).name()
						<< std::endl;
		}
		stringBuff << "[undo] " << typeid(*undoCommand).name() << std::endl;
		return stringBuff.str();
	}
};

} // namespace Undo
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif