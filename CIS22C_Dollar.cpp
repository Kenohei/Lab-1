/****************************************************************************************************
CIS 22C
Lab 1
Author: Laban Tran

****************************************************************************************************/

#include <iostream>
#include <iomanip>
#include "CIS22C_Dollar.h"

CIS22C_Dollar::CIS22C_Dollar() {
	conversion = 1.36;
	/*USDtoC2D_rate = 1.36;
	C2DtoDollar_rate = 0.74;*/
};

CIS22C_Dollar::~CIS22C_Dollar() {

};

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

void CIS22C_Dollar::setConversion(double x) {
	conversion = x;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

double CIS22C_Dollar::getConversion() {
	return conversion;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

CIS22C_Dollar CIS22C_Dollar::operator+(CIS22C_Dollar rhs) {
	CIS22C_Dollar dollarTotal;

	Dollar* base = dynamic_cast<Dollar*>(&rhs);

	int resultInt = this->getCurrencyInt() + base->getCurrencyInt();
	int resultDeci = this->getCurrencyDeci() + base->getCurrencyDeci();

	while (resultDeci >= 1000) {
		resultInt = resultInt + 1;
		resultDeci = resultDeci - 1000;
	}

	dollarTotal.setCurrencyInt(resultInt);
	dollarTotal.setCurrencyDeci(resultDeci);

	return dollarTotal;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

CIS22C_Dollar CIS22C_Dollar::operator-(CIS22C_Dollar rhs) {
	CIS22C_Dollar dollarTotal;

	Dollar* base = dynamic_cast<Dollar*>(&rhs);

	int resultInt = this->getCurrencyInt() - base->getCurrencyInt();
	dollarTotal.setCurrencyInt(resultInt);

	int resultDeci = this->getCurrencyDeci() - base->getCurrencyDeci();
	dollarTotal.setCurrencyDeci(resultDeci);

	return dollarTotal;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

CIS22C_Dollar CIS22C_Dollar::operator<(CIS22C_Dollar rhs) {
	CIS22C_Dollar compareEqual;

	Dollar* base = dynamic_cast<Dollar*>(&rhs);

	if ((this->getCurrencyInt() == base->getCurrencyInt()) && (this->getCurrencyDeci() == base->getCurrencyDeci())) {
		std::cout << "equal" << std::endl;
	}
	else {
		std::cout << "not equal" << std::endl;
	}

	return compareEqual;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

CIS22C_Dollar CIS22C_Dollar::operator>(CIS22C_Dollar rhs) {
	CIS22C_Dollar compareGreater;

	Dollar* base = dynamic_cast<Dollar*>(&rhs);

	if (this->getCurrencyInt() > base->getCurrencyInt()) {
		std::cout << "left is greater" << std::endl;
	}
	else if ((this->getCurrencyInt() == base->getCurrencyInt()) && (this->getCurrencyDeci() > base->getCurrencyDeci())) {
		std::cout << "left is greater" << std::endl;
	}
	else {
		std::cout << "right is greater" << std::endl;
	}

	return compareGreater;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

std::ostream& operator<<(std::ostream& out, const CIS22C_Dollar& c)
{
	out << "$" << c.currencyInt << "." << std::setfill('0') << std::setw(4) << c.currencyDeci << " " << "C2D";
	//out << "$" << c.conversion << std::endl;
	return out;
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

void CIS22C_Dollar::USDtoC2D(Dollar& x) {
	double placeholder = x.getCurrencyInt() + (x.getCurrencyDeci() * .01);
	double result = placeholder * conversion;
	std::cout << result << " C2D";
}

/****************************************************************************************************

Pre:
Post:
Return:
****************************************************************************************************/

void CIS22C_Dollar::C2DtoUSD(CIS22C_Dollar& x) {
	double placeholder = x.getCurrencyInt() + (x.getCurrencyDeci() * .001);
	double result = placeholder * conversion;
	std::cout << result << " USD";
}


//CIS22C_Dollar CIS22C_Dollar::operator=(Dollar rhs) {
//
//}