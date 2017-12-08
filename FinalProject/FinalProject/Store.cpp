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

#include "Store.h"
#include "header.h"

const int Store::BAD_ID = -1;

Store::Store() : 
	mItems(nullptr), mStoreFileName(), mCapacity(0), mNumberOfItems(0)
{

}

Store::~Store()
{
	delete[] mItems;
}

int Store::getNumberOfItems() const
{
	return mNumberOfItems;
}

void Store::setCapacity(int capacity)
{
	mCapacity = capacity;

	if (mItems != nullptr)
	{
		delete[] mItems;
	}

	mItems = new int[mCapacity];
}

string Store::getStoreFileName() const
{
	return mStoreFileName;
}

void Store::setStoreFileName(string storeName)
{
	mStoreFileName = storeName;
}

bool Store::createStore(int& shoppingCartLength)
{
	//Parse file name to get size of list.
	//If file name is empty then return false.
	if (mStoreFileName.empty())
	{
		cout << "File does not exist" << endl;
		return false;
	}

	/*
	The naming convention for the generated dataset is
	Tx.NyK.DzK.dat or (T25.N1K.D100K) where
	- x is the average transaction length
	- y is the number of items (in thousand)
	- z is the number of transaction (in thousand)
	*/
	int startIndex = mStoreFileName.find_first_of("N") + 1;
	int endIndex = mStoreFileName.find_first_of("K");
	double listSize = atof(mStoreFileName.substr(startIndex, endIndex - startIndex).c_str());

	startIndex = mStoreFileName.find_first_of("D") + 1;
	endIndex = mStoreFileName.find_last_of("K");
	double numberOfShoppingCarts = atof(mStoreFileName.substr(startIndex, endIndex - startIndex).c_str());

	shoppingCartLength = static_cast<int>(numberOfShoppingCarts * SIZE_INCREMENT);

	//Set the size of the list.
	setCapacity(static_cast<int>(listSize * SIZE_INCREMENT));

	//Go into the store file.
	ifstream inputStream(mStoreFileName);

	if (inputStream.is_open())
	{

		string line;
		int lineNumber = 0;

		while (getline(inputStream, line))
		{

			stringstream lineStream(line);
			int itemID;

			while (lineStream >> itemID)
			{
				addItemToList(itemID);
			}
		}
	}
	else
	{
		cout << "Input file does not exist." << endl;
		return false;
	}

	inputStream.close();

	//Quick sort list.
	quickSort(mItems, 0, mNumberOfItems - 1);

	return true;
}

void Store::addItemToList(int itemID)
{
	int i;
	for (i = 0; i < mNumberOfItems; ++i)
	{
		if (mItems[i] == itemID)
		{
			return;
		}
	}

	mItems[i] = itemID;
	++mNumberOfItems;
}

const int& Store::getItemByID(const int &itemID) const
{
	int i;
	for (i = 0; i < mNumberOfItems; ++i)
	{
		if (mItems[i] == itemID)
		{
			return itemID;
		}
	}

	return BAD_ID;
}

const int& Store::getItemByIndex(int index) const
{
	return mItems[index];
}