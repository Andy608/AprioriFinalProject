/*
Author: Walter Hill, Andrew Rimpici, Kelly Herstine
Class: Data Structures & Algorithims (CSI 281-01)
Assignment: Apriori Final Project
Date Assigned: 11/16/17
Due Date: 12/8/17

Program Description: Final Project - Apriori Program

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment:- Reproduce this assignment and provide a copy to another member of
academic staff; and/or - Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/


#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "ShoppingCart.h"

using namespace std;

class Store
{
private:

	static const int SIZE_INCREMENT = 1000;

	string mStoreFileName;
	int *mItems;
	int mCapacity;
	int mNumberOfItems;

	void setCapacity(int capacity);
	void addItemToList(int itemID);

public:

	static const int BAD_ID;

	Store();
	~Store();

	int getNumberOfItems() const;

	string getStoreFileName() const;
	void setStoreFileName(string storeName);

	bool createStore(int& shoppingCartLength);
	const int& getItemByID(const int &itemID) const;
	const int& getItemByIndex(int index) const;
};

#endif // !STORE_H