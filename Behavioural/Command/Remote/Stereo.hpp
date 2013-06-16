#ifndef	_HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_STEREO_HPP_
#define _HEAD_FIRST_DESIGN_PATTERNS_COMMAND_REMOTE_STEREO_HPP_

#include "Remote.hpp"

namespace HeadFirstDesignPatterns {
namespace Command {
namespace Remote {

class Stereo {
	private: std::string location;
 
	public: Stereo(std::string location) {
		this->location = location;
	}
	public: virtual void on() {
		std::cout << location.c_str() << " stereo is on" << std::endl;
	} 
	public: virtual void off() {
		std::cout << location.c_str() << " stereo is off" << std::endl;
	}
	public: virtual void setCD() {
		std::cout << location.c_str() << " stereo is set for CD input" << std::endl;
	}
 	public: virtual void setDVD() {
		std::cout << location.c_str() << " stereo is set for DVD input" << std::endl;
	}
	public: virtual void setRadio() {
		std::cout << location.c_str() << " stereo is set for Radio" << std::endl;
	}
	public: virtual void setVolume(int volume) {
		// code to set the volume
		// valid range: 1-11 (after all 11 is better than 10, right?)
		std::cout << location.c_str() << " Stereo volume set to " << volume << std::endl;
	}
};

} // namespace Remote
} // namespace Command
} // namespace HeadFirstDesignPatterns

#endif