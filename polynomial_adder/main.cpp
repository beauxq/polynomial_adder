#include <iostream>
#include <string>

#include "Term.h"
#include "Polynomial.h"
#include "Menu.h"
#include "Alt_iss.h"


void test_doug()
{
	Term t(3, 4);
	std::cout << t.get_exponent() << ' ' << t.str() << std::endl;

	Alt_iss ss("5w-5x^-2+10-5y+z^2");
	//Alt_iss ss("++3");  // this one should throw exception
	//Alt_iss ss("-x+5+x^2-10");
	//Alt_iss ss("7*f-2*k^10+18x");

	while (!ss.empty())
	{
		t = extract_term(ss);
		std::cout << t.str() << std::endl;
		std::cout << ss.str() << ' ' << ss.tellg() << std::endl;
	}

	Menu menu;
	while (menu.run());  // empty statement
}

int main()
{
	Menu menu;
	while (menu.run());  // empty statement

	return 0;
}