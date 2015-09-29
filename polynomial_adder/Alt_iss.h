#ifndef ALT_ISS_H_INCLUDED
#define ALT_ISS_H_INCLUDED

#include <sstream>
#include <string>

/**
alternate istringstream
inherits from std::istringstream
knows whether there's something left to read in the stream
*/

class Alt_iss : public std::istringstream
{
private:
	const size_t LENGTH;

public:
	// default ctor
	Alt_iss() : std::istringstream(), LENGTH(0) {}
	// string ctor
	Alt_iss(const std::string& str_input) : std::istringstream(str_input), LENGTH(str_input.length()) {}

	bool empty() { return ((tellg() < 0) || (tellg() >= LENGTH)); }
};

#endif  // ALT_ISS_H_INCLUDED