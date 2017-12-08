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

#include "Itemset.h"

Itemset::Itemset() : 
	mItems(nullptr), mSizeOfItemset(0), mSupport(0)
{

}

Itemset::Itemset(int *items, int length) :
	mSizeOfItemset(length), mItems(new int[length]), mSupport(0)
{
	int i;
	for (i = 0; i < length; ++i)
	{
		mItems[i] = items[i];
	}
}

Itemset::Itemset(Itemset& another) : 
	mSizeOfItemset(another.mSizeOfItemset), mItems(new int[mSizeOfItemset]), mSupport(another.mSupport)
{
	int i;
	for (i = 0; i < mSizeOfItemset; ++i)
	{
		mItems[i] = another.mItems[i];
	}
}

Itemset::~Itemset()
{
	if (mItems == nullptr)
	{
		delete[] mItems;
	}
}

int Itemset::getSupport() const
{
	return mSupport;
}

string Itemset::getItemset() const
{
	string output = "";
	int i;

	if (mItems == nullptr)
	{
		return " { null } ";
	}

	output += " { " + std::to_string(mItems[0]);

	for (i = 1; i < mSizeOfItemset; i++)
	{
		output += ", " + std::to_string(mItems[i]);
	}

	output += " } ";

	return output;
}

int Itemset::getItemAtIndex(int index)
{
	int result;

	result = mItems[index];

	return result;
}

void Itemset::incrementSupport()
{
	mSupport++;
}

void Itemset::addNewItemsets(Itemset& first, Itemset& second, int newItemsetSize, LinkedList<Itemset>& newItemsets)
{
	Itemset newItemset;
	newItemset.mSizeOfItemset = newItemsetSize;
	newItemset.mItems = new int[newItemset.mSizeOfItemset];

	if (first == second)
	{
		return;
	}

	int comparisonSize = newItemsetSize - 2;

	for (int i = 0; i < comparisonSize; ++i)
	{
		if (first.getItemAtIndex(i) != second.getItemAtIndex(i))
		{
			return;
		}
	}

	for (int i = 0; i < comparisonSize; ++i)
	{
		newItemset.mItems[i] = first.getItemAtIndex(i);
	}

	if (first.getItemAtIndex(comparisonSize) < second.getItemAtIndex(comparisonSize))
	{
		newItemset.mItems[comparisonSize] = first.getItemAtIndex(comparisonSize);
		newItemset.mItems[comparisonSize + 1] = second.getItemAtIndex(comparisonSize);
	}
	else
	{
		newItemset.mItems[comparisonSize] = second.getItemAtIndex(comparisonSize);
		newItemset.mItems[comparisonSize + 1] = first.getItemAtIndex(comparisonSize);
	}

	newItemsets.insert(newItemset);
}

Itemset Itemset::itemToItemset(const int& item)
{
	Itemset newItemset(new int[1]{ item }, 1);
	return newItemset;
}

int Itemset::getSizeOfItemset() const
{
	return mSizeOfItemset;
}


bool Itemset::operator==(Itemset another) const
{
	if (mSizeOfItemset != another.mSizeOfItemset)
	{
		return false;
	}

	for (int i = 0; i < mSizeOfItemset; ++i)
	{
		if (mItems[i] != another.getItemAtIndex(i))
		{
			return false;
		}
	}

	return true;
}

ostream& operator<<(ostream &output, Itemset itemset)
{
	output << itemset.getItemset();
	return output;
}