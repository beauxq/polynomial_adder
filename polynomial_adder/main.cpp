#include <iostream>
#include <string>
#include <sstream>

#include "Term.h"
#include "Polynomial.h"


void test_doug()
{
	Term t(3, 4);
	std::cout << t.exponent << std::endl;

	//std::istringstream ss("5w-5x^-2+10-5y+z^2");
	//std::istringstream ss("++3");  // this one should throw exception
	//std::istringstream ss("-x+5+x^2-10");
	std::istringstream ss("7*f-2*k^10");

	while (ss.tellg() > -1)
	{
		t = extract_term(ss);
		std::cout << t.coefficient << " " << t.exponent << std::endl;
		std::cout << ss.str() << " " << ss.tellg() << std::endl;
	}
}

int main()
{
	test_doug();  // if you want to test something, comment this out and put in your own

	char c;
	std::cin >> c;  // stop the window from closing, type a char and press enter
	return 0;
}