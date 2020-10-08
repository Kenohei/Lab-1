/****************************************************************************************************
CIS 22C
Lab 1
Author: Laban Tran

****************************************************************************************************/

#ifndef Dollar_h
#define Dollar_h

#include <iostream>

class Dollar {
protected:
	int currencyInt;
	int currencyDeci;
	std::string currencyName;

public:
	Dollar(int wholeDollar = 0, int fractionDollar = 0);							// Constructor
	~Dollar();																		// Destructor
	void setCurrencyInt(int);
	void setCurrencyDeci(int);
	void setCurrencyName(std::string);
	int getCurrencyInt();
	int getCurrencyDeci();
	std::string getCurrencyName();
	Dollar operator+(Dollar rhs);													// Adding two objects of the same currency
	Dollar operator-(Dollar rhs);													// Subtracting one object from another object of the same currency
	Dollar operator<(Dollar rhs);													// Comparing two objects of the same currency for equality/inequality
	Dollar operator>(Dollar rhs);													// Comparing two objects of the same currency to identify which object is larger or smaller
	friend std::ostream& operator << (std::ostream& out, const Dollar& c);			// Print method to print details of a currency object
};

#endif