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

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	mTransaction = nullptr;
	mNumberOfItems = 0;
}

ShoppingCart::~ShoppingCart()
{
	delete[] mTransaction;
}

int ShoppingCart::getNumberOfItems()
{
	return mNumberOfItems;
}

void ShoppingCart::addItemToCart(const int& item)
{
	mNumberOfItems++;

	int *tempArray = new int[mNumberOfItems];

	int i, oldSize = mNumberOfItems - 1;
	for (i = 0; i < oldSize; ++i)
	{
		tempArray[i] = mTransaction[i];
	}

	tempArray[mNumberOfItems - 1] = item;

	if (mTransaction != nullptr)
	{
		delete[] mTransaction;
	}
	
	mTransaction = tempArray;
}

const int& ShoppingCart::getItemAtIndex(int index) const
{
	return mTransaction[index];
}