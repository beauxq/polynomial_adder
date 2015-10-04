#include <string>
#include <sstream>  // only for ostringstream
#include <cctype>  // isspace

#include "Polynomial.h"
#include "Alt_iss.h"


/*inlined function from polynomial.h
std::string str() const { return Polynomial; }  
string that actually print out the list
*/

const Polynomial Polynomial::operator+ (const Polynomial& other)
{
	/*
	add every term or item from the list and create a new list for the final polynomial
	add term will be doing the comparisions for the individual terms based on exponents
	*/
	std::list<int> final_poly_list();
	std::list<int> poly_list();
	int i = 0;
/*
	while (i < poly_list().size())
	{
		
		if (Term.exponent == Term.exponent)	// they match == then add the constants
		{
		int add_exp = Term.coefficient + Term.coefficien;
		}
		
		if (Term.exponent > Term.exponent)	// term1 > term2 then add it to the final_poly_list first
		{
		final_poly_list<Term>* head = new Node<std::string>(some.exponent);
		}
		if (Term.exponent < Term.exponent)	// term2 > term1 then add it to the final_poly_list first.
		{
		final_poly_list<Term>* head = new Node<std::string>(some1.exponent);
		}
		i++;

		
	}
	*/
		return Polynomial();
	
	
}
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
		insert_term(extract_term(inputss));
	/*
	string representation	.str() function  example: returns string "3x^2" needs to be done
	take the list and put it in a string format


	str terms_of_poly = items in the list
	return (finished polynomial)
	*/
}

void insert_term(const Term& term) //taking terms inputed and creating one list
{
/*
/
 while counter != num_items in the list
{
	compare exp

	 if they match == then add the constants (sample code below)
	 if term1 > term2 then add it to the p1_list first
	 if term2 > term1 then add it to the p1_list first.


 //after you find where the item in the list belongs.
 	if (Term.exponent == itr->exponent)	// they match == then add the constants
		{
			itr->coefficient += term.coefficient;
			if (itr->coefficient == 0)
			{
				//remove the node from the list
			}
			else
				int add_exp = Term.coefficient + Term.coefficien; //add the item into the list
		}
}
*/
}  