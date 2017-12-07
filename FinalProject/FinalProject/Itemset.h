#ifndef ITEMSET_H
#define ITEMSET_H

#include <string>
#include "LinkedList.h"
using namespace std;

class Itemset
{
private:
	int mSizeOfItemset;
	int *mItems;
	int mSupport;

public:
	Itemset();
	Itemset(Itemset& another);
	Itemset(int *items, int length);
	~Itemset();

	//void populateItemSet(int *items, int length);
	int getSupport() const;
	string getItemset() const;
	void incrementSupport();
	int getSizeOfItemset() const;
	static void addNewItemsets(Itemset& first, Itemset& second, int newItemsetSize, LinkedList<Itemset>& newItemsets);

	//int operator[](int itemsetIndex) const;
	bool operator==(Itemset another) const;
	int getItemAtIndex(int index);

	//int operator[](int itemsetIndex) const;
	friend ostream& operator<<(ostream &output, Itemset itemset);
};


#endif // !ITEMSET_H