#include <iostream>
#include <string>
#include <stdexcept>

#include "Menu.h"
#include "Polynomial.h"

bool Menu::run()
{
	/** returns false for quit, true otherwise */


	std::string choice("x");  // only look at first char of string (in case more than one char entered)
	Polynomial sum = p1 + p2;  // stores the sum of the two polynomials

	std::string menu_display_string = "\n1. change/input polynomial 1   " + p1.str()
									+ "\n2. change/input polynomial 2   " + p2.str()
									+ "\n                          sum: " + sum.str()
									+ "\nQ. quit\n choice? ";

	// valid choice loop
	while ((choice[0] != '1') && (choice[0] != '2') && (choice[0] != 'q') && (choice[0] != 'Q'))
	{
		std::cout << menu_display_string;
		std::getline(std::cin, choice);
	}
	if ((choice[0] == 'q') || (choice[0] == 'Q'))
		return false;

	// 1 or 2
	// input polynomial
	Polynomial temp;  // verify input before doing anything with p1 or p2
	std::string input;

	std::cout << "new polynomial: ";
	std::getline(std::cin, input);
	try
	{
		temp.parse(input);

		if (choice[0] == '1')
			p1 = temp;
		else  // choice[0] == '2'
			p2 = temp;
	}
	catch (std::invalid_argument err)
	{
		std::cout << "invalid polynomial - " << err.what() << std::endl;
	}

	return true;
}