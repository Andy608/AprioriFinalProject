#include "Store.h"
#include "header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

const int Store::BAD_ID = -1;

Store::Store() : mItems(nullptr), mStoreFileName(), mCapacity(0), mNumberOfItems(0)
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

bool Store::createItemList()
{
	//Parse file name to get size of list.
	//If file name is empty then return false.
	if (mStoreFileName.empty())
	{
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
	float listSize = atof(mStoreFileName.substr(startIndex, endIndex - startIndex).c_str());

	//Set the size of the list.
	setCapacity(listSize * SIZE_INCREMENT);

	//Go into the store file.
	ifstream inputStream(mStoreFileName);

	if (inputStream.is_open())
	{
		//In a while loop that goes through the whole file.
		//Separate numbers by spaces
		//If a number comes up that is not in the list, append to the list.
		//End when end of file

		string line;
		while (getline(inputStream, line))
		{
			cout << line << endl;

			stringstream lineStream(line);
			int itemID;

			while (lineStream >> itemID)
			{
				addItemToList(itemID);
			}
		}
	}

	inputStream.close();

	for (int i = 0; i < mNumberOfItems; ++i)
	{
		cout << mItems[i] << " ";
	}
	cout << endl << endl;

	//Quick sort list.
	quickSort(mItems, 0, mNumberOfItems - 1);

	for (int i = 0; i < mNumberOfItems; ++i)
	{
		cout << mItems[i] << " ";
	}
	cout << endl;
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