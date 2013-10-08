#include "Undo.hpp"

using namespace HeadFirstDesignPatterns::Command::Undo;

int main(int argc, char* argv[]) {

	RemoteControlWithUndo* remoteControl = new RemoteControlWithUndo();

	Light* livingRoomLight = new Light("Living Room");

	LightOnCommand* livingRoomLightOn = 
			new LightOnCommand(livingRoomLight);
	LightOffCommand* livingRoomLightOff = 
			new LightOffCommand(livingRoomLight);

	remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);

	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	std::cout << remoteControl->toString() << std::endl;
	remoteControl->undoButtonWasPushed();
	remoteControl->offButtonWasPushed(0);
	remoteControl->onButtonWasPushed(0);
	std::cout << remoteControl->toString() << std::endl;
	remoteControl->undoButtonWasPushed();

	CeilingFan* ceilingFan = new CeilingFan("Living Room");

	CeilingFanMediumCommand* ceilingFanMedium = 
			new CeilingFanMediumCommand(ceilingFan);
	CeilingFanHighCommand* ceilingFanHigh = 
			new CeilingFanHighCommand(ceilingFan);
	CeilingFanOffCommand* ceilingFanOff = 
			new CeilingFanOffCommand(ceilingFan);

	remoteControl->setCommand(0, ceilingFanMedium, ceilingFanOff);
	remoteControl->setCommand(1, ceilingFanHigh, ceilingFanOff);

	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	std::cout << remoteControl->toString() << std::endl;
	remoteControl->undoButtonWasPushed();

	remoteControl->onButtonWasPushed(1);
	std::cout << remoteControl->toString() << std::endl;
	remoteControl->undoButtonWasPushed();

	return 0;
}

