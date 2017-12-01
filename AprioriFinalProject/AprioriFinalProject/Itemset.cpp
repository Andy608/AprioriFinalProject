#include "Itemset.h"

Itemset::Itemset()
{
	mSizeOfItemset = 0;
	mItems = new int[mSizeOfItemset];
}

Itemset::~Itemset()
{
	delete[] mItems;
}

void Itemset::createItemSet(int *items, int length)
{
	mSizeOfItemset = length;
	items = new int[mSizeOfItemset];
}