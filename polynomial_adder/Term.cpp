#include <stdexcept>
#include <cctype>  // isalpha

#include "Term.h"
#include "Alt_iss.h"  // alternate istringstream


Term operator> (Term& exponent, Term& list1) 
{
	Term result = exponent > list1;
	return result; 
} 

Term operator< (Term& exponent, Term& list1)
 {
	 Term result = exponent > list1;
	return result; 
 }
 

//global function
Term extract_term(Alt_iss& input)
{
	/**
	extracts one Term from an istringstream and leaves the istringstream pointing right after that Term
	input should only have + - * ^ digits letters
	throws invalid_argument otherwise
	also throws invalid_argument for empty stream or not .good() stream
	all letters are taken as the same variable (3Y+2r = 3x+2x)
	*/

	char next_char;
	int coefficient, exponent;
	bool number_was_read;

	// check for something left to read in stream
	if (input.empty())
		throw std::invalid_argument("nothing to read in stringstream");
	// verify stream in "good" state
	if (!input.good())
		throw std::invalid_argument("stream not in \"good\" state");

	// coefficent
	// check for '-' in case there is no int ("-x")
	next_char = input.peek();

	input >> coefficient;
	number_was_read = (!input.fail());
	if (!number_was_read)  // coefficient was not read, example: "-x^3"
	{
		if (next_char == '-')
			coefficient = -1;
		else  // not negative, then positive
			coefficient = 1;
		input.clear();  // clear error state

		if (input.empty())  // string ended with a "-" or "+"
			// ("-" or "+" is the only thing I know of that would be
			// taken out of an int read and still give fail)
			throw std::invalid_argument("invalid polynomial string");

		// if there was no number, then there has to be a variable
		if (!isalpha(input.peek()))
			throw std::invalid_argument("invalid polynomial string");
	}

	// looking for variable with exponent
	if (input.empty() && number_was_read)  // if stream is empty, done parsing this term, don't need variable or exponent
		return Term(coefficient, 0);  // example: 5 = 5x^0

	// stream is not empty
	input >> next_char;

	if ((next_char == '+') || (next_char == '-'))  // this belongs to the next term
	{
		input.putback(next_char);
		return Term(coefficient, 0);
	}

	// let user put "*" between coefficient and variable
	if (next_char == '*')
	{
		if (input.empty())  // end with "*"
			throw std::invalid_argument("invalid polynomial string");
		input >> next_char;
	}
	// this must go right after the "*"
	if (!isalpha(next_char))  // variable is only valid possibility remaining
		throw std::invalid_argument("invalid polynomial string");

	// else isalpha, is variable
	if (input.empty())  // empty, nothing left
		return Term(coefficient, 1);

	// something after the variable
	input >> next_char;  // don't care what the variable is, move on
	if ((next_char == '+') || (next_char == '-'))  // this belongs to the next term
	{
		input.putback(next_char);
		return Term(coefficient, 1);
	}

	if (next_char != '^')  // this is the only valid possibility left
		throw std::invalid_argument("invalid polynomial string");
	// else next_char == '^'
	// now the exponent must come next
	input >> exponent;
	if (input.fail())  // exponent didn't come next
		throw std::invalid_argument("invalid polynomial string");

	return Term(coefficient, exponent);
}