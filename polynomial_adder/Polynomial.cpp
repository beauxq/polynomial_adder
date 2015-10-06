#include <string>
#include <sstream>  // only for ostringstream
#include <cctype>  // isspace

#include "Polynomial.h"
#include "Alt_iss.h"


std::string Polynomial::str() const
{
	if (the_data.empty())
		return "";

	// else not empty
	std::list<Term>::const_iterator itr = the_data.begin();

	std::string to_return = itr->str();  // the first Term is handled differently because it doesn't need + or - before it
	++itr;
	// now at the second Term
	while (itr != the_data.end())
	{
		if (itr->str()[0] != '-')  // make sure there's + or -
			to_return += '+';

		to_return += itr->str();
		
		++itr;
	}

	return to_return;
}

const Polynomial Polynomial::operator+ (const Polynomial& other) const
{
	// this merge is like merge of "merge sort"
	Polynomial to_return;

	std::list<Term>::const_reverse_iterator itr_this = the_data.rbegin();
	std::list<Term>::const_reverse_iterator itr_other = other.the_data.rbegin();

	// insert the lowest Term in both lists
	// insert_term will always find insertion point at head, so all calls to insert_term in this function are O(1)
	while ((itr_this != the_data.rend()) && (itr_other != other.the_data.rend()))
	{
		if (*itr_this < *itr_other)
		{
			to_return.insert_term(*itr_this);
			++itr_this;
		}
		else  // this >= other
		{
			to_return.insert_term(*itr_other);
			++itr_other;
		}
	}
	// one of the iterators is at the rend
	while (itr_this != the_data.rend())
	{
		to_return.insert_term(*itr_this);
		++itr_this;
	}
	while (itr_other != other.the_data.rend())
	{
		to_return.insert_term(*itr_other);
		++itr_other;
	}

	return to_return;
}

void Polynomial::parse(const std::string& input)
{
	// remove whitespace
	std::ostringstream remove_ws;

	for (std::string::const_iterator itr = input.begin(); itr != input.end(); ++itr)
		if (!isspace(*itr))
			remove_ws << *itr;

	Alt_iss inputss(remove_ws.str());

	// parse one term at a time
	while (!inputss.empty())
		insert_term(extract_term(inputss));
}

void Polynomial::insert_term(const Term& term)
{
	/** this will insert (in order) if the term with matching exponent isn't already there,
		and add to the term if it's already there,
		then it will delete the term from the_data if the coefficient is zero */

	if (term.coefficient == 0)  // adding zero doesn't do anything
		return;
	if (the_data.empty())  // inserting in empty list
		return the_data.push_front(term);

	std::list<Term>::iterator itr = the_data.begin();

	while ((itr != the_data.end()) && (term < *itr))  // short circuit to not dereference end
		++itr;
	// now itr is at the correct insert point
	if (itr == the_data.end())
		return the_data.push_back(term);

 	if (term.exponent == itr->exponent)	// they match == then add the coefficients
	{
		itr->coefficient += term.coefficient;
		if (itr->coefficient == 0)  // don't keep zero coefficients in the list
			the_data.erase(itr);
		return;
	}
	// else exponents not equal - insert term here
	the_data.insert(itr, term);
}
