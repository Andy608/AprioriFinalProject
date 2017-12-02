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

int ShoppingCart::getNumberOfTransactions()
{
	return mNumberOfItems;
}

void ShoppingCart::setNumberOfTransactions(int length)
{
	mNumberOfItems = length;
	mTransaction = new int[mNumberOfItems];
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

	if(mTransaction != nullptr)
		delete[] mTransaction;
	
	mTransaction = tempArray;
}