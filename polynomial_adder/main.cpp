#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>

#include "Term.h"
#include "Polynomial.h"
#include <iostream>
#include <string>


Term extract_term(std::istringstream& input)
{
	/**
	extracts one Term from a stringstream and leaves the stringstream pointing right after that Term
	*/
	
	char next_char;
	int coefficient, exponent, sign_multiplier;
	bool number_was_read;

	input >> std::ws;  // eat up any leading whitespace

	// check for empty
	if (!(input))
		return Term(0, 0);

	// coefficent
	// check for - in case there is no int ("-x")
	next_char = input.peek();

	// set sign multiplier for + or -
	// (this is only necessary because I want to allow whitespace, which isn't required by the assignment)
	if (!isdigit(next_char))
	{
		if (next_char == '-')
		{
			input >> next_char;  // same value, just takes it out of the stream
			input >> std::ws;  // eat up whitespace again
			sign_multiplier = -1;
		}
		else if (next_char == '+')
		{
			input >> next_char;  // same value, just takes it out of the stream
			input >> std::ws;  // eat up whitespace again
			sign_multiplier = 1;
		}
	}

	input >> coefficient;
	coefficient *= sign_multiplier;
	number_was_read = (!input.fail());
	if (!number_was_read)  // coefficient was not read, example: "-x^3"
	{
		if (next_char == '-')
			coefficient = -1;
		else  // not negative, then positive
			coefficient = 1;
	}
	input.clear();  // clear error state

	input >> std::ws;  // eat up whitespace again

	// looking for variable with exponent
	if ((!(input)) && number_was_read)  // if stream is empty, done parsing this term, don't need variable or exponent
		return Term(coefficient, 0);  // example: 5 = 5x^0
	else if ((!(input)) && (!number_was_read))  // string ended with a "-"
		throw std::invalid_argument("invalid polynomial string");
	else  // stream is not empty
	{
		input >> next_char;

		// let user put "*" between coefficient and variable
		if (next_char == '*')
		{
			if (!(input))  // end with "*"
				throw std::invalid_argument("invalid polynomial string");
			input >> std::ws;
			input >> next_char;
			if (!isalpha(next_char))  // coefficient * no variable
				throw std::invalid_argument("invalid polynomial string");
		}
		if ((next_char == '+') || (next_char == '-'))  // this belongs to the next term
		{
			input.putback(next_char);
			return Term(coefficient, 0);
		}
		else if (!isalpha(next_char))  // variable is only valid possibility remaining
			throw std::invalid_argument("invalid polynomial string");
		else // isalpha, is variable
		{
			input >> std::ws;
			input >> next_char;
			if ((next_char == '+') || (next_char == '-'))  // this belongs to the next term
			{
				input.putback(next_char);
				return Term(coefficient, 1);
			}
			input >> std::ws;  // eat up whitespace again
			if (!(input))  // empty, nothing left
				return Term(coefficient, 1);
			if (next_char != '^')  // this is the only valid possibility left
				throw std::invalid_argument("invalid polynomial string");
			// else next_char == '^'
			// now the exponent must come next
			input >> exponent;
			if (!input.good())  // exponent didn't come next
				throw std::invalid_argument("invalid polynomial string");
			input.clear();

			return Term(coefficient, exponent);
		}
	}
}

void test_doug()
{
	Term t(3, 4);
	std::cout << t.exponent << std::endl;

	std::istringstream ss("-x + 5 + x^2 - 10");

	while (ss)
	{
		t = extract_term(ss);
		std::cout << t.coefficient << " " << t.exponent << std::endl;
	}
}

int main()
{
<<<<<<< HEAD
	std::string variable = "I can't figure out how to run this";
	if (variable != "Test")
	{
		std::cout << " Natalie is unsuccessfull in testing." << std::endl;
	}
	else
		std::cout << "Testing is currently working" << std::endl;

=======
	test_doug();  // comment this out and put in your own to test something

	char c;
	std::cin >> c;  // stop the window from closing
>>>>>>> master
	return 0;
}