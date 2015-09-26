#include <string>
#include <sstream>  // only for ostringstream
#include <cctype>  // isspace

#include "Polynomial.h"
#include "Alt_iss.h"

void Polynomial::parse(const std::string& input)
{
	// remove whitespace
	std::ostringstream remove_ws;

	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
		if (!isspace(*it))
			remove_ws << *it;

	Alt_iss inputss(remove_ws.str());

	// parse one term at a time
	while (!inputss.empty())
		add_term(extract_term(inputss));
}