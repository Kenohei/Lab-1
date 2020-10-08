/****************************************************************************************************
CIS 22C
Lab 1
Author: Laban Tran

****************************************************************************************************/

#ifndef CIS22C_Dollar_h
#define CIS22C_Dollar_h

#include <iostream>
#include "Dollar.h"

class CIS22C_Dollar : public Dollar {
protected:
	double conversion;
	//double USDtoC2D_rate;
	//double C2DtoDollar_rate;

public:
	CIS22C_Dollar();																// Default Construction
	~CIS22C_Dollar();																// Destructor
	void setConversion(double);
	double getConversion();
	CIS22C_Dollar operator+(CIS22C_Dollar rhs);										// Adding two objects of the same currency
	CIS22C_Dollar operator-(CIS22C_Dollar rhs);										// Subtracting one object from another object of the same currency
	CIS22C_Dollar operator<(CIS22C_Dollar rhs);										// Comparing two objects of the same currency for equality/inequality
	CIS22C_Dollar operator>(CIS22C_Dollar rhs);										// Comparing two objects of the same currency to identify which object is larger or smaller
	friend std::ostream& operator << (std::ostream& out, const CIS22C_Dollar& c);	// Print method to print details of a currency object

	void USDtoC2D(Dollar&);															// In your derived class only, methods to convert USD objects to C2D and vice versa
	void C2DtoUSD(CIS22C_Dollar&);
													
	/*CIS22C_Dollar operator=(Dollar rhs);*/

};

#endif