#ifndef _UTILITY_HPP
#define _UTILITY_HPP

#include <string>

class xbug{
private:
	std::string s;
public:
	xbug(std::string _s){
		s = _s;
	}
	std::string what(){
		return s;
	}
};

#endif
