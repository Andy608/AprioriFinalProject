#include "Itemset.h"
using namespace std;

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

/*void Itemset::populateItemSet(int *items, int length)
{
	mSizeOfItemset = length;
	mItems = items;
}*/

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

int Itemset::getSizeOfItemset() const
{
	return mSizeOfItemset;
}
/*
int Itemset::operator[](int itemsetIndex) const
{
	return mItems[itemsetIndex];
}*/

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