#include <iostream>
#include <string>
#include <stdexcept>

#include "Menu.h"
#include "Polynomial.h"

void Menu::input_polynomial(const bool& for_p2)
{
	/** gets a Polynomial from std::cin and stores it according to the parameter 
		if it is not for_p2 then it is for p1 */

	Polynomial temp;  // verify input before doing anything with p1 or p2
	std::string input;

	std::cout << "new polynomial: ";
	std::getline(std::cin, input);

	try
	{
		temp.parse(input);

		if (for_p2)
			p2 = temp;
		else  // not for_p2
			p1 = temp;
	}
	catch (std::invalid_argument err)
	{
		std::cout << "invalid polynomial - " << err.what() << std::endl;
	}
}

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

	switch (choice[0])
	{
	case 'q':
	case 'Q':
		return false;
	case '1':
		input_polynomial(0);
		return true;
	case '2':
		input_polynomial(1);
	default:
		return true;
	}
}