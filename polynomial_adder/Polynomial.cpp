#include <string>
#include <sstream>  // only for ostringstream
#include <cctype>  // isspace

#include "Polynomial.h"
#include "Alt_iss.h"

/*inlined function from polynomial.h
std::string str() const { return Polynomial; }  
string that actually print out the list
*/

const Polynomial operator+ (const Polynomial& other)
{ 
	/* we compare and add polynomials?

	add every term or item from the list and create a new list for the final polynomial string. 
	add term will be doing the comparisions for the individual terms based on exponents


	
 compare exp of the first items of each list. 9list are already in order
	 
	 if they match == then add the constants
	 if term1 > term2 then add it to the final_poly_list first
	 if term2 > term1 then add it to the final_poly_list first.



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
		add_term(extract_term(inputss));
	/*
	string representation	.str() function  example: returns string "3x^2" needs to be done
	take the list and put it in a string format


	str terms_of_poly = items in the list
	return (finished polynomial)
	*/
}

void add_term(const Term& term) //taking terms inputed and creating one list
{
/*
/overload > < needs to be done

 while counter != num_items in the list
 compare exp

 if they match == then add the constants
 if term1 > term2 then add it to the p1_list first
 if term2 > term1 then add it to the p1_list first.

 

*/
}  