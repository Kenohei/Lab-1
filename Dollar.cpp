/****************************************************************************************************
CIS 22C
Lab 1
Author: Laban Tran

****************************************************************************************************/

#include <iostream>
#include <iomanip>
#include "Dollar.h"

Dollar::Dollar(int wholeDollar, int fractionDollar) {		// Construction based on parameters for all attributes
	currencyInt = wholeDollar;								// Copy Constructor and/or Assignment, as applicable to your programming language of choice
	currencyDeci = fractionDollar;
};

Dollar::~Dollar() {

};

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

void Dollar::setCurrencyInt(int x) {
	currencyInt = x;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

void Dollar::setCurrencyDeci(int x) {
	currencyDeci = x;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

void Dollar::setCurrencyName(std::string x) {
	currencyName = x;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

int Dollar::getCurrencyInt() {
	return currencyInt;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

int Dollar::getCurrencyDeci() {
	return currencyDeci;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

std::string Dollar::getCurrencyName() {
	return currencyName;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

Dollar Dollar::operator+(Dollar rhs) {
	Dollar dollarTotal;

	dollarTotal.currencyInt = currencyInt + rhs.currencyInt;
	dollarTotal.currencyDeci = currencyDeci + rhs.currencyDeci;

	while (dollarTotal.currencyDeci >= 100) {
		dollarTotal.currencyInt = dollarTotal.currencyInt + 1;
		dollarTotal.currencyDeci = dollarTotal.currencyDeci - 100;
	}

	return dollarTotal;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

Dollar Dollar::operator-(Dollar rhs) {
	Dollar dollarTotal;

	dollarTotal.currencyInt = currencyInt - rhs.currencyInt;
	dollarTotal.currencyDeci = currencyDeci - rhs.currencyDeci;

	return dollarTotal;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

Dollar Dollar::operator<(Dollar rhs) {

	if ((currencyInt == rhs.currencyInt) && (currencyDeci == rhs.currencyDeci)) {
		std::cout << "equal" << std::endl;
	}
	else {
		std::cout << "not equal" << std::endl;
	}

	return 0;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

Dollar Dollar::operator>(Dollar rhs) {

	if (currencyInt > rhs.currencyInt) {
		std::cout << "left is greater" << std::endl;
	}
	else if ((currencyInt == rhs.currencyInt) && (currencyDeci > rhs.currencyDeci)) {
		std::cout << "left is greater" << std::endl;
	}
	else {
		std::cout << "right is greater" << std::endl;
	}

	return 0;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

std::ostream& operator<<(std::ostream& out, const Dollar& c)
{
	out << "$" << c.currencyInt << "." << std::setfill('0') << std::setw(2) << c.currencyDeci << " " << "USD";
	return out;
}

