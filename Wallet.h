/****************************************************************************************************
CIS 22C
Lab 1
Author: Laban Tran

****************************************************************************************************/

#ifndef Wallet_h
#define Wallet_h

#include <iostream>
#include "Dollar.h"
#include "CIS22C_Dollar.h"

// A default Constructor which sets
	// the first element of the array to a zero value Dollar object
	// the second element of the array to a zero value CIS22C Dollar object
// A Destructor, as applicable to your programming language of choice
// Methods to add or subtract
	// USD objects to/from the first element only and
	// C2D objects to/from the second element only
// Methods to compare if the value of either element is greater or smaller than an input value
// A method to Print the values of the two elements in the Wallet

template <typename T>
class Wallet {
	protected:
		//T* dollar_arr = new T;
		//int size;

		Dollar* dollar_arr[2];

	public:
		/*Wallet(T arr[], int s);*/
		Wallet();
		~Wallet();
		/*void add(int x);*/
		/*void add(T t);*/
		/*void print();*/
		void print() const;

};

template <typename T>
Wallet<T>::Wallet() {
	Dollar dollar_arr[0] = new Dollar(0, 0, "USD");
	Dollar dollar_arr[1] = new CIS22C_Dollar(0, 0, "C2D");
};

template <typename T>
Wallet<T>::~Wallet()
{
	delete[] dollar_arr;
};

template <typename T>
void Wallet<T>::print() const {
	std::cout << "Test" << std::endl;
}

//template <typename T>
//void Wallet<T>::add(int x) {
//	Dollar dollar_arr[0] = x;
//}

//template <typename T>
//Wallet<T>::Wallet(T arr[], int s)
//{
//	dollar_arr = new T[s];
//	size = s;
//	for (int i = 0; i < size; i++)
//		dollar_arr[i] = arr[i];
//
//};

//template<typename T>
//void Wallet<T>::add(T t)
//{
//
//	Dollar dollar_arr;
//
//	int wholeNumber = 0;
//	int decNum = 0;
//	wholeNumber += this->getCurrencyInt() + t.getCurrencyInt();
//	decNum += dollar_arr[0].getCurrencyDeci() + t.getCurrencyDeci();
//
//	dollar_arr[0].setCurrencyInt(wholeNumber);
//	dollar_arr[0].setCurrencyDeci(decNum);
//
//	CIS22C_Dollar temp;
//
//	temp.setConversion(dollar_arr[1]);
//
//
//	Dollar* base = dynamic_cast<Dollar*>(&temp);
//
//	Dollar result;
//
//
//
//	temp.getConversion();
//
//	std::cout << "Test" << std::endl;
//	std::cout << dollar_arr[0].getCurrencyInt();
//	return T();
//}

//template <typename T>
//void Wallet<T>::print() {
//	for (int i = 0; i < size; i++)
//		std::cout << " " << *(dollar_arr + i);
//	std::cout << std::endl;
//}

#endif