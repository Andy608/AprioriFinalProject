#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	mNumberOfTransactions = 0;
	mTransaction = new int[mNumberOfTransactions];
}

ShoppingCart::~ShoppingCart()
{
	delete[] mTransaction;
}

int ShoppingCart::getNumberOfTransactions()
{
	return mNumberOfTransactions;
}

void ShoppingCart::setNumberOfTransactions(int length)
{
	mNumberOfTransactions = length;
	mTransaction = new int[mNumberOfTransactions];
}