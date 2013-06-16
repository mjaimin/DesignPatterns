#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_UNDO_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

#include "Command.hpp"
#include "NoCommand.hpp"

#include "CeilingFan.hpp"
#include "CeilingFanOffCommand.hpp"
#include "CeilingFanLowCommand.hpp"
#include "CeilingFanMediumCommand.hpp"
#include "CeilingFanHighCommand.hpp"

#include "Light.hpp"
#include "LightOffCommand.hpp"
#include "LightOnCommand.hpp"
#include "DimmerLightOnCommand.hpp"
#include "DimmerLightOffCommand.hpp"

#include "RemoteControlWithUndo.hpp"

#endif