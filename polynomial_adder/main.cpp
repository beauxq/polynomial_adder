#include <iostream>
#include <string>

#include "Term.h"
#include "Polynomial.h"
#include "Menu.h"
#include "Alt_iss.h"


void test_doug()
{
	Term t(3, 4);
	std::cout << t.exponent << std::endl;

	Alt_iss ss("5w-5x^-2+10-5y+z^2");
	//Alt_iss ss("++3");  // this one should throw exception
	//Alt_iss ss("-x+5+x^2-10");
	//Alt_iss ss("7*f-2*k^10+18x");

	while (!ss.empty())
	{
		t = extract_term(ss);
		std::cout << t.coefficient << " " << t.exponent << std::endl;
		std::cout << ss.str() << " " << ss.tellg() << std::endl;
	}

	Menu menu;
	while (menu.run());  // empty statement
}

int main()
{
	test_doug();  // if you want to test something, comment this out and put in your own

	char c;
	std::cin >> c;  // stop the window from closing, type a char and press enter
	return 0;
}